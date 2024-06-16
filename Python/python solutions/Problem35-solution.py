from math import*
num_of_coins = int(input("please input number of coins you want : "))
turn = 2
while num_of_coins > 0:
    if turn == 2:
        turn = 1
    elif turn == 1:
        turn = 2
    move = int(input("player number "+str(turn)+", pick a squared number : "))
    while sqrt(move) % 1 != 0:
        move = int(input("the number you picked isn't squared, pick a squared number : "))
    while move > num_of_coins:
        move = int(input("the number you picked is bigger than the number of coins available, pick a suitable number of coins : "))
    num_of_coins -= move
    print("number of coins remaining = "+str(num_of_coins))
print("player number "+str(turn)+" won!")
