# Print a Rectangle
# Draw a rectangle which has a height of H cm and a width of W cm. Draw a 1-cm square by single '#'.

# Input
# The input consists of multiple datasets. Each dataset consists of two integers H and W separated by a single space.

# The input ends with two 0 (when both H and W are zero).

# Output
# For each dataset, print the rectangle made of H × W '#'.

# Print a blank line after each dataset.

# Constraints
# 1 ≤ H ≤ 300
# 1 ≤ W ≤ 300
# # 
rect = input().split(' ')
h = int(rect[0])
w = int(rect[1])
while h != 0:
    for i in range(0,h):
        if i==0 or i==h-1:
            for j in range(w):
                print('#',end='')
            print('')
        else:
            print('#',end='')
            for j in range(0,w-2):
                print('.',end='')
            print('#',end='')
            print('')
    rect = input().split(' ')
    h = int(rect[0])
    w = int(rect[1])
    if h!=0: print('')