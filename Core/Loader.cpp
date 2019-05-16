#include "rapidjson/document.h"
#include <iostream>
#include <vector>
#include <map>
#include "stdlib.h"
using namespace std;
#include "Core.h"
using namespace rapidjson;
void Load(Launcher &Lau)
{
	map<string,string>exmap;
	string json=read("1.12.2.json"),Libs_;
	Document dom;
	dom.Parse(json.c_str());
	Lau.pbase=GetBasePath();//获得工作路径
	Lau.id=dom["id"].GetString();//获得Id
	Lau.mainclass=dom["mainClass"].GetString();//获得mainclass
	Lau.vtype=dom["type"].GetString();
	if(dom.HasMember("assetIndex"))
		Lau.asindex=dom["assetIndex"]["id"].GetString();
	Value& libs=dom["libraries"];//获得libraries
	Lau.mcargs=dom["minecraftArguments"].GetString();
	for (auto& v : libs.GetArray())
	{
			if (v.HasMember("extract"))
			{
				exmap.insert(pair<string,string>(v["name"].GetString(),v["extract"]["exclude"].GetArray()[0].GetString()));
				continue;
			}
	}
	for (auto& v : libs.GetArray())
	{
			if(exmap.count(v["name"].GetString()))
				continue;
			vector<string> tmp1=split(v["name"].GetString(),":");
			string names="",last,native;
			for (int x=0;x<tmp1[0].length();x++)
			{
				if(tmp1[0][x]=='.')
					tmp1[0][x]='\\';
			}
			if(tmp1[1].find("platform")!=string::npos&&v.HasMember("natives"))
			{
				Value& natives_=v["natives"];
				native=v["natives"]["windows"].GetString();
				if(native.find("${arch}")!=string::npos)
					Replace(native,"${arch}",GetSystemBits());
				last=tmp1[1]+"-"+tmp1[2]+"-"+native;
			}else
				last=tmp1[1]+"-"+tmp1[2];
			names=Lau.pbase+Lau.gmdir+"\\libraries\\"+tmp1[0]+"\\"+tmp1[1]+"\\"+tmp1[2]+"\\"+last+".jar;\n";
			Libs_+=names;
	}
	Lau.plibs+=Libs_+Lau.pbase+Lau.gmdir+"\\versions\\"+Lau.id+"\\"+Lau.id+".jar";
	Lau.DealminecraftArguments();
}