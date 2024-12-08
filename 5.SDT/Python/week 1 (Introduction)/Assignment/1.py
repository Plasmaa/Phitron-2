# Link - https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/S?fbclid=IwAR1qi6o8WBDOrdzcZ--U5YO_40SSQmmLbZ8jggB6CFIRqog1ukVL_Z2wK2s

def max_split(S):
    L = 0
    R = 0
    result = []
    start = 0

    for i in range(len(S)):
        if S[i] == 'L':
            L += 1
        else:
            R += 1

        if L == R:
            result.append(S[start:i+1])
            start = i + 1
            L = R = 0
    
    print(len(result))
    for substring in result:
        print(substring)

S = input()

max_split(S)
