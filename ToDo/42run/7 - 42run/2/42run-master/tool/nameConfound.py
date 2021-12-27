#encoding=utf-8

import hashlib,re,os
# 机密秘钥
__SALT__="926670100e188233f3853000f2e71356"
# 路径
__PATH__=os.getcwd()+"/build/"
fileList=[
# 要替换的Html文件
	__PATH__+"index.html",
	__PATH__+"templates/donate.html",
	__PATH__+"templates/login.html",
	__PATH__+"templates/menu.html",
	__PATH__+"templates/playlist.html",
	__PATH__+"templates/setting.html",
	__PATH__+"templates/timer.html",

# 要替换的JS文件
	__PATH__+"js/app.js",
	__PATH__+"js/controllers.js",
	__PATH__+"js/services.js"
]
# 获取16位字符串的MD5值
def getHash(_str):
	hashStr="_"+hashlib.md5(_str+__SALT__).hexdigest()[8:-8].upper()
	return hashStr

# 获取函数名值
def getFunctionName():
	nameListTmp=[]
	nameList=[]

	# 获取所有文件中符合函数名的字符串
	for oneFile in fileList:
		fileTmp=open(oneFile,"r")
		nameListTmp.extend(re.findall(r'[\'\"]\w+\",function\(',fileTmp.read()))
		fileTmp.close()
	nameListTmp=set(nameListTmp)
	# 去除多余匹配字符
	for oneName in nameListTmp:
		finallName=oneName.replace("\",function(","").replace("\'","").replace("\"","")
		nameList.append(finallName)
	return nameList

def main():
	nameList=getFunctionName()
	for oneFile in fileList:
		fp=open(oneFile,"r")
		fpText=fp.read()
		for oneName in nameList:
			fpText=fpText.replace(oneName,getHash(oneName))
			print oneFile.replace(__PATH__,"")," function:",oneName," --> ",getHash(oneName)
		fp.close()
		fp1=open(oneFile,"w")
		fp1.write(fpText)
		fp1.close()


if __name__ == '__main__':
	main()






