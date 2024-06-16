array=[]
array_size=int(input("please input array length:"))
for i in range(array_size):
     item=input("input item "+str(i)+" in array:")
     array.append(item)
start=int(input("input index of start of segment:"))
end=int(input("input index of end of segment:"))
removed=int(input("input index of item you want removed from segment:"))
if removed>end:
     print("error:index of removed item not in segment")
elif removed<start:
     print("error:index of removed item not in segment")
else:
    array.remove(array[removed])
    print(array[start:end])