#include "framework.h"

#include "Object/GameObj/CupHead/CH_Player.h"
#include "Object/GameObj/CupHead/CH_BackGround.h"

#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<CH_Player>();
	_bg = make_shared<CH_BackGround>();
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();
}

void CupHeadScene::PreRender()
{
	_bg->Render();
}

void CupHeadScene::Render()
{
	_player->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
