#include "framework.h"
#include "CH_Player.h"

CH_Player::CH_Player()
{
	_transform = make_shared<Transform>();
	_collider = make_shared<CircleCollider>(30);
	_collider->GetTransform()->SetParent(_transform);
	CreateAction("Idle");
	CreateAction("Run");

	_transform->GetPos() = { CENTER_X, CENTER_Y };
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
		_sprites[_state]->SetLeftRight(1);
		_stateNum = 1;
	}
	if (KEY_PRESS('D'))
	{
		_transform->GetPos().x += DELTA_TIME * _speed;
		_state = State::RUN;
		_sprites[_state]->SetLeftRight(0);
		_stateNum = 0;
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

	while (true)
	{
		if (row == nullptr)
			break;
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();
		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	shared_ptr<Sprite> sprite;
	if (state == "Run")
	{
		sprite = make_shared<Sprite>(srvPath, Vector2(2, 8), Vector2(65, 75));
	}
	else
		sprite = make_shared<Sprite>(srvPath, Vector2(2, 8), Vector2(150, 150));

	sprite->GetTransform()->SetParent(_transform);
	_sprites.push_back(sprite);
	shared_ptr<Action> action = make_shared<Action>(clips, state, Action::LOOP, 0.1f);
	action->Play();
	_actions.push_back(action);
}

void CH_Player::SetState()
{
	_state = State::IDLE();
	_sprites[_state]->SetLeftRight(_stateNum);
}
