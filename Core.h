#ifndef CORE_H
#define CORE_H
string read(string path)
{
	ifstream F("1.11.json");
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
#endif