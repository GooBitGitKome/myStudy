def insertionSort(list):
    for i in range(1,len(list)):
        key = i
        for j in range(i-1,-1,-1):
            if(list[j] > list[key]): 
                list[j] ,list[key] = list[key] ,list[j]
                key = j
    return list