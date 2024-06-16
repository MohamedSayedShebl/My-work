array=["","","","","","","","","",""]
for i in range(10):
  array[i]=(input("input item number "+str(i)+" in array "))
item_eliminated=int(input("input index of element you want deleted "))
array[item_eliminated]=""
print(array)