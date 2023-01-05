#pragma once
class CH_BackGround
{
public:
	CH_BackGround();
	~CH_BackGround();

	void Update();
	void Render();

	Vector2 GetSize() { return _mainBg->GetSize(); }
	Vector2 GetMainPos() { return _mainBg->GetTransform()->GetWorldPos(); }
private:
	shared_ptr<Quad> _mainBg;
	shared_ptr<Quad> _track;
};
