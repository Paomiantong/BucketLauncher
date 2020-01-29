#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string a="xx${arch}xx";
	a.replace(a.find("${arch}"),strlen("${arch}"),"223123123123132");
	cout<<a;
	return 0;
}
