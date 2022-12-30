#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"CupHead/Idle.png", Vector2(5, 1), Vector2(250, 250));
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
}

void SpriteScene::PostRender()
{
	ImGui::SliderInt("LeftRight", &_leftRight, 0, 1);
	_sprite->SetLeftRight(_leftRight);
}

void SpriteScene::CreateAction()
{
}
