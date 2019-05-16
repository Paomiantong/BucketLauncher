#ifndef BARGS_H
#define BARGS_H
struct Barg
{
	string name;
	string value;
	int type;
	Barg(void){}
	Barg(string n,string v,int t)
	{
		name=n;
		value=v;
		type=t;//0int 1string 2Xname
	}
};
struct Bargs
{
	Barg args[101];
	int tot;
	Bargs(void)
	{
		tot=0;
	}
	void newarg(string n,string v,int t)
	{
		args[tot++]=Barg(n,v,t);
	}
	string GetAllargs()
	{
		string str;
		for(int i=0;i<tot;i++)
			if(args[i].type==1)
				str+="-"+args[i].name+" \""+args[i].value+"\" ";
			else if(args[i].type==2)
				str+=args[i].value+" ";
			else
				str+="-"+args[i].name+" "+args[i].value+" ";

		return str;
	}
	bool setargsv(string n,string v)
	{
		for(int i=0;i<tot;i++)
		{
			if(args[i].name=="n")
			{
				args[i].value=v;
				return 1;
			}
		}
		return 0;
	}
};
#endif