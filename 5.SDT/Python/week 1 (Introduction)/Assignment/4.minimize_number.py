# link - https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/P

n = int(input())
a = list(map(int, input().split()))

operations = 0

while all(num % 2 == 0 for num in a):
    a = [num // 2 for num in a]
    operations += 1

print(operations)
