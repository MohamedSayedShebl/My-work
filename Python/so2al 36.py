word=input("Please input your string ")
Result=""
length=int(len(word))-1
while length>=0 :
    Result=Result+word[length]
    length=length-1
if Result==word:
    print("this word is palindrome")
else:
    print("this word isn't palindrome")