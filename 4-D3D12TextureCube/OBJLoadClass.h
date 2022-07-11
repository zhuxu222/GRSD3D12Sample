#pragma once
#include <vector>
#include <string>
#include <fstream>  //for ifstream
#include <sstream>
#include <windows.h>

#include "4-D3D12TextureCube.h"

using namespace std;
using std::ifstream;
using std::istringstream;

class OBJLoadClass
{
private:

public:
	std::vector<DirectX::XMFLOAT4> mModelPosArray; //在外部加载的模型顶点位置
	std::vector<DirectX::XMFLOAT3> mModelNormalArray; //在外部加载的模型数据
	std::vector<DirectX::XMFLOAT2> mModelTexArray; //在外部加载的模型数据纹理坐标
	std::vector<ST_GRS_VERTEX> mVertexData;
	std::vector<UINT32> mIndices;
	std::string ObjMaterialFileName;

private:
	//加载OBJ文件
	bool LoadOBJFile(std::string OBJFileName);

	//加载OBJ材质文件
	bool LoadOBJMaterialFile(string MaterialFileName);

	

public:
	OBJLoadClass(std::string OBJFileName);

};

std::vector<std::string> stringSplit(const std::string& target, const std::string& key);

