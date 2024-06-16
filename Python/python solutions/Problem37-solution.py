first_name = input("input file name")
list1 = list(open(first_name))
second_file = open('second text.txt', 'w')
for line in reversed(list1):
    second_file.write(line+"\n")
second_file.close()