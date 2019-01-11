#Baby-Gin Problem
testcase = int(input())
for t in range(testcase):
    data = list(map(int,input()))
    count = [0]*12
    k=0
    for i in range(6):
        if k < data[i]:
            k = data[i]
        count[data[i]]+=1

    tflag = 0
    rflag = 0
    print(count)
    for i in range(10):
        if count[i] == 0:
            continue
        if count[i] >= 3:
            count[i] -= 3
            tflag += 1
    
        if count[i] > 0 and count[i+1] > 0 and count[i+2] > 0:
            rflag += 1
            count[i] -= 1
            count[i+1] -= 1
            count[i+2] -= 1

    if tflag + rflag == 2:
        print("Baby Gin")
    else:
        print("Lose")


    
