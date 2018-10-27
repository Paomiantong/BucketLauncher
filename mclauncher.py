import json,platform,uuid,os
class laun:
	base_id=""#版本id
	base_path=""#基本路径
	base_libs=[]#库列表
	base_launtype=""#启动类型
	base_launargs=""#启动参数
	base_username=""#用户名
	base_cmd=""
	args_mxm=512#最大内存
	args_mnm=128#最小内存
	args_usertype=0;
	args_usertype_info=["Legacy","mojang"]#用户类型args_usertype_info[0]为盗版登录args_usertype_info[1]为正版登录
	args_javapath=""#java路径
	args_mainclass=""#启动主类
	args_asindex=""#资源引索
	args_gmdir="\\.minecraft"
	args_asdir="\\.minecraft\\assets"
	args_paths="\""#库路径
	forge_inheritsFrom=""
	json_path=""#json路基
	num_paths=0#库路径数
	libs_natives=[]#需要解压的库列表
	def __init__(self, path,jpath,username):
		self.base_path = path#基本路径
		self.json_path = jpath#json路基
		self.base_username = username#用户名
		with open(jpath, 'r') as file:#读入josn
			data = json.load(file)

		self.base_id=data["id"]#获取id
		self.base_libs=data["libraries"]#获取libraries列表
		self.args_mainclass=data["mainClass"]#获取主类

		if("inheritsFrom" in data):
			self.base_launtype="forge"
			self.forge_inheritsFrom=data["inheritsFrom"]
		else:
			self.base_launtype="main"
			self.args_asindex=data["assetIndex"]["id"]
		self.dealpath(data)

		if(self.base_launtype=="forge"):
			fpath=self.base_path+self.args_gmdir+"\\versions\\"+self.forge_inheritsFrom+"\\"+self.forge_inheritsFrom+".json"
			with open(fpath, 'r') as file2:#读入josn
				data2 = json.load(file2)
			self.args_asindex=data2["id"]
			self.dealpath(data2)
		self.dealmcargs(data)
	pass

	def dealcmd(self):
		self.base_cmd=self.args_javapath+" -XX:HeapDumpPath=MojangTricksIntelDriversForPerformance_javaw.exe_minecraft.exe.heapdump -XX:+UseG1GC -XX:-UseAdaptiveSizePolicy -XX:-OmitStackTraceInFastThrow"+" -Xmn"+str(self.args_mnm)+"m"+" -Xmx"+str(self.args_mxm)+"m \"-Djava.library.path="+self.base_path+self.args_gmdir+"\\versions\\"+self.base_id+"\\"+self.base_id+"-natives\" -Dfml.ignoreInvalidMinecraftCertificates=true -Dfml.ignorePatchDiscrepancies=true -cp "+self.args_paths+" "+self.args_mainclass+" "+self.base_launargs
		pass

	def start(self):
		if(self.base_cmd==""):
			self.dealcmd()
		with open("tmp.bat",'w') as f:
			f.write(self.base_cmd)
		w=os.popen("tmp.bat")
		print(w.read())
		os.remove("tmp.bat")
		return w.read()
		pass

	def dealmcargs(self,data):
		var3=getuuid()
		var1=data["minecraftArguments"].replace("${game_directory}","\""+self.base_path+self.args_gmdir+"\"")
		var1=var1.replace("${assets_root}","\""+self.base_path+self.args_asdir+"\"")
		var1=var1.replace("${assets_index_name}",self.args_asindex)
		var1=var1.replace("${version_name}","\"InsB\"")
		var1=var1.replace("${auth_uuid}",var3)
		var1=var1.replace("${auth_access_token}",var3)
		var1=var1.replace("${user_type}",self.args_usertype_info[self.args_usertype])
		var1=var1.replace("${user_properties}","{}")
		var1=var1.replace("${auth_player_name}",self.base_username)
		self.base_launargs=var1+" --height 480 --width 854"
		pass

	def dealpath(self,data):#处理lib列表中的name并整合
		for idx in range(len(data["libraries"])):
			self.num_paths+=1
			lib=data["libraries"][idx]["name"].split(":")
			tmp=list(lib[0])
			for i in range(len(tmp)):
				if(tmp[i]=="."):
					tmp[i]="\\"
			lib[0]="".join(tmp)
			if(lib[1].find("platform")!=-1 and "natives" in data["libraries"][idx]):
				native=data["libraries"][idx]["natives"]["windows"]
				if(native.find("${arch}")):
					native=native.replace("${arch}",platform.architecture()[0][0:2])
				last=lib[1]+"-"+lib[2]+"-"+native
				var=self.base_path+self.args_gmdir+"\\libraries\\"+lib[0]+"\\"+lib[1]+"\\"+lib[2]+"\\"+last+".jar"
				self.libs_natives.append(var)
			else:
				last=lib[1]+"-"+lib[2]
				self.args_paths+=self.base_path+self.args_gmdir+"\\libraries\\"+lib[0]+"\\"+lib[1]+"\\"+lib[2]+"\\"+last+".jar;"
		self.args_paths+=self.base_path+self.args_gmdir+"\\versions\\"+self.base_id+"\\"+self.base_id+".jar\""
	pass
pass

def getuuid():
	uuidcode=str(uuid.uuid4())
	uuidcode=uuidcode.split("-")
	uuidcode="".join(uuidcode)
	return uuidcode
	pass