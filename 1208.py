for i in range(1,11):
    num = int(input())
    boxes = input()
    box = list(map(int,boxes.split()))

    for j in range(num):
        if max(box)-min(box)<=1:
            break
        else:
            maxi = box.index(max(box))
            mini = box.index(min(box))
        
            box[maxi]-=1
            box[mini]+=1

    print("#%d %d"%(i, max(box)-min(box)))
    
