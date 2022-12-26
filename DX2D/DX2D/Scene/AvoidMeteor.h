#pragma once

class Surviver;
class Meteor;

class AvoidMeteor : public Scene
{
public:
	AvoidMeteor();
	virtual ~AvoidMeteor();

	virtual void Update() override;
	virtual void Render() override;

private:
	float _check = 0.0f;
	float _delay = 0.5f;

	shared_ptr<Surviver> _player;
	vector<shared_ptr<Meteor>> _meteors;
};