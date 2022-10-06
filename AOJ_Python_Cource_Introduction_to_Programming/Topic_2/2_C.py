def insertionSort(list):
    for i in range(1,len(list)):
        key = i
        for j in range(i-1,-1,-1):
            if(list[j] > list[key]): 
                list[j] ,list[key] = list[key] ,list[j]
                key = j
    return list
inpt = input().split(' ')
list = list(map(int,inpt))
sorted_list = insertionSort(list)
for i in range(len(sorted_list) - 1):
    print(sorted_list[i], end = ' ')
print(sorted_list[len(sorted_list) - 1])    