n = int(input())
ar = list(map(int,input().split()))
pref = [[0]*32 for i in range(n)]

for i in range(len(ar)):
    for j in range(32):
        pref[i][j] = (ar[i] >> j)&1
for i in pref:
    print(i)
for i in range(32):
    run = 0
    for j in range(1,n):
        pref[j][i] += pref[j-1][i]
# for i in pref:
#     print(i)
q = int(input())
for _ in range(q):
    l,r = map(int,input().split())
    ans = 0
    for i in range(31,-1,-1):
        x = pref[r][i] - pref[l-1][i]
        if x == (r-l+1):
            ans = ans | (1 << i)
    print(ans)
