#pragma once

#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN // 从 Windows 头中排除极少使用的资料
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <wrl.h>//添加WTL支持 方便使用COM
#include <dxgi1_6.h>
#include <DirectXMath.h>
#include <d3d12.h>//for d3d12
#include <d3dcompiler.h>
#if defined(_DEBUG)
#include <dxgidebug.h>
#endif
#include <wincodec.h> //for WIC

struct ST_GRS_VERTEX
{
	DirectX::XMFLOAT4 m_v4Position;		//Position
	DirectX::XMFLOAT2 m_vTex;		//Texcoord
	DirectX::XMFLOAT3 m_vNor;		//Normal
};