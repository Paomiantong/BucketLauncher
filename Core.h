//ifndef CORE_H
//define CORE_H
//include <stdlib.h>  
//include <stdio.h> 
string GetBasePath(void)//获取工作路径
{  
    char szFilePath[MAX_PATH + 1]={0};  
    GetModuleFileNameA(NULL, szFilePath, MAX_PATH);  
    (strrchr(szFilePath, '\\'))[0] = 0;
    string path = szFilePath;  
  
    return path;  
}  

string read(string path)
{
	ifstream F(path.c_str());
	string str,tmp;
	while(getline(F,tmp))
	{
		str+=tmp;
	}
	F.close();
	return str;
}

vector<string> split(const string& str, const string& delim) {  
	vector<string> res;  
	if("" == str) return res;  
	//先将要切割的字符串从string类型转换为char*类型  
	char * strs = new char[str.length() + 1] ; //不要忘了  
	strcpy(strs, str.c_str());   
 
	char * d = new char[delim.length() + 1];  
	strcpy(d, delim.c_str());  
 
	char *p = strtok(strs, d);  
	while(p) {  
		string s = p; //分割得到的字符串转换为string类型  
		res.push_back(s); //存入结果数组  
		p = strtok(NULL, d);  
	}  
 
	return res;  
}
// 获取操作系统位数
string GetSystemBits()
{
	typedef void (WINAPI *LPFN_PGNSI)(LPSYSTEM_INFO); 
    SYSTEM_INFO si;
    LPFN_PGNSI pGNSI = (LPFN_PGNSI) GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "GetNativeSystemInfo");
    pGNSI(&si);
     if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64 )
    {
        return "64";
    }
    return "32";
}
class Launcher
{
public:
	string id;
	string pbase;//当前路径
	string pjava;//java路径
	string base_launtype;//启动类型
	string base_launargs;//启动参数
	string base_username;//用户名
	int max_mem;//最大内存
	int min_mem;//最小内存
	int usertype=0;
	string mainclass;//启动主类
	string asindex;//资源引索
	string gmdir;
	string asdir;
	string paths;//库路径
	string usertype_info[2];//用户类型args_usertype_info[0]为盗版登录args_usertype_info[1]为正版登录
	Launcher(void)
	{
		max_mem=512;
		min_mem=128;
		usertype_info[0]="Legacy";
		usertype_info[1]="mojang";
		mainclass="";
		asindex="";
		gmdir="\\.minecraft";
		asdir="\\.minecraft\\assets";
		paths="\"";
	}
};
//endif