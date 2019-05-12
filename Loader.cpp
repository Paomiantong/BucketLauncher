#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include "stdlib.h"
using namespace std;
#include "Core.h"
using namespace rapidjson;
int main(int argc, char const *argv[])
{
	Launcher Lau;
	string json=read("1.11.json");
	Document dom;
	dom.Parse(json.c_str());
	Lau.pbase=GetBasePath();//获得工作路径
	Lau.id=dom["id"].GetString();//获得Id
	//获得libraries
	Value& libs=dom["libraries"];
	for (auto& v : libs.GetArray())
	{
			Value& tmp=v;
			vector<string> tmp1=split(tmp["name"].GetString(),":");
			string names="",last,native;
			for (int x=0;x<tmp1[0].length();x++)
			{
				if(tmp1[0][x]=='.')
					tmp1[0][x]='\\';
			}
			if(tmp1[1].find("platform")!=string::npos&&v.HasMember("natives"))
			{
				Value& natives_=tmp["natives"];
				native=tmp["natives"]["windows"].GetString();
				if(native.find("${arch}")!=string::npos)
					native.replace(native.find("${arch}"),7,GetSystemBits());
				last=tmp1[1]+"-"+tmp1[2]+"-"+native;
			}else
				last=tmp1[1]+"-"+tmp1[2];
			names=Lau.pbase+Lau.gmdir+"\\libraries\\"+tmp1[0]+"\\"+tmp1[1]+"\\"+tmp1[2]+"\\"+last+".jar";
    		cout<<names<<endl;
	}
	return 0;
}