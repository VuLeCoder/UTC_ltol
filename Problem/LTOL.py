n = int(input())
for i in range(1, n + 1):
    if i % 2 == 1:
        print(i)
    else:
        print('L', end='')
        if i % 4 == 0:
            print('T', end='')
        if i % 8 == 0:
            print('O', end='')
        if i % 16 == 0:
            print('L', end='')
        print()
