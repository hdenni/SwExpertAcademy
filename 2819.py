# https://bit.ly/3lj70Gk

def dfs(now, x):
    d = [(-1,0), (0,1), (1,0), (0,-1)]
    # up right down left
    if len(x) == 7:
        result.add(x)
        return
    
    if now[0]<0 or now[1]<0 or now[0]>3 or now[1]>3: return
    x += L[now[0]][now[1]]
    
    for i in d:
        dfs((now[0]+i[0], now[1]+i[1]), x)
    
    

tc = int(input())

for t in range(1, tc+1):
    global L
    L = list()
    for i in range(4):
        L.append(list(input().split()))

    global result
    result = set()

    for i in range(4):
        for j in range(4):
            dfs((i,j), '')

    print(f'#{t} {len(result)}')

    
    
