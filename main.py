import os

#ignorefile = ['.fonts', '.git']
PATH = "."
subsections = ["", "section", "subsection", "subsubsection"] # 层次列表
#content = ["", "lstinputlisting", "input"] # lstinputlisting 输入.cpp文件,input 输入.tex文件
content = {"cpp": "lstinputlisting", "tex": "input", "md": "input"}

outTexfile = "template.tex" # 要生成的.tex文件


# 解析参数字符串==>参数列表
def Parse(paras):
    n = len(paras)
    res = []
    i = 0
    while (i < n):
        if (paras[i] == '<'):
            filename = ''
            i += 1
            while (i < n and paras[i] != '>'):
                filename += paras[i]
                i += 1
            i += 1
            res.append(filename)
    return res


# 将生成的latex排版代码写入到tex文件中
def writeTotex(path, curfile, parass, deep):
    if (deep == 1):
        with open(outTexfile, 'a') as f:
            f.write('\\' + subsections[deep] + '{' + curfile + '}\n')
    print(curfile, deep)
    n = len(parass)
    while (parass[n - 1] == ''):
        parass.pop()
        n -= 1
    for each in parass:
        paras = Parse(each)
        n = len(paras)
        with open(outTexfile, 'a') as f:
            f.write('\\' + subsections[deep + 1] + '{' + paras[0] + '}\n')
        if n == 4:
            Config = readConfig(path + '/' + paras[3])
            writeTotex(path + '/' + paras[3], paras[3], Config, deep + 1)
        else:
            for i in range(1, n):
                if (paras[i] != ''):
                    with open(outTexfile, 'a') as f:
                        s = paras[i].split('.')[-1]
                        if (s == 'md'):
                            os.popen("pandoc " + path + '/' + paras[i] +
                                     " -o " + path + '/' +
                                     paras[i].replace('md', 'tex'))
                            paras[i] = paras[i].replace('md', 'tex')
                        f.write('\\' + content[s] + '{' + path + '/' +
                                paras[i] + '}\n')


# 除去空格和回车符
def Replace(lst):
    n = len(lst)
    for i in range(0, n):
        lst[i] = lst[i].replace(' ', '').replace('\n', '')
    return lst


# 读取config配置文件
def readConfig(path):
    with open(path + '/config', 'r') as f:
        return Replace(f.readlines())


# 将head文件内容写入到要生成的tex文件中
def HeadtoTex():
    with open(outTexfile, 'w') as tex:
        with open("head", 'r') as head:
            tex.write(head.read())


def main():
    HeadtoTex()
    mainConfig = readConfig(PATH)
    for each in mainConfig:
        docname = each.replace(' ', '').replace('\n', '')
        path = PATH + '/' + docname
        parass = readConfig(path)
        writeTotex(path, docname, parass, 1)
    with open(outTexfile, 'a') as f:
        f.write('\\end{document}')


if __name__ == "__main__":
    main()
