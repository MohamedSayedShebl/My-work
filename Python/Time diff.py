s1=input("input the earlier time in the day in this format : hr:min:sec ")
s2=input("input the later time in the day in this format : hr:min:sec ")

def removeColon(s):
    if (len(s) == 7):
        s = s[:1] + s[2:4] + s[5:]

    if (len(s) == 8):
        s = s[:2] + s[3:5] + s[6:]

    return int(s)



def diff(s1, s2):

    time1 = removeColon(s1)
    time2 = removeColon(s2)


    hourDiff = time2 // 10000 - time1 // 10000 -1

    time1 = time1 % 10000
    time2 = time2 % 10000

    minDiff = time2 // 100 + (60 - time1 // 100) -1

    print(minDiff)

    secDiff = time2 % 100 + (60 - time1 % 100)

    print(secDiff)
    if (secDiff >= 60):
        minDiff += 1
        secDiff = secDiff - 60

    if (minDiff >= 60):
        hourDiff += 1
        minDiff = minDiff - 60
    res = str(hourDiff) + ":" + str(minDiff) + ":" + str(secDiff)

    print (res)

diff(s1,s2)