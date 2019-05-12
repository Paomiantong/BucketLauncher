import mclauncher,os
def test():
	p1=os.getcwd()+"\\1.11.json"
	laun=mclauncher.laun(os.getcwd(),p1,"test")
	laun.args_javapath="D:\\Java8\\bin\\javaw.exe"
	laun.dealcmd()
	print(laun.base_cmd)
test()