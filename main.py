import os

ignorefile = ['.fonts', '.git']
PATH = "."
subsections = ["", "section", "subsection", "subsubsection"]
content = ["", "lstinputlisting", "input"]
outTexfile = "template.tex"


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
    #print(res)
    return res


def writeTotex(path, curfile, parass, deep):
    if (deep == 1):
        with open(outTexfile, 'a') as f:
            f.write('\\' + subsections[deep] + '{' + curfile + '}\n')
    print(curfile, deep)
    n = len(parass)
    while (parass[n - 1] == ''):
        parass.pop()
        n -= 1
        #print(parass)
    for each in parass:
        paras = Parse(each)
        #print(paras)
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
                        f.write('\\' + content[i] + '{' + path + '/' +
                                paras[i] + '}\n')


def Replace(lst):
    n = len(lst)
    for i in range(0, n):
        lst[i] = lst[i].replace(' ', '').replace('\n', '')
    return lst


def readConfig(path):
    with open(path + '/config', 'r') as f:
        return Replace(f.readlines())


def HeadtoTex():
    with open(outTexfile, 'w') as tex:
        with open("head", 'r') as head:
            tex.write(head.read())


if __name__ == "__main__":
    HeadtoTex()
    mainConfig = readConfig(PATH)
    for each in mainConfig:
        docname = each.replace(' ', '').replace('\n', '')
        path = PATH + '/' + docname
        parass = readConfig(path)
        writeTotex(path, docname, parass, 1)
    with open(outTexfile, 'a') as f:
        f.write('\\end{document}')
