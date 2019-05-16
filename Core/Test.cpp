#include <iostream>
#include <fstream>
#include "Loader.cpp"
#include "BOptions.h"
using namespace std;
int main(int argc, char const *argv[])
{
	Launcher Lau;
	BOptions Option(&Lau);
	ofstream o("c.txt");
	string a="1";
	Option.opts["pjava"]="C:\\Program Files\\Java\\jre1.8.0_201\\bin\\java.exe";
	Option.opts["max_mem"]="512";
	Option.opts["min_mem"]="128";
	Option.opts["height"]="480";
	Option.opts["width"]="854";
	Option.opts["jvmarg"]="-Dfml.ignoreInvalidMinecraftCertificates=true -Dfml.ignorePatchDiscrepancies=true";
	Lau.uuid="f6122c9461e24d12af2c637819ed39b7";
	Lau.username="lala";
	Lau.uuid=UUIDgenerator(Lau.username);
	Load(Lau);
	Option.LoadOptions2Lau();
	cout<<Lau.uuid;
	o.close();
	//f6122c9461e24d12af2c637819ed39b7
	// "${auth_player_name}"
	// "${version_name}"
	// "${game_directory}"
	// "${assets_root}"
	// "${assets_index_name}"
	// "${auth_access_token}"
	// "${user_type}"
	// "${version_type}"
	// JrePath+" -Xmx"+MaxMem+" -Dfml.ignoreInvalidMinecraftCertificates=true -Dfml.ignorePatchDiscrepancies=true -Djava.library.path="+natives+" -cp "+libjars+" "+new JSONObject(ReadAllTextFromFile(jsonPath)).get("mainClass")+" "+minecraftArguments);
	//HKEY_LOCAL_MACHINE\SOFTWARE\JavaSoft\Java Runtime Environment\<第一个版本名称，如1.8.0_144>
	return 0;
}