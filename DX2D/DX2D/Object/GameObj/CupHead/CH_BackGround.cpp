#include "framework.h"
#include "CH_BackGround.h"

CH_BackGround::CH_BackGround()
{
	wstring path = L"CupHead/BackGround/";
	_mainBg = make_shared<Quad>(path + L"clown_bg_main.png");
	_mainBg->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };

	_track = make_shared<Quad>(path + L"clown_bg_track.png");
	_track->GetTransform()->GetPos() = { CENTER_X, CENTER_Y - 300 };

	_mainBg->Update();
	_track->Update();
}

CH_BackGround::~CH_BackGround()
{
}

void CH_BackGround::Update()
{
}

void CH_BackGround::Render()
{
	_mainBg->Render();
	_track->Render();
}
