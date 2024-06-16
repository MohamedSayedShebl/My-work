list1 = []
list2 = []
size_of_list1 = int(input("please input size of list 1:"))
size_of_list2 = int(input("please input size of list 2:"))
for index in range(size_of_list1):
    item = int(input("input item number "+str(index+1)+" in list 1:"))
    list1.append(item)
for index in range(size_of_list2):
    item = int(input("input item number " + str(index+1) + " in list 2:"))
    list2.append(item)


def check_lists(list1, list2):
    sum1 = 0
    sum2 = 0
    for index in range(len(list1)):
        sum1 = sum1 + list1[index]
    for index in range(len(list2)):
        sum2 = sum2 + list2[index]
    if sum1 == sum2:
        print("Lists are equal = True")
    else:
        print("Lists are equal = False")


check_lists(list1, list2)
