'''
https://bit.ly/2TYgCrU
'''
testcase = int(input())

for i in range(testcase):
    tc = int(input())
    dic = {}
    scores=input()
    score_list = scores.split()
    for j in score_list:
        dic[j] = dic.get(j, 0)+1

    a, b = max(zip(dic.values(), dic.keys()))
    sort_list = sorted(zip(dic.values(), dic.keys()))

    new_dic = []
    for key, value in dic.items():
        if value == a:
            new_dic.append(key)

    result = int(max(new_dic))
    
    print("#%d %d"%(tc,result))
