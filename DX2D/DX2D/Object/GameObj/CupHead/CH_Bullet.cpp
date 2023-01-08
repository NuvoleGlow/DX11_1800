#include "framework.h"
#include "CH_Bullet.h"

CH_Bullet::CH_Bullet()
{
	CreateAction("Bullet/Bullet_Loop");
	_collider = make_shared<CircleCollider>(5);
	_collider->GetTransform()->SetParent(_sprite->GetTransform());

	_collider->GetTransform()->GetPos().y += 45.0f;
}

CH_Bullet::~CH_Bullet()
{
}

void CH_Bullet::Update()
{
	if (_sprite->GetTransform()->GetWorldPos().x >= WIN_WIDTH || _sprite->GetTransform()->GetWorldPos().x <= 0)
		isActive = false;

	if (!isActive) return;

	_sprite->GetTransform()->GetPos() += _dir * _speed * DELTA_TIME;

	_collider->Update();

	_action->Update();
	_sprite->Update();
}

void CH_Bullet::Render()
{
	if (isActive == false)
		return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();
	_collider->Render();
}

void CH_Bullet::CreateAction(string state)
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

	averageW /= count * 1.5f;
	averageH /= count * 1.5f;

	_sprite = make_shared<Sprite>(srvPath, Vector2(averageW, averageH));

	_action = make_shared<Action>(clips, state, Action::LOOP, 0.1f);
	_action->Play();
}

void CH_Bullet::SetDirection(Vector2 dir)
{
	float angle = dir.Angle();
	_dir = dir;
	_sprite->GetTransform()->GetAngle() = angle - PI * 0.5f;
}
