inp = open('king.in')
outp = open('king.out', 'w')

months = [31,28,31,30,31,30,31,31,30,31,30,31]
def convert(d, m, y):
    return 365 * y + sum(months[:m]) + d

decease = convert(*map(int, inp.readline().split()))
n = int(inp.readline())

heir = -2
heir_age = 1e9

for son in range(n):
    son_age = decease -  convert(*map(int, inp.readline().split()))
    if son_age >= 18 * 365 and son_age < heir_age:
        heir_age = son_age
        heir = son

print(heir+1, file=outp)