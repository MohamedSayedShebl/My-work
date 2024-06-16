x=int(input("please input x in format (x 'operator' y = z):"))
y=int(input("please input y in format (x 'operator' y = z):"))
z=int(input("please input z in format (x 'operator' y = z):"))

if x+y==z:
    print("the operator is +")
    print(str(x)+"+"+str(y)+"="+str(z))
if x-y==z:
    print("the operator is -")
    print(str(x)+"-"+str(y)+"="+str(z))
if x/y==z:
    print("the operator is /")
    print(str(x)+"/"+str(y)+"="+str(z))
if x//y==z:
     print("the operator is //")
     print(str(x)+"//"+str(y)+"="+str(z))
if x%y==z:
    print("the operator is %")
    print(str(x)+"%"+str(y)+"="+str(z))
if x*y==z:
    print("the operator is *")
    print(str(x)+"*"+str(y)+"="+str(z))
if x**y==z:
    print("the operator is **")
    print(str(x)+"**"+str(y)+"="+str(z))
else:
    print("invalid equation,no operator found")