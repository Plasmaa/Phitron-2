# link - https://atcoder.jp/contests/arc087/tasks/arc087_a

n = int(input())
a = list(map(int, input().split()))

freq = {}

for num in a:
    if num in freq:
        freq[num] += 1
    else:
        freq[num] = 1

removals = 0

for num, count in freq.items():
    if count > num:
        removals += count - num
    elif count < num:
        removals += count

print(removals)
