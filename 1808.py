'''
https://bit.ly/2UwKY9c
'''

from itertools import product

num_of_calc = 1
def rec(k, p, ing):
    global num_of_calc
    
    if k==1:
        if num_of_calc > ing:
            num_of_calc = ing
            return
    
    for i in p:
        if k%i == 0:
            ing += (len(str(i))+1)
            rec(k/i, p, ing)
            ing -= (len(str(i))+1)
'''
def subset(p, index):
    global POS
    if index == len(p):
        POS.append(p)
        return
    subset(p[:], index+1)
    p.pop(index)
    subset(p[:], index)
'''

if __name__ == "__main__":
    testcase = int(input())

    for t in range(1,testcase+1):

        # Inputs
        calc = list()
        c = 0
        tmp = input().split()
        for i in range(10):
            if tmp[i]=='1':
                calc.append(i)
                c+=1

        # num : 1<=num<=10^6
        x = input()
        num = int(x)
        
        # Start
        # 가능한 숫자가 없음 > Fail
        if not c:
            print("#%d -1"%t)
            continue

        # 결과값이 1인 경우
        if num==1:
            if 1 in calc:
                print("#%d 2"%t)
                continue
            else:
                print("#%d -1"%t)
                continue

        # 만들 수 있는 숫자 리스트
        t_p = list()
        for i in range(1,len(x)+1):
            t_p += product(calc, repeat=i)

        p=set()
        for tuples in t_p:
            s=0
            for i in range(len(tuples)):
                s+=tuples[i]*(10**i)
            if s!=0 and s!=1 and num%s == 0:
                p.add(s)

        num_of_calc = 10**6
        rec(num, p, 0)
        
        '''
        # 부분집합 만들기
        POS = list()
        subset(p,0)

        comp = list()
        for items in POS:
            res = 1
            for i in items:
                res *= i
            if res == num:
                comp.append(items)

        # 가능한 조합이 없음
        if not comp:
            print("#%d -1"%t)
            continue

        pr = list()
        for items in comp:
            a = len(items)
            for i in items:
                a += len(str(i))
            pr.append(a)
        '''
        if num_of_calc == 10**6:
            num_of_calc = -1
        print("#%d %d"%(t,num_of_calc))

        
