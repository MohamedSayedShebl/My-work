n=int(input("please enter the number you want the factorial of "))
fact=1
count=1
if n==0:
    print("The factorial of "+str(n)+" is "+str(fact))
else:
    while count!=n:
        count+=1
        fact=fact*count
print("The factorial of "+str(n)+" is "+str(fact))

