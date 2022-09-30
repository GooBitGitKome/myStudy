def rang(inf):
    for i in range(2):
        for j in range(i + 1, 3):
            if(int(inf[i]) > int(inf[j])): 
                return 0
            if(int(inf[i]) == int(inf[j])):
                return 0
    return 1

inf = input().split(' ')
if(rang(inf)): print('Yes')
else: print('No')
