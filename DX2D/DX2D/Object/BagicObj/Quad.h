#pragma once
class Quad
{
public:
	Quad(wstring file);
	Quad(wstring file, Vector2 size);
	virtual ~Quad();

	virtual void Update();
	virtual void Render();

	Vector2 GetSize() { return _size; }

	void SetLeftRight(int leftRight);

	shared_ptr<Transform> GetTransform() { return _transform; }

protected:
	void CreateVertricesAndIndices();

	vector<Vertex_UV> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	Vector2 _size = { 1.0f,1.0f };
	shared_ptr<Transform> _transform;

	shared_ptr<SRV> _srv;

	shared_ptr<LeftRightBuffer> _leftRightBuffer;
};
