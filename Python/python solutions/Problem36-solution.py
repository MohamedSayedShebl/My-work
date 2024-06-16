first_name=input("input first file name")
list1=list(open(first_name))
second_name=input("input second file name")
second_file=open(second_name, 'w')
for line in list1:
    second_file.write(line)
second_file.close()