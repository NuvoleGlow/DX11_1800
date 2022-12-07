#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <wrl/client.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

using namespace std;
using namespace DirectX;

// DirectX Tex
#include "../DirectXTex/DirectXTex.h"

#include "Types.h"

// Math
#include "Framework/Math/Vector2.h"

// Device
#include "Framework/Device/Device.h"

// Render
#include "Framework/Render/VertexLayOut.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"

// Texture
#include "Framework/Texture/SRV.h"
#include "Framework/Texture/SamplerState.h"

// Object
#include "Object/Texture.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"
