num=int(input("please input your number "))
for i in range(int(num/2)):
    if num%(i+1)==0:
        print(i+1)
print(num)