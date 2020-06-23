# -*- coding: utf-8 -*-

# 위치 tuple return
def drc(p):
    if p=='up': 
        return (-1, 0)
    elif p=='right':
        return (0, 1)
    elif p=='down': 
        return (1, 0)
    elif p=='left': 
        return (0, -1)

# 반대로 가는 경우 reverse
def reverse(x):
    if x=='up': return 'down'
    elif x=='right': return 'left'
    elif x=='left': return 'right'
    elif x=='down': return 'up'

# 좌표 계산
def sum_tuple(x, y):
    return (x[0]+y[0], x[1]+y[1])

# start 지점에 관한 i, j는 main에서 반복문으로 이미 setting 되어있음
# 이 start 지점에 관하여, 네가지 방향 중 어느방향으로 가는 것이 가장 점수가 높은지 확인하면 됨
def sol(b, start):
    global hole, end

    score_save = 0
    #now = start
    
    direction = ['up', 'down', 'right', 'left']
    for d in direction:
        score = 0
        
        now = start
        
        # 첫 시작점일 때는 다른 조건 보지 않고 움직임
        now = sum_tuple(now, drc(d))
        if now[0] == 0 or now[0] == len(b)-1 or now[1] == 0 or now[1] == len(b)-1:
            continue
        
        while True:
            x, y = now
            # (1~5)벽에 부딪침
            if b[x][y] >= 1 and b[x][y] <= 5:
                if b[x][y] == 1:
                    if d =='down':  d = 'right'
                    elif d=='left': d = 'up'
                    else:           d = reverse(d)
                    
                elif b[x][y] == 2:
                    if d == 'up':   d = 'right'
                    elif d=='left': d = 'down'
                    else:           d = reverse(d)
                    
                elif b[x][y] == 3:
                    if d == 'up':       d = 'left'
                    elif d == 'right':  d = 'down'
                    else:               d = reverse(d)
                    
                elif b[x][y] == 4:
                    if d == 'down':     d = 'left'
                    elif d=='right':    d = 'up'
                    else:               d = reverse(d)
                elif b[x][y] == 5:
                    d = reverse(d)
                score += 1

            # (6~10) 웜홀에 도착함
            elif b[x][y] > 5:
                h = b[x][y]
                if now == hole[h][0]: now = hole[h][1]
                else:                 now = hole[h][0]

            # 시작지점/끝지점에 도착, 끝냄
            elif now == start or now in end:
                break
            
            #else:
                #pass
                # 일반좌표..달리할거없음

            now = sum_tuple(now, drc(d))
        # while문 여기까지
        
        if score_save < score:
            score_save = score

    return score_save

testcase = int(input())
for t in range(1, testcase+1):
    # input
    n = int(input())

    # map 입력
    # 테두리를 5로 설정
    b = list()
    b.append([5]*n)
    for i in range(n):
        b.append(list(map(int, input().split())))
    b.append([5]*n)
    
    for i in range(len(b)):
        b[i].insert(0, 5)
        b[i].append(5)

    # hole 정보 저장
    hole = dict()
    for i in range(6, 11):
        hole[i] = list()

    end = list() # hole 탐색하면서 end 위치도 같이 탐색
    for i in range(1, n+1):
        for j in range(1, n+1):
            if b[i][j] >= 6:
                h = b[i][j]
                hole[h].append((i, j))
            elif b[i][j] == -1:
                end.append((i, j))

    # start지점은 0이라면 어디든 될 수 있음
    max_score = 0
    for i in range(1, n+1):
        for j in range(1, n+1):
            if b[i][j] == 0:
                result = sol(b, (i,j))
                if max_score < result: max_score = result


    print("#{} {}".format(t, max_score))
