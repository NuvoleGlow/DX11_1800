#pragma once
class FortressScene : public Scene
{
public:
	FortressScene();
	virtual ~FortressScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Canon> _canon;
};