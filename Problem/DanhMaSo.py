def backtrack(n, used, s) :
    if len(s) == n * 2:
        print(s)
        return
    
    if len(s) < n:
        for i in range (n):
            if not used[i]:
                used[i] = True
                backtrack(n, used, s + chr(ord('A') + i))
                used[i] = False
        return
    
    for i in range(n):
        backtrack(n, used, s + str(i + 1))

n = int(input())
used = [False] * n
backtrack(n, used, "")
