def checkRange(inpt):
    W = int(inpt[0])
    H = int(inpt[1])
    x = int(inpt[2])
    y = int(inpt[3])
    r = int(inpt[4])
    #the point of Up, Down, Left and Right Circle(x,y)
    points = [
        [x,y+r],#Up
        [x,y-r],#Down
        [x-r,y],#Left
        [x+r,y]#Right
    ]
    if(H > 0):
        if(points[1][1] < 0): return 0
        if(points[0][1] > H): return 0
    if(H < 0):
        if(points[0][1] > 0): return 0
        if(points[1][1] < H): return 0
    if(W > 0):
        if(points[2][0] < 0): return 0
        if(points[3][0] > W): return 0
    if(W < 0):
        if(points[3][0] > 0): return 0
        if(points[2][0] < W): return 0
    return 1

inpt = input().split(' ')
if(checkRange(inpt)):print('Yes')
else: print('No')