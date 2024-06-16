message = input("type in your message: ")
encrypted_message = ""
def create_list(sentence):
    message_list = []
    for i in range(len(sentence)):
        message_list.append(sentence[i])
    return message_list
message_list = create_list(message)
letter_num = 0
while letter_num != len(message_list):
    if ord(message_list[letter_num]) == 32:
        message_list.remove(message_list[letter_num])
    letter_num += 1

for letter in range(len(message_list)):
        message_list[letter] = chr(ord(message_list[letter])+1)
        encrypted_message = encrypted_message+message_list[letter]
print(encrypted_message)
reversed_message = ""
for letter in range(len(message_list)):
        message_list[letter] = chr(ord(message_list[letter])-1)
        reversed_message = reversed_message+message_list[letter]
print(reversed_message)
