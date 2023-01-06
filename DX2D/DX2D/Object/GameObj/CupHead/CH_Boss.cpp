#include "framework.h"

#include "CH_Bullet.h"

#include "CH_Boss.h"

CH_Boss::CH_Boss()
{
	_transform = make_shared<Transform>();
	_collider = make_shared<CircleCollider>(100);
	_collider->GetTransform()->SetParent(_transform);
	CreateAction("Boss/Clown_Intro_Idle");

	_transform->GetPos() = { CENTER_X + 500 , CENTER_Y - 100 };

}

CH_Boss::~CH_Boss()
{
}


void CH_Boss::Update()
{
	if (_hp <= 0)
	{
		_collider->_isActive = false;
		return;
	}

	_transform->Update();
	_collider->Update();
	_action->Update();
	_sprite->Update();

}

void CH_Boss::Render()
{
	if (_hp <= 0)
		return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();
	_collider->Render();
}

void CH_Boss::PostRender()
{
	ImGui::SliderInt(" : HP", (int*)&_hp, 0, 1000);
}

void CH_Boss::CreateAction(string state)
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

	_sprite = make_shared<Sprite>(srvPath, Vector2(averageW, averageH));
	_sprite->GetTransform()->SetParent(_transform);

	_action = make_shared<Action>(clips, state, Action::LOOP, 0.1f);
	_action->Play();
}

void CH_Boss::SetLeft()
{
	_sprite->SetLeft();
}

void CH_Boss::SetRight()
{
	_sprite->SetRight();
}

void CH_Boss::Dammaged(shared_ptr<CH_Bullet> bullet)
{
	if (bullet->isActive == true)
	{
		if (_collider->IsCollision(bullet->GetCollider()))
		{
			_hp -= bullet->atk;
			bullet->isActive = false;
		}
	}
}
