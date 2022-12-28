#include "framework.h"

#include "../AvoidMeteor/Surviver.h"

#include "Meteor.h"

Meteor::Meteor()
{
	_quad = make_shared<Quad>(L"Texture/Bullet.png", Vector2(130, 130));

	_quad->GetTransform()->GetAngle() = PI * 1.5f;

	_circleCollider = make_shared<CircleCollider>(5);
	_circleCollider->GetTransform()->SetParent(_quad->GetTransform());
	_circleCollider->GetTransform()->GetPos().x += 60;
}

Meteor::~Meteor()
{
}

void Meteor::Update()
{
	if (_isActive == false)
		return;

	if (_quad->GetTransform()->GetPos().y < 0)
	{
		Init();
		return;
	}

	_quad->GetTransform()->GetPos().y -= _speed * DELTA_TIME;

	_quad->Update();
	_circleCollider->Update();
}

void Meteor::Render()
{
	_quad->Render();
}

void Meteor::Init()
{
	_quad->GetTransform()->GetPos().x = 400 + rand() % 480;
	_quad->GetTransform()->GetPos().y = WIN_HEIGHT + 50;
	_isActive = false;
}

bool Meteor::IsCollisionWithPlayer(shared_ptr<Surviver> player)
{
	if (_isActive == false || player->_isAlive == false)
		return false;

	return _circleCollider->IsCollision(player->GetCollider());
}
