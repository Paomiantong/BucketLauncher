#include <iostream>
#include "Game.h"
using namespace std;
int main()
{
	Game g;
	g.LoadVersion(Version("testdata/1.14.4.json"));
	cout<<g.GetVersion().mainclass<<endl;
	for(auto &i : g.GetVersion().libraries.GetLostLib())
	{
		cout<<i.path<<endl;
	}
	return 0;
}
