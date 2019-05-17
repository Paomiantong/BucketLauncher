#ifndef CORE_H
#define CORE_H
#include "Bargs.h"
#include "BCommon.h"
#include <stdio.h>
class Launcher
{
public:
	string id;
	string pbase;//当前路径
	string pjava;//java路径
	string launtype;//启动类型
	string mcargs;//mc启动参数
	string jvmargs;
	string username;//用户名
	string max_mem;//最大内存
	string min_mem;//最小内存
	int usertype;
	string mainclass;//启动主类
	string asindex;//资源引索
	string gmdir;
	string asdir;
	string plibs;//库路径
	string usertype_info[2];//用户类型args_usertype_info[0]为盗版登录args_usertype_info[1]为正版登录
	string uuid;
	string height;
	string width;
	string vtype;
	string fatherid;
	bool inner;
	Bargs args;
	Launcher(void)
	{
		max_mem="512";
		min_mem="128";
		usertype=0;
		usertype_info[0]="Legacy";
		usertype_info[1]="mojang";
		mainclass="";
		asindex="";
		gmdir="\\.minecraft";
		asdir="\\.minecraft\\assets";
		plibs="";
		uuid="";
		height="480";
		width="854";
		jvmargs="";
		inner=false;
	}
	void DealminecraftArguments()
	{
		Replace(mcargs,"${auth_player_name}",username);
		Replace(mcargs,"${version_name}","Cola");
		Replace(mcargs,"${game_directory}","\""+pbase+gmdir+"\"");
		Replace(mcargs,"${assets_root}","\""+pbase+asdir+"\"");
		Replace(mcargs,"${assets_index_name}",asindex);
		Replace(mcargs,"${auth_uuid}",uuid);
		Replace(mcargs,"${auth_access_token}",uuid);
		Replace(mcargs,"${user_properties}","{}");
		Replace(mcargs,"${version_type}",vtype);
		Replace(mcargs,"${user_type}",usertype_info[usertype]);
	}
	string BuildCommand()
	{
		args.newarg("java","\""+pjava+"\"",2);
		args.newarg("???","-XX:HeapDumpPath=MojangTricksIntelDriversForPerformance_javaw.exe_minecraft.exe.heapdump -XX:+UseG1GC -XX:-UseAdaptiveSizePolicy -XX:-OmitStackTraceInFastThrow",2);
		args.newarg("Xmn","-Xmn"+min_mem+"m",2);
		args.newarg("Xmx","-Xmx"+max_mem+"m",2);
		if(!inner)
			args.newarg("Djava.library.path","-Djava.library.path=\""+pbase+gmdir+"\\versions\\"+id+"\\"+id+"-natives\"",2);
		else
			args.newarg("Djava.library.path","-Djava.library.path=\""+pbase+gmdir+"\\versions\\"+fatherid+"\\"+fatherid+"-natives\"",2);
		args.newarg("jvm",jvmargs,2);
		args.newarg("cp",plibs,1);
		args.newarg("mainClass",mainclass,2);
		args.newarg("mc",mcargs,2);
		args.newarg("more"," --height "+height+" --width "+width,2);
		return args.GetAllargs();
	}
	void Setinner(string fid)
	{
		fatherid=fid;
		inner=1;
	}
};
#endif