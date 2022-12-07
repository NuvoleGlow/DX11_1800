#pragma once
class SolarScene : public Scene
{
public:
	SolarScene();
	virtual ~SolarScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<MatrixBuffer> _worldBuffer;
	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectBuffer;

	XMFLOAT2 _worldPos = { 0,0 };
	XMFLOAT2 _cameraPos = { 0,0 };

	float _cameraAngle = 0.0f;

	shared_ptr<Texture> _sun;
	shared_ptr<Texture> _earth;
	shared_ptr<Texture> _moon;
};
