#include "framework.h"

#include "Object/GameObj/CupHead/CH_Player.h"
#include "Object/GameObj/CupHead/CH_BackGround.h"
#include "Object/GameObj/CupHead/CH_Boss.h"

#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<CH_Player>();
	_bg = make_shared<CH_BackGround>();
	_boss = make_shared<CH_Boss>();

	Camera::GetInstance()->SetTarget(_player->GetTransform());
	Camera::GetInstance()->SetOffSet({ CENTER_X, 160 });
	Camera::GetInstance()->SetLeftBottom(_bg->GetSize() * 0.5f * -1.0f + _bg->GetMainPos());
	Camera::GetInstance()->SetRightTop(_bg->GetSize() * 0.5f + _bg->GetMainPos());
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		Camera::GetInstance()->ShakeStart(3.0f, 0.3f);
	}

	for (auto bullet : _player->GetBullets())
	{
		_boss->Dammaged(bullet);
	}

	_player->Update();
	_boss->Update();
}

void CupHeadScene::PreRender()
{
	_bg->Render();
}

void CupHeadScene::Render()
{
	_player->Render();
	_boss->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
	_boss->PostRender();
}
