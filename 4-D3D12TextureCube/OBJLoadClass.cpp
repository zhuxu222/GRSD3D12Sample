#include "OBJLoadClass.h"

bool OBJLoadClass::LoadOBJFile(std::string OBJFileName)
{
	ifstream fin;

	fin.open(OBJFileName.c_str());
	if (fin.fail())
	{
		return false;
	}
	//line代表文件里的一整行,包含空格，字符等。 而word代表文件里的一个单词，无空格存在
	std::string line, word;

	//空行的数量
	UINT NullStrCount = 0;

	//对象的数量
	UINT OBJCount = 0;

	//首先在第一行读取出顶点数(这里顶点数每三个就是一个三角形)
	while (!fin.eof())
	{
		line.clear();
		word.clear();

		getline(fin, line);


		//如果line包含mtllib,则存储OBJ的材质文件的相对路径
		if (line.find("mtllib") != string::npos)
		{
			string MaterialFileName;
			istringstream record(line);
			record >> word;
			record >> word;
			MaterialFileName =   word;
			ObjMaterialFileName = MaterialFileName;
			continue;
		}
		if (line[0]=='v' && line[1] == ' ')
		{
			DirectX::XMFLOAT4 v;
			string MaterialFileName;
			istringstream record(line);
			record >> word;
			record >> v.x >> v.y >> v.z;
			v.w = 1.0f;

			mModelPosArray.push_back(v);
			continue;
		}
		if (line[0] == 'v' && line[1] == 'n')
		{
			DirectX::XMFLOAT3 vn;
			string MaterialFileName;
			istringstream record(line);
			record >> word;
			record >> vn.x >> vn.y >> vn.z;

			mModelNormalArray.push_back(vn);
			continue;
		}
		if (line[0] == 'v' && line[1] == 't')
		{
			DirectX::XMFLOAT2 vt;
			string MaterialFileName;
			istringstream record(line);
			record >> word;
			record >> vt.x >> vt.y;

			mModelTexArray.push_back(vt);
			continue;
		}
		if (line[0] == 'f')
		{
			int start = 2;
			int end = start;
			std::vector<std::string> groupVVtVn = stringSplit(line.substr(2, line.size() - 2)," ");
			for (size_t i = 0; i < groupVVtVn.size(); i++)
			{
				std::vector<std::string> itemVVtVn= stringSplit(groupVVtVn[i], "/");
				int vIndex = atoi(itemVVtVn[0].c_str());
				int vtIndex = atoi(itemVVtVn[1].c_str());
				int vnIndex = atoi(itemVVtVn[2].c_str());
				ST_GRS_VERTEX vertex;
				vertex.m_v4Position = mModelPosArray[vIndex-1];
				vertex.m_vTex = mModelTexArray[vtIndex-1];
				vertex.m_vNor = mModelNormalArray[vnIndex-1];

				mVertexData.push_back(vertex);
			}

			continue;
		}

	}
	fin.close();

	for (uint32_t i = 0; i < mVertexData.size(); i++)
	{
		mIndices.push_back(i);
	}

	return true;
}

bool OBJLoadClass::LoadOBJMaterialFile(string MaterialFileName)
{
	return false;
}

OBJLoadClass::OBJLoadClass(std::string OBJFileName)
{
	LoadOBJFile(OBJFileName);
}

std::vector<std::string> stringSplit(const std::string& target, const std::string& key)
{
	std::vector<std::string> splitedStrVec;
	int b = 0;
	int e = 0;
	while (b < target.size() && e < target.size())
	{
		e = target.find(key, b);
		if (e== std::string::npos)
		{
			e = target.size();
		}
		std::string subStr = target.substr(b, e-b);
		if (!subStr.empty())
		{
			splitedStrVec.push_back(subStr);
		}
		b = e + key.size();
	}
	return splitedStrVec;
}
