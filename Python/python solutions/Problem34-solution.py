num_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
list1 = []                                     #player-1 choices
list2 = []                                     #player-2 choices
counter1=0
counter2=0
fifteen1 = False
fifteen2 = False
while counter1<4 and fifteen1 == False and counter2<4 and fifteen2 == False:
   if counter1<4 and fifteen1 == False and fifteen2 == False:
      list1_item = int(input("Player number 1,please pick a number from 1 to 9 that hasn't been picked yet : "))
      while list1_item not in num_list:
          list1_item = int(input("this number can't be picked,please pick a different number : "))
      list1.append(list1_item)
      num_list.remove(list1_item)
      if len(list1) > 2:
          if list1[0] + list1[1] + list1[2]==15:
              fifteen1 = True
              print("player number 1 wins!")
      if len(list1) > 3 and fifteen1 == False:
          if list1[1] + list1[2] + list1[3] == 15 or list1[0] + list1[2] + list1[3] == 15 or list1[0] + list1[1] + list1[3] == 15:
              fifteen1 = True
              print("player number 1 wins!")
      counter1 += 1
   if counter2<4 and fifteen1 == False and fifteen2 == False:
      list2_item = int(input("Player number 2,please pick a number from 1 to 9 that hasn't been picked yet : "))
      while list2_item not in num_list:
          list2_item = int(input("this number can't be picked,please pick a different number : "))
      list2.append(list2_item)
      num_list.remove(list2_item)
      if len(list2) > 2:
          if list2[0] + list2[1] + list2[2] == 15:
              fifteen2 = True
              print("player number 2 wins!")
      if len(list2) > 3 and fifteen2 == False:
          if list2[1] + list2[2] + list2[3] == 15 or list2[0] + list2[2] + list2[3] == 15 or list2[0] + list2[1] + list2[3] == 15:
              fifteen2 = True
              print("player number 2 wins!")
      counter2+=1
if fifteen1==False and fifteen2==False:
    print("it's a draw")
