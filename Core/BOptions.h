#ifndef BOPTIONS_H
#define BOPTIONS_H
#include <map>
#include "Core.h"
class BOptions
{
public:
	map<string, string>	opts;
	Launcher* Lau;
	BOptions(Launcher* L)
	{
		Lau=L;
		opts.insert(pair<string,string>("pjava",""));
		opts.insert(pair<string,string>("max_mem",""));
		opts.insert(pair<string,string>("min_mem",""));
		opts.insert(pair<string,string>("height",""));
		opts.insert(pair<string,string>("width",""));
		opts.insert(pair<string,string>("jvmargs",""));
	}
	void LoadOptions2Lau()
	{
		Lau->pjava=opts["pjava"];
		Lau->max_mem=opts["max_mem"];
		Lau->min_mem=opts["min_mem"];
		Lau->height=opts["height"];
		Lau->width=opts["width"];
		Lau->jvmargs=opts["jvmargs"];
	}
	void save()
	{

	}
	void load()
	{

	}
};
#endif