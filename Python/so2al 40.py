size=int(input("please input the size of the sequence:"))
counter=1
result=0
fibonacci=[]
if size==1:
  fibonacci.append(1)
if size==2:
    fibonacci.append(1)
    fibonacci.append(1)
if size>2:
    fibonacci.append(1)
    fibonacci.append(1)
    while counter<size:
        result=fibonacci[counter]+fibonacci[counter-1]
        fibonacci.append(result)
        counter=counter+1
fibonacci.remove(fibonacci[len(fibonacci)-1])
print(fibonacci)