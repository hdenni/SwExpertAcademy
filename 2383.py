'''
https://bit.ly/2TuEhQm
'''
p = list() # people : [[x, y, stair(Default -1)], ...]
s = list() # stairs : [[x, y, time], ...]

pNum = 0

def dist(x, y, stair):
    global s
    return abs(s[stair][0] - x) + abs(s[stair][1] - y)

# ps : ps[0] = 첫번째 계단을 내려가는 사람 수 / ps[1] = 두번째 계단을 내려가는 사람 수
# exp[i] : [Move, Down, Stair Num]
def cal_time(exp, ps, time):
    global pNum
    
    move = 0
    down = 1
    stair = 2

    k = 0
    while k != pNum:
        time += 1
        
        for i in range(pNum):
            where = exp[i][stair]
            
            # 이미 도착해있음
            if exp[i][down] == -1:
                continue
            if exp[i][move] > 0:
                exp[i][move]-=1
            # 계단에 도착
            elif exp[i][move] == 0:
                if ps[where] < 3:
                    ps[where] += 1
                    exp[i][move] = -1
                    exp[i][down] -= 1
                else:
                    # 계단이 다 차서 기다려야 함
                    continue
            
            # 내려가는중
            elif exp[i][move] == -1:
                exp[i][down] -= 1
                
        for i in range(pNum):
            if exp[i][move] == -1 and exp[i][down] == 0:
                exp[i][down] = -1
                ps[exp[i][stair]] -= 1
                k += 1
                
    return time
            

def check_case(p, man):
    global pNum
    global s, minute
    
    if man == pNum:
        expect = list()
        for i in range(pNum):
            expect.append([dist(p[i][0], p[i][1], p[i][2])+1,s[p[i][2]][2], p[i][2]])
        
        new_minute = cal_time(expect, [0,0], 0)
        '''
        if new_minute == 8:
            for i in range(pNum):
                print(expect[i][2], end=' ')
            print()
        '''
        if minute > new_minute :
            minute = new_minute
        return

    for i in range(2):
        p[man][2] = i
        check_case(p, man+1)
        #p[man][2] = -1

    return
    

if __name__ == "__main__":
    #global pNum, p, s, times
    
    testcase = int(input())

    for t in range(1, testcase+1):
        # Reset
        minute = 0 # result time
        p = list()
        s = list()
        
        size = int(input())
        pNum = 0 # num of people
        field = [list(map(int, input().split())) for i in range(size)]
        for i in range(size):
            for j in range(size):
                if field[i][j] == 1:
                    pNum+=1
                    p.append([i,j,-1])
                elif field[i][j] > 1:
                    s.append([i, j, field[i][j]])

        '''
        times = list()
        for i in range(pNum):
                times.append(dist(p[j][0], p[j][1], 0), dist(p[j][0], p[j][1], 1))
        '''
        minute = 200
        check_case(p, 0)
        print("#%d %d"%(t, minute))
         
