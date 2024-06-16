dictionary={
    "alexandria":"218 km",
    "asyut":"389 km",
    "port said":"198 km",
    "luxor":"657 km",
    "tanta":"94 km",
    "banha":"58 km",
    "suez":"140 km",
    "sharm el sheikh":"506 km",
    "hurghada":"463 km",
    "aswan":"872 km"
}
choices = [1,2,3]
move = int(input("input 1 for all informations on the cities in the dictionary, input 2 for an enquiry about a certain city, input 3 to add your own information: "))
while move not in choices:
    move = int(input("please select an input from the inputs stated above: "))
if move == 1:
   print(dictionary)
elif move == 2:
   city = input("please enter the name of the city you would like to know about: ")
   if city not in dictionary:
     print("sorry, the city you chose is not in the dictionary. If you would like you can add it and it's formation by inputting 3 at the start")
   print(dictionary[city])
elif move == 3:
    name_of_city = input("please enter the name of the city you would like to add to the dictionary: ")
    distance = input("please enter the distance of the city you would like to add to the dictionary to cairo: ")
    dictionary[name_of_city]=distance
    print("thank you for providing the dictionary with such valuable information!")
    print(dictionary)