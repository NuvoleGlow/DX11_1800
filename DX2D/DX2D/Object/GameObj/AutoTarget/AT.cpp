#include "framework.h"
#include "AT.h"

AT::AT(string name)
{
	wstring path;
	path.assign(name.begin(), name.end());
	_texture = make_shared<Texture>(path);
}

AT::AT(string name, Vector2 size)
{
	wstring path;
	path.assign(name.begin(), name.end());
	_texture = make_shared<Texture>(path, size);
}

AT::~AT()
{
}

void AT::Update()
{
	_texture->Update();
}

void AT::Render()
{
	_texture->Render();
}

void AT::SetParent(shared_ptr<Transform>& parent)
{
	_texture->SetParent(parent);
}
