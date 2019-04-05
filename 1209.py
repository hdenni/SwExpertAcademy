'''
https://bit.ly/2Ug3YcY
'''
for j in range(1,11):
    num = int(input())
    matrix = []
    for k in range(100):
        matrix += list(map(int,input().split()))

    row=[0]*100
    col=[0]*100
    right = 0
    left = 0
    for i in range(10000):        
        rindex = i%100
        cindex = int(i/100)
        
        row[rindex]=  row[rindex] + matrix[i]
        col[cindex] = col[cindex] + matrix[i]
        if i%101 == 0:
            right += matrix[i]
        if i%100 == 99:
            left += matrix[i]

    row = row+col
    row.append(right)
    row.append(left)

    print("#%d %d"%(j, max(row)))
        
