#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_quad = make_shared<Quad>(L"1.png");

}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	if (KEY_PRESS(0x41))
	{
		_quad->GetTransform()->GetPos().x -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x44))
	{
		_quad->GetTransform()->GetPos().x += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x57))
	{
		_quad->GetTransform()->GetPos().y += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x53))
	{
		_quad->GetTransform()->GetPos().y -= 0.5f * DELTA_TIME * 100;
	}

	_quad->Update();
}

void TextureScene::Render()
{
	_quad->Render();
}
