decimal=(input("please input the decimal number "))

binary_list=["","","","","","","",""]
if decimal[0]=="-":
    negative=True
    print(str(negative))
else:
    negative=False
    print("negative = "+str(negative))
def remove_negative(decimal):
   if decimal[0]=="-":
      decimal=decimal[1:]
   return int(decimal)
decimal=remove_negative(decimal)
print(decimal)
binary=""
if decimal>127:
    print("your number can't be represented in signed 8 bits")
else:
    while decimal>0:
        if decimal%2==0:
            binary=binary+"0"
        elif decimal%2!=0:
            binary=binary+"1"
        decimal = decimal // 2
        print("decimal= "+str(decimal))
        print("binary = "+binary)
    for digit in range(len(binary)):
        binary_list[digit]=binary[digit]
    print(binary_list)
    for digit in range(len(binary_list)):
        if binary_list[digit]=="":
            binary_list[digit]="0"
    print(binary_list)
    binary_list.reverse()
    print(binary_list)
    binary = ""
    if negative==True:                            #the negative format is one's complement
       for digit in range(len(binary_list)):
           if binary_list[digit]=="1":
               binary_list[digit]="0"
           elif binary_list[digit]=="0":
                binary_list[digit]="1"
    print(binary_list)


    for digit in range(len(binary_list)):
        binary = binary + binary_list[digit]
    print(binary)