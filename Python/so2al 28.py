num=int(input("please input number "))
num2=num
result=0
while num2>0:
   result=result+((num2%10)**3)
   num2=num2//10
print(result)
if result==num:
   print("this number is an armstrong")
else:
   print("this number isn't an armstrong")
