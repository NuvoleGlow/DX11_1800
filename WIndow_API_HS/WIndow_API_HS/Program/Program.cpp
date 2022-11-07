#include "framework.h"
#include "Program.h"

#include "../Scene/PaintScene.h"
#include "../Scene/FortressScene.h"
#include "../Scene/LineScene.h"
#include "../Scene/LineScene2.h"
#include "../Scene/Arkanoid.h"
#include "../Scene/MazeScene.h"

HDC Program::_backBuffer = nullptr;

Program::Program()
{
	HDC hdc = GetDC(hWnd);

	_backBuffer = CreateCompatibleDC(hdc);
	_hBit = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(_backBuffer, _hBit);

	ReleaseDC(hWnd, hdc);

	_scenes["PaintScene"] = make_shared<PaintScene>();
	_scenes["FortressScene"] = make_shared<FortressScene>();
	_scenes["LineScene"] = make_shared<LineScene>();
	_scenes["LineScene2"] = make_shared<LineScene2>();
	_scenes["Arkanoid"] = make_shared<Arkanoid>();
	_scenes["MazeScene"] = make_shared<MazeScene>();

	_targetScene = _scenes["Arkanoid"];
}

Program::~Program()
{
	_targetScene = nullptr;

	DeleteObject(_hBit);
	DeleteObject(_backBuffer);
}

void Program::Update()
{
	_targetScene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(_backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);

	_targetScene->Render(_backBuffer);

	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, _backBuffer, 0, 0, SRCCOPY);
}