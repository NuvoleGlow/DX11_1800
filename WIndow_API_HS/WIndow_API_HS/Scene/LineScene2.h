#pragma once
class LineScene2 : public Scene
{
public:
	LineScene2();
	virtual ~LineScene2();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Line> _line1; // X축에 대한 line2의 그림자
	shared_ptr<Line> _line2; // 움직이는 선
	shared_ptr<Line> _line3; // Y축에 대한 line2의 그림자
};