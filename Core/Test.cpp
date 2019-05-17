#include <iostream>
#include <fstream>
#include "C:\Users\Administrator\Desktop\DuiDemo\FirstDuilibDemo\FirstDuilibDemo\Core\Loader.cpp"
#include "C:\Users\Administrator\Desktop\DuiDemo\FirstDuilibDemo\FirstDuilibDemo\Core\BOptions.h"
using namespace std;
int main(int argc, char const *argv[])
{
	Launcher Lau;
	BOptions Option(&Lau);
	ofstream o("test.cmd");
	Option.opts["pjava"]="C:\\Program Files\\Java\\jre1.8.0_201\\bin\\java.exe";
	Option.opts["max_mem"]="512";
	Option.opts["min_mem"]="128";
	Option.opts["height"]="480";
	Option.opts["width"]="854";
	Option.opts["jvmarg"]="-Dfml.ignoreInvalidMinecraftCertificates=true -Dfml.ignorePatchDiscrepancies=true";
	Lau.uuid="f6122c9461e24d12af2c637819ed39b7";
	Lau.username="lala";
	Lau.uuid=UUIDgenerator(Lau.username);
	Load(Lau,"F:\\game\\M inecraft\\.minecraft\\versions\\1.12.2-forge1.12.2-14.23.5.2816\\1.12.2-forge1.12.2-14.23.5.2816.json");
	Option.LoadOptions2Lau();
	o<<Lau.BuildCommand();
	o.close();
	//HKEY_LOCAL_MACHINE\SOFTWARE\JavaSoft\Java Runtime Environment\<第一个版本名称，如1.8.0_144>
	return 0;
}