#pragma once
class TextureScene : public Scene
{
public:
	TextureScene();
	virtual ~TextureScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<MatrixBuffer> _worldBuffer;
	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectBuffer;

	XMFLOAT2 _worldPos = { 0,0 };
	XMFLOAT2 _cameraPos = { 0,0 };

	float _cameraAngle = 0.0f;

	shared_ptr<Texture> _texture;
};
