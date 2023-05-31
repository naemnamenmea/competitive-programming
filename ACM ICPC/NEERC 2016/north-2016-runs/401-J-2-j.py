import sys

sys.stdin = open("java2016.in", "r")
sys.stdout = open("java2016.out", "w")

def f(n, k):
    if n == 1:
        print("{} = i".format(chr(k)))
        return

    f(n // 2, k + 1)
    if n % 2 == 0:
        print("{} = {} + {}".format(chr(k), chr(k+1), chr(k+1)))
    else:
        print("{} = {} + {} + i".format(chr(k), chr(k+1), chr(k+1))) 

n = int(input())

if n == 0:
    print("? / ? / ?")
    sys.exit(0)

print('z = ? max ?')
for i in reversed(range(ord('j'), ord('z'))):
    print("{} = {} max {}".format(chr(i), chr(i+1), chr(i+1)))
print('i = j / j')

f(n, ord('a'))
print('a')