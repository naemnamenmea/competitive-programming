import sys

sys.stdin = open("java2016.in")
sys.stdout = open("java2016.out", "w")

n = int(input())
if n == 0:
    print("? / ? / ?")
    exit(0)
# print("a = ? max ? max ? max ? max ? max ? max ? max ? max ?")
#  print("z = (a max a max a max a max a max a )/a")  # 1
print("a = ? max ? max ? max ? max ?")
print("z = (a max a max a max a max a max a) / a")  # 1z
print("x = (z max z max z max z max z max z)")  # 1z

print("b = x max x max x")
# print("b = (z max z max z)/z")
dic = [""] * 10
dic[0] = "b"
for i in range(1, 8):
    char = chr(ord("c") + i - 1)
    dic[i] = char
    # print(2 ** i, char)
    print("%s = %s + %s" % (char, dic[i - 1], dic[i - 1]))
# (a max a) / a +
bn = bin(n)[2:]
jp = 0
ans = []
for i in range(len(bn) - 1, -1, -1):

    if bn[i] == "1":
        ans.append(dic[jp])
    jp += 1
print(" + ".join(ans))
