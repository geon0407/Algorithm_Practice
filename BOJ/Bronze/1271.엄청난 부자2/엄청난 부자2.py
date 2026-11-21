n, m = input().split()
m = int(m)
ans = ''
num = ''
for a in n :
    num += a
    num = int(num)
    ans += str(num // m)
    num = str(num % m)
print(int(ans))
print(num)