#include "System.h"
std::string getDir()
{
	std::string executeFile;
#ifdef __WIN32__
    char path[MAX_PATH]; GetModuleFileNameA(NULL,path,MAX_PATH);
    executeFile = path;
#else
    char path[1024];
    int cnt = readlink("/proc/self/exe", path, 1024);
    executeFile=path;
#endif
		std::string dirName = executeFile.substr(0, executeFile.find_last_of("/\\"));
    return dirName;
}
