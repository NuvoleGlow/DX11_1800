#include "framework.h"
#include "Program.h"

#include "../Scene/PaintScene.h"
#include "../Scene/FortressScene.h"
#include "../Scene/LineScene.h"

Program::Program()
{
	_scenes["PaintScene"] = make_shared<PaintScene>();
	_scenes["FortrissScene"] = make_shared<FortressScene>();
	_scenes["LineScene"] = make_shared<LineScene>();

	_targetScene = _scenes["FortrissScene"];
}

Program::~Program()
{
	_targetScene = nullptr;
}

void Program::Update()
{
	_targetScene->Update();
}

void Program::Render(HDC hdc)
{
	_targetScene->Render(hdc);
}
