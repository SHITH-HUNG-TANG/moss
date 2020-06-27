import os
import re
import chardet

def load_dir_path_list(inputPath,outputPath):
  
    if not os.path.isdir(outputPath):
        os.makedirs(outputPath)

    # 遞迴列出所有子目錄與檔案
    list_dir = os.listdir(inputPath)
    print(list_dir)
    for thedir in list_dir:
        currenPath = os.path.join(inputPath, thedir)
        files = ["%s/%s" % (currenPath, x)
            for x in os.listdir(currenPath) if x.endswith(".h") or x.endswith(".cpp")]
        print(files)
        if len(files) > 0:
            merge = ""
            for i in range(len(files)):
                f = open(files[i],'rb')#encoding='mbcs'
                data = f.read()
                print(chardet.detect(data))
                encodeType = chardet.detect(data)['encoding']
                if encodeType == 'GB2312':
                    encodeType = 'gb18030'
                data = data.decode(encodeType)
                merge += data

            f = open("%s\%d.txt"%(outputPath,int(re.findall("[0-9]+", thedir)[-2])),'a',encoding='utf-8')
            f.write(merge)

        # print("now %s" % root)
        # for theFile in files:
        #     if theFile.endswith(".h") or theFile.endswith(".cpp"):
        #         count += 1
        #         f = open("%s\%s"%(root,theFile),'r',encoding='utf-8')
        #         merge += f.read()
                
        # if count == 2:
        #     f = open("%s\%d.txt"%(outputPath,int(re.findall("[0-9]+", root)[-2])),'a')
        #     f.write(merge)

    
    # list_path = os.listdir(path)
    # print(list_path)
    # os.system("pause")
    # result = ["%s/%s" % (path, x)
    #           for x in list_path if x.endswith(".h") or x.endswith(".cpp")]
    # result = sorted(result, key=lambda x: int(re.findall("[0-9]+", x)[0]))
    # return result



if __name__ == '__main__':
    load_dir_path_list(".\\input",".\\output")
