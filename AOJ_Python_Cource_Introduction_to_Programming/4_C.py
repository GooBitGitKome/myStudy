while True:
    in_val = input().split(' ')
    a = int(in_val[0])
    op = in_val[1]
    b = int(in_val[2])
    if(op == '?'): break
    if(op == '+'): print(a+b)
    if(op == '-'): print(a-b)
    if(op == '*'): print(a*b)
    if(op == '/'): print(int(a/b))