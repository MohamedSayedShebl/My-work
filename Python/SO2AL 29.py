num1=int(input("enter the start number"))
num2=int(input("enter the end number"))
for i in range(num1,num2+1):
   if i%9==0:
      if i%4!=0:
         print(i)
      