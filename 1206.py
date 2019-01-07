#1206 - View
for i in range(1,11):
    num = int(input())
    inputs = input()
    tall = list(map(int,inputs.split()))


    result = 0
    for j in range(2, num-2):
        left = min(tall[j] - tall[j-1], tall[j]-tall[j-2])
        right = min(tall[j]-tall[j+1], tall[j]-tall[j+2])

        if left<0 or right<0:
            continue
        else:
            result = result + min(left, right)

    print("#%d %d"%(i, result))
    
        
