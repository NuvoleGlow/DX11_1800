#include "framework.h"

#include "Object/GameObj/CupHead/CH_Player.h"

#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<CH_Player>();
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();
}

void CupHeadScene::Render()
{
	_player->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
