#pragma once

#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN // 从 Windows 头中排除极少使用的资料
#include <windows.h>
#include <tchar.h>
#include <fstream>  //for ifstream
#include <strsafe.h>
#include <atlconv.h> //for T2A
#include <atlcoll.h>
#include <wrl.h> //添加WTL支持 方便使用COM
#include <dxgi1_6.h>
#include <DirectXMath.h>
#include <d3d12.h>//for d3d12
#include <d3dcompiler.h>
#if defined(_DEBUG)
#include <dxgidebug.h>
#endif
#include <wincodec.h> //for WIC

#include "..\WindowsCommons\DDSTextureLoader12.h"

using namespace std;
using namespace Microsoft;
using namespace Microsoft::WRL;
using namespace DirectX;


struct ST_GRS_VERTEX
{//这次我们额外加入了每个顶点的法线，但Shader中还暂时没有用
	XMFLOAT4 m_v4Position;		//Position
	XMFLOAT2 m_vTex;		//Texcoord
	XMFLOAT3 m_vNor;		//Normal
};