#include "framework.h"

#include "../AvoidMeteor/Meteor.h"

#include "Surviver.h"

Surviver::Surviver()
{
	_quad = make_shared<Quad>(L"Texture/1.png", Vector2(50, 100));

	_rectCol = make_shared<RectCollider>(Vector2(50, 100));
	_rectCol->GetTransform()->SetParent(_quad->GetTransform());

	_quad->GetTransform()->GetPos() = Vector2(CENTER_X, CENTER_Y - 300);
}

Surviver::~Surviver()
{
}

void Surviver::Update()
{
	if (_isAlive == false)
		return;
	Input();

	_quad->Update();
	_rectCol->Update();
}

void Surviver::Render()
{
	if (_isAlive == false)
		return;
	_quad->Render();
	_rectCol->Render();
}

void Surviver::Input()
{
	if (KEY_PRESS('A'))
	{
		_quad->GetTransform()->GetPos().x -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('D'))
	{
		_quad->GetTransform()->GetPos().x += _speed * DELTA_TIME;
	}
}
