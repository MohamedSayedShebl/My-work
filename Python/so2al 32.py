word=input("please enter your word ")
word_list=[]
for letter in word:
    word_list.append(letter)
for i in range(len(word_list)):
    word_list[i]=chr(ord(word_list[i])-32)
word=""
for i in range(len(word_list)):
    word=word+word_list[i]
print(word)