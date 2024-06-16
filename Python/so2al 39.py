LOW=int(input("please input lower number:"))
HIGH=int(input("please input higher number:"))
SUM=0
for i in range(LOW,HIGH+1):
    SUM+=i
print(SUM)