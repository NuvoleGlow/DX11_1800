#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/SolarScene.h"


Program::Program()
{
	_scenes["TextureScene"] = make_shared<TextureScene>();
	_scenes["SolarScene"] = make_shared<SolarScene>();
	_curScene = _scenes["SolarScene"];
}

Program::~Program()
{
}

void Program::Update()
{
	_curScene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	_curScene->Render();

	Device::GetInstance()->Present();
}
