#pragma once

class Ft_Bullet;
class Ft_Turret;

class FortressScene : public Scene
{
public:
	FortressScene();
	virtual ~FortressScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Ft_Turret> _turret;
	shared_ptr<Collider> _target;
};

