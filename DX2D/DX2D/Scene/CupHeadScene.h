#pragma once

class CH_Player;
class CH_BackGround;
class CH_Boss;

class CupHeadScene : public Scene
{
public:
	CupHeadScene();
	virtual ~CupHeadScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
private:
	shared_ptr<CH_Player> _player;
	shared_ptr<CH_BackGround> _bg;
	shared_ptr<CH_Boss> _boss;
};

