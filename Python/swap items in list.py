List=["","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",]
for i in range(50):
  List[i]=(input("input item number "+str(i)+" in list "))
store=""
counter=0
while counter<50:
    store=List[counter]
    List[counter]=List[counter+1]
    List[counter+1]=store
    counter=counter+2
print(List)
