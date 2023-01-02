#include "framework.h"

#include "CH_Bullet.h"

#include "CH_Player.h"

CH_Player::CH_Player()
{
	_transform = make_shared<Transform>();
	_collider = make_shared<CircleCollider>(30);
	_collider->GetTransform()->SetParent(_transform);
	CreateAction("Idle");
	CreateAction("Run");

	{
		CreateAction("AimStraightShot");
	}

	_actions[State::IDLE]->SetSpeed(0.1f);
	_actions[State::RUN]->SetSpeed(0.07f);

	_transform->GetPos() = { CENTER_X, CENTER_Y - 200 };

	_bullet = make_shared<CH_Bullet>();
}

CH_Player::~CH_Player()
{
}

void CH_Player::Input()
{
	SetState();


	if (KEY_PRESS('A'))
	{
		_transform->GetPos().x -= DELTA_TIME * _speed;
		_state = State::RUN;
		_sprites[_state]->SetLeft();
		_stateNum = 1;
	}
	if (KEY_PRESS('D'))
	{
		_transform->GetPos().x += DELTA_TIME * _speed;
		_state = State::RUN;
		_sprites[_state]->SetRight();
		_stateNum = 0;
	}
	if (KEY_PRESS(VK_SPACE))
	{
		_state = State::SHOT;
		if (_stateNum == 0)
		{
			_sprites[_state]->SetRight();
		}
		if (_stateNum == 1)
		{
			_sprites[_state]->SetLeft();
		}
	}
}

void CH_Player::Update()
{
	Input();

	_transform->Update();
	_collider->Update();
	_actions[_state]->Update();
	_sprites[_state]->Update();
}

void CH_Player::Render()
{
	_transform->SetWorldBuffer();
	_sprites[_state]->SetSpriteAction(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();
	_collider->Render();
}

void CH_Player::PostRender()
{
}

void CH_Player::CreateAction(string state)
{
	wstring srvPath;
	srvPath.assign(state.begin(), state.end());
	srvPath = L"CupHead/" + srvPath + L".png";
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(srvPath);
	vector<Action::Clip> clips;

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string xmlPath = "Resource/Texture/CupHead/" + state + ".xml";
	document->LoadFile(xmlPath.c_str());

	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = textureAtlas->FirstChildElement();

	int averageW = 0;
	int averageH = 0;
	int count = 0;

	while (true)
	{
		if (row == nullptr)
			break;
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		averageW += w;
		int h = row->FindAttribute("h")->IntValue();
		averageH += h;

		count++;

		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	shared_ptr<Sprite> sprite;
	averageW /= count * 1.5f;
	averageH /= count * 1.5f;

	sprite = make_shared<Sprite>(srvPath, Vector2(averageW, averageH));
	sprite->GetTransform()->SetParent(_transform);

	_sprites.push_back(sprite);
	shared_ptr<Action> action = make_shared<Action>(clips, state, Action::LOOP, 0.1f);
	action->Play();
	_actions.push_back(action);
}

void CH_Player::SetState()
{
	_state = State::IDLE();
	if (_stateNum == 0)
	{
		_sprites[_state]->SetRight();
	}
	if (_stateNum == 1)
	{
		_sprites[_state]->SetLeft();
	}
}
