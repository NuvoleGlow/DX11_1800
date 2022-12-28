#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"Texture/alpabet.png", Vector2(8, 5), Vector2(100, 100));
	_sprite->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
	
	CreateAction();
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_sprite->Update();
	_action->Update();
}

void SpriteScene::Render()
{
	AdditiveBlendState->SetState();
	_sprite->Render();
	_sprite->SetSprite(_action->GetCurClip());
}

void SpriteScene::PostRender()
{
	ImGui::SliderInt("FrameX", &_frameX, 0, 7);
	ImGui::SliderInt("FrameY", &_frameY, 0, 4);
	ImGui::SliderInt("LeftRight", &_leftRight, 0, 1);
	_sprite->SetLeftRight(_leftRight);
}

void SpriteScene::CreateAction()
{
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(L"Texture/alpabet.png");
	vector<Action::Clip> clips;
	Vector2 imageSize = srv->GetSize();
	Vector2 maxFrame = { 8,5 };
	float w = imageSize.x / maxFrame.x;
	float h = imageSize.y / maxFrame.y;

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			Action::Clip clip = Action::Clip(x * w, y * h, w, h, srv);
			clips.push_back(clip);
		}
	}

	_action = make_shared<Action>(clips, "alpabet");
	_action->Play();
}
