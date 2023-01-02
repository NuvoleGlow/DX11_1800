#pragma once
class CH_BackGround
{
public:
	CH_BackGround();
	~CH_BackGround();

	void Update();
	void Render();

private:
	shared_ptr<Quad> _mainBg;
	shared_ptr<Quad> _track;
};
