word=input("please input your string:")
digits=0
letters=0
for i in range(len(word)):
   if ord(word[i]) in range(65,91):
      letters+=1
   if ord(word[i]) in range(97, 123):
       letters+=1
   if ord(word[i]) in range(48, 58):
       digits += 1
print("digits="+str(digits))
print("letters="+str(letters))
