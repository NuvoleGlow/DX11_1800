#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _brushes[0] = CreateSolidBrush(RED); // »¡°­
    _brushes[1] = CreateSolidBrush(GREEN); // ÃÊ·Ï
    _brushes[2] = CreateSolidBrush(BLUE); // ÆÄ¶û

    _pens[0] = CreatePen(0, 3, RED);
    _pens[1] = CreatePen(0, 3, GREEN);
    _pens[2] = CreatePen(0, 3, BLUE);

    _rect = make_shared<RectCollider>(Vector2((float)225, (float)225), Vector2((float)150, (float)150));

    _elli = make_shared<ElliCollider>(Vector2(400, 400), Vector2(150, 150));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
    _rect->GetCenter()._x += 0.5f;
    _elli->GetCenter()._x_int += 1;
    _elli->GetCenter()._y_int += 1;
}

void PaintScene::Render(HDC hdc)
{ 
    SelectObject(hdc, _pens[2]);
    SelectObject(hdc, _brushes[2]);

    MoveToEx(hdc, 150, 150, NULL);
    LineTo(hdc, mousePosX, mousePosY);

    SelectObject(hdc, _pens[2]);
    SelectObject(hdc, _brushes[1]);
    _rect->Render(hdc);

    SelectObject(hdc, _pens[2]);
    SelectObject(hdc, _brushes[0]);
    _elli->Render(hdc);
}
