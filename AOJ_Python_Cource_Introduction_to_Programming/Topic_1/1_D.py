
inf = int(input())
h = inf / 60 / 60
m = (h - int(h)) * 60
s = (m - int(m)) * 60
print(f'{int(h)}:{int(m)}:{round(s)}')