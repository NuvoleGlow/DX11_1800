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
	
	_curScene = _scenes["CupHeadScene"];

	_viewBuffer = make_shared<MatrixBuffer>();
	_projectBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0.0f, WIN_WIDTH, 0, WIN_HEIGHT, -1.0f, 1.0f);

	_projectBuffer->SetData(projectionM);

	_viewBuffer->Update();
	_projectBuffer->Update();
}

Program::~Program()
{
}

void Program::Update()
{
	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();

	_curScene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	AlphaBlendState->SetState();

	_curScene->PreRender();

	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);

	_curScene->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
