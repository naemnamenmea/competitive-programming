import sys

sys.stdin = open("java2016.in", "r")
sys.stdout = open("java2016.out", "w")

def f(n, k):
    if n == 1:
        print("{} = y".format(chr(k)))
        return

    f(n // 2, k + 1)
    if n % 2 == 0:
        print("{} = {} + {}".format(chr(k), chr(k+1), chr(k+1)))
    else:
        print("{} = {} + {} + y".format(chr(k), chr(k+1), chr(k+1))) 

n = int(input())

if n == 0:
    print("? / ? / ?")
    sys.exit(0)

print("x = ?", "y = x / x", sep='\n')
f(n, ord('a'))
print('a')