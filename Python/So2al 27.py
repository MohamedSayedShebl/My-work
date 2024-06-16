num=int(input("please input number "))
result=0
while num>0:
   result=result+(num%10)
   num=num//10
print(result)