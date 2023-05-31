#!/usr/bin/python3

import sys
sys.stdin = open("java2016.in", "r")
sys.stdout = open("java2016.out", "w")

n = int(input())

if n == 0:
    print('? / ? / ?')
    exit(0)

k = 18

last = '?'
for i in range(k):
    print(chr(ord('a') + i) + '=' + last + ' max ' + last)
    last = chr(ord('a') + i)

print(chr(ord('a') + k) + "=(" + last + ")/(" + chr(ord('a') + k - 2) + ")")
last = chr(ord('a') + k)

for j in range(k + 1, k + 8):
    print(chr(ord('a') + j) + '=(' + last + ')+(' + last + ')')
    last = chr(ord('a') + j)
    
p = k

s = ''
for t in range(8):
    if ((n >> t) & 1):
        if len(s):
            s += "+"
        s += "(" + chr(ord('a') + p + t) + ")"
print(s)