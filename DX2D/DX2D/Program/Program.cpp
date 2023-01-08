#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/SolarScene.h"
#include "../Scene/GunGreed.h"
#include "../Scene/CollisionScene.h"
#include "../Scene/AvoidMeteor.h"
#include "../Scene/FortressScene.h"
#include "../Scene/SpriteScene.h"
#include "../Scene/CupHeadScene.h"
#include "../Scene/FilterScene.h"
#include "../Scene/EffectScene.h"

Program::Program()
{
	// _scenes["TextureScene"] = make_shared<TextureScene>();
	// _scenes["SolarScene"] = make_shared<SolarScene>();
	// _scenes["GunGreed"] = make_shared<GunGreed>();
	// _scenes["Collision"] = make_shared<CollisionScene>();
	// _scenes["AvoidMeteor"] = make_shared<AvoidMeteor>();
	// _scenes["FortressScene"] = make_shared<FortressScene>();
	// _scenes["SpriteScene"] = make_shared<SpriteScene>();
	 _scenes["CupHeadScene"] = make_shared<CupHeadScene>();
	// _scenes["FilterScene"] = make_shared<FilterScene>();
	// _scenes["EffectScene"] = make_shared<EffectScene>();
	
	_curScene = _scenes["CupHeadScene"];
}

Program::~Program()
{
}

void Program::Update()
{
	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();

	_curScene->Update();

	Camera::GetInstance()->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Camera::GetInstance()->SetProjectionBuffer(WIN_WIDTH, WIN_HEIGHT);
	Camera::GetInstance()->SetCameraWorldBuffer();

	_curScene->PreRender();

	Camera::GetInstance()->SetViewPort();

	AlphaBlendState->SetState();

	_curScene->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	Camera::GetInstance()->PostRender();
	_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
