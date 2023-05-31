inp = open("king.in")
outp = open("king.out", 'w')

def isAdult(d_0, d):
    if d_0[2] - d[2] > 18:
        return True
    elif d_0[2] - d[2] == 18:
        if d_0[1] < d[1]:
            return False
        elif d_0[1] == d[1]:
            if d_0[0] < d[0]:
                return False
            else:
                return True
        else:
            return True
    else:
        return False

date_0 = [int(x) for x in inp.readline().split()]
amount = int(inp.readline())

dates1 = [] # [ [28, 2, 1999, 0], [22, 7, 1995, 1], ... ]
maxYear = 0
for i in range(amount):
    date_i = [int(x) for x in inp.readline().split()] + [i]
    if date_0[2] - date_i[2] >= 18:
        dates1.append(date_i)
        if date_i[2] > maxYear:
            maxYear = date_i[2]

resultSon = -2
# здесь убираем из dates те, которым нет 18
dates = []
for d in dates1:
    if isAdult(date_0, d):
        dates.append(d)

resY = []
maxMonth = 0
for d in dates:
    if d[2] == maxYear:
        resY.append(d)
        if d[1] > maxMonth:
            maxMonth = d[1]

# теперь в res только люди, которым уже 18 или пока 17, и у которых минимальный год рождения
resM = []
maxDay = 0
for d in resY:
    if d[1] == maxMonth:
        resM.append(d)
        if d[0] > maxDay:
            maxDay = d[0]

for d in resM:
    if d[0] == maxDay:
        print(d)
        resultSon = d[3]

outp.write(str(resultSon + 1))
inp.close()
outp.close()