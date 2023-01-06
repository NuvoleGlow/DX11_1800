#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>
#include <cmath>
#include <memory>
#include <time.h>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <wrl/client.h>
#include <functional>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

using namespace std;
using namespace DirectX;

// DirectX Tex
#include "../DirectXTex/DirectXTex.h"

// ImGUI
#include "../ImGUI/imgui.h"
#include "../ImGUI/imgui_impl_win32.h"
#include "../ImGUI/imgui_impl_dx11.h"

#include "Types.h"

// Device
#include "Framework/Device/Device.h"

// Utility
#include "Framework/Utility/Timer.h"
#include "Framework/Utility/Keyboard.h"
#include "Framework/Utility/tinyxml2.h"

// Render
#include "Framework/Render/VertexLayOut.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/Shader.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework/Render/ShaderManager.h"
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"

// Math
#include "Framework/Math/MathUtility.h"
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"
#include "Framework/Math/Collider.h"
#include "Framework/Math/RectCollider.h"
#include "Framework/Math/CIrcleCollider.h"

// Camera
#include "Framework/Camera/Camera.h"

// Texture
#include "Framework/Texture/SRV.h"
#include "Framework/Texture/SamplerState.h"
#include "Framework/Texture/BlendState.h"
#include "Framework/Texture/StateManager.h"
#include "Framework/Texture/SRVManager.h"

// Animation
#include "Framework/Animation/Action.h"

// BagicObject
#include "Object/BagicObj/Quad.h"
#include "Object/BagicObj/Sprite.h"
#include "Object/BagicObj/Effect.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"

extern Vector2 mousePos;