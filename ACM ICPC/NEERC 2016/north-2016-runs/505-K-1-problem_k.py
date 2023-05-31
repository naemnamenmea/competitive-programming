def getDate(nums):
    return int(nums[0]), int(nums[1]), int(nums[2])

def greaterOrEqual(date1, date2):
    (day1, month1, year1) = date1
    (day2, month2, year2) = date2

    (day_diff, month_diff, year_diff) = (day2 - day1, month2 - month1, year2 - year1)
    if year_diff < 0:
        return True
    elif year_diff == 0:
        if month_diff < 0:
            return True
        elif month_diff == 0:
            if day_diff < 0:
                return True
    return False

in_file = open('king.in', 'r')
out_file = open('king.out', 'w')

king = getDate(in_file.readline().split(' '))
(king_day) = king
kids_n = int(in_file.readline())

kids = []
for i in range(kids_n):
    kids.append(getDate(in_file.readline().split(' ')))

poss_kids = []
for i in range(len(kids)):
    (day, month, year) = kids[i]
    if greaterOrEqual(king, (day, month, year + 18)):
        poss_kids.append((i + 1, kids[i]))

s = list(sorted(poss_kids))

if len(s) > 0:
    (ind, k) = s[-1]
    out_file.write("%i" % ind)
else:
    out_file.write("-1")







