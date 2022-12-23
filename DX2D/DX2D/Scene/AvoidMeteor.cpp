#include "framework.h"
#include "AvoidMeteor.h"

AvoidMeteor::AvoidMeteor()
{
	_player = make_shared<Surviver>();

	for (int i = 0; i < 100; i++)
	{
		shared_ptr<Meteor> meteor = make_shared<Meteor>();
		meteor->Init();
		_meteors.push_back(meteor);
	}
}

AvoidMeteor::~AvoidMeteor()
{
}

void AvoidMeteor::Update()
{
	_player->Update();

	for (auto meteor : _meteors)
		meteor->Update();


	for (auto meteor : _meteors)
	{
		if (meteor->IsCollisionWithPlayer(_player))
		{
			meteor->Init();
			--_player->GetHP();
		}
	}

	if (_check > _delay)
	{
		for (auto meteor : _meteors)
		{
			if (meteor->_isActive == false)
			{
				meteor->_isActive = true;
				_check = 0.0f;
				break;
			}
		}
	}

	_check += DELTA_TIME;

	if (_player->GetHP() <= 0)
		_player->_isAlive = false;
}

void AvoidMeteor::Render()
{
	_player->Render();

	for (auto meteor : _meteors)
		meteor->Render();

	int playerHP = _player->GetHP();
	ImGui::SliderInt("HP", &playerHP, 0, 10);
}
