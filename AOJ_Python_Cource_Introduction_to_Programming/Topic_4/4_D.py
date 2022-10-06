from decimal import MAX_EMAX, MIN_EMIN


in_nm_val = int(input())
sum = 0
min = MAX_EMAX
max = MIN_EMIN
in_val = input().split(' ')
for i in range(in_nm_val):
    if(int(in_val[i]) < min): min = int(in_val[i])
    if(int(in_val[i]) > max): max = int(in_val[i])
    sum += int(in_val[i])
print(f'{min} {max} {sum}')