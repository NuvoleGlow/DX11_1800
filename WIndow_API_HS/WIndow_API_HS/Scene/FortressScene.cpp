#include "framework.h"
#include "FortressScene.h"

FortressScene::FortressScene()
{
	_canon = make_shared<Canon>();
}

FortressScene::~FortressScene()
{
}

void FortressScene::Update()
{
	_canon->Update();

	if (GetAsyncKeyState(VK_LEFT))
		_canon->MoveLeft();
	if (GetAsyncKeyState(VK_RIGHT))
		_canon->MoveRight();
	if (GetAsyncKeyState(VK_UP))
		_canon->GetAngle() -= 0.01f;
	if (GetAsyncKeyState(VK_DOWN))
		_canon->GetAngle() += 0.01f;

	if (GetAsyncKeyState(VK_SPACE))
		_canon->Shoot();
		
}

void FortressScene::Render(HDC hdc)
{
	_canon->Render(hdc);
}