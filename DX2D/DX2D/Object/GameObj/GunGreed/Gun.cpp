#include "framework.h"
#include "Gun.h"

Gun::Gun()
{
	_quad = make_shared<Quad>(L"Texture/railgun.png", Vector2(200, 100));

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<class Bullet> _bullet = make_shared<Bullet>();
		_bullets.push_back(_bullet);
	}
}

Gun::~Gun()
{
}

void Gun::Update()
{
	_quad->Update();
	for (int i = 0; i < 10; i++)
	{
		_bullets[i]->Update();
	}
}

void Gun::Render()
{
	_quad->Render();
	for (int i = 0; i < 10; i++)
	{
		_bullets[i]->Render();
	}
}

void Gun::FireBullet(const Vector2& mousePos)
{
	for (int i = 0; i < 10; i++)
	{
		if (_bullets[i]->_inControl == false)
		{
			continue;
		}
		else
		{
			Vector2 dir = mousePos - _quad->GetTransform()->GetWorldPos();

			_bullets[i]->_isActive = true;
			_bullets[i]->GetTransform()->GetPos() = _quad->GetTransform()->GetWorldPos();
			_bullets[i]->SetDir(dir);
			break;
		}
	}
}
