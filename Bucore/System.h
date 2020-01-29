#ifndef BC_SYSTEM_H
#define BC_SYSTEM_H

#include <string>
#ifdef __WIN32__
#include <windows.h>
#define MAX_PATH 1024
#else
#include <unistd.h>
#endif
#define _dirname_ getDir()
std::string getDir();
#endif
