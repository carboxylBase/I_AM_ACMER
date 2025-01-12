import sys
# sys.stdin = open('input.txt','r')

def solve():
    s = input()
    for i in s[::-1]:
        if i == 'p':
            print('q',end='')
        elif i == 'q':
            print('p',end='')
        else:
            print('w',end='')

    print()
    return

_ = int(input())
while _ > 0:
    solve()
    _ -= 1