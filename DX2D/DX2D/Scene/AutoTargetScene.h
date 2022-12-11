#pragma once
class AutoTargetScene : public Scene
{
public:
	AutoTargetScene();
	virtual ~AutoTargetScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<AT> _texture;
	shared_ptr<AT> _drone;

	shared_ptr<Transform> _2Trans;
};
