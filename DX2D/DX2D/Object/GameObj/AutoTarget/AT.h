#pragma once
class AT
{
public:
	AT(string name);
	AT(string name, Vector2 size);
	~AT();

	void Update();
	void Render();

	void SetParent(shared_ptr<Transform>& parent);

	shared_ptr<Transform> GetTransform() { return _texture->GetTransform(); }

	Vector2& Getpos() { return _texture->GetTransform()->GetPos(); }
	Vector2& GetScale() { return _texture->GetTransform()->GetScale(); }
	float& GetAngle() { return _texture->GetTransform()->GetAngle(); }

private:
	string _name;
	shared_ptr<Texture> _texture;
};
