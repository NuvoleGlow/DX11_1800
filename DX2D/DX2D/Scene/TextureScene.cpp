#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_texture = make_shared<Texture>(L"Texture/1.png");

	_worldBuffer = make_shared<MatrixBuffer>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectBuffer->SetData(projectionM);

	_worldBuffer->Update();
	_viewBuffer->Update();
	_projectBuffer->Update();
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	XMMATRIX worldS = XMMatrixScaling(1, 1, 1);
	XMMATRIX worldR = XMMatrixRotationZ(0);
	XMMATRIX worldT = XMMatrixTranslation(_worldPos.x, _worldPos.y, 0);
	XMMATRIX worldSRT = worldS * worldR * worldT;
	_worldBuffer->SetData(worldSRT);
	_worldBuffer->Update();

	XMMATRIX viewS = XMMatrixScaling(1, 1, 1);
	XMMATRIX viewR = XMMatrixRotationZ(_cameraAngle);
	XMMATRIX viewT = XMMatrixTranslation(_cameraPos.x, _cameraPos.y, 0);
	XMMATRIX viewSRT = viewS * viewR * viewT;
	_viewBuffer->SetData(viewSRT);
	_viewBuffer->Update();

	_texture->Update();
}

void TextureScene::Render()
{
	_worldBuffer->SetVSBuffer(0);
	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);

	_texture->Render();
}
