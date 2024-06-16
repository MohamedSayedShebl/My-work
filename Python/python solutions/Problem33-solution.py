list1 = []
size_of_list1 = int(input("please input size of list 1:"))
for index in range(size_of_list1):
    item = int(input("input item number "+str(index+1)+" in list 1:"))
    list1.append(item)
ascendingly=True
descendingly=True
not_sorted=False
for num in range(len(list1)-1):
    if list1[num]>list1[num+1]:
        ascendingly=False
    if list1[num]<list1[num+1]:
        descendingly=False
if ascendingly==False and descendingly==False:
    not_sorted=True
if ascendingly==True:
    print("1")
elif descendingly==True:
    print("-1")
elif not_sorted==True:
    print("0")