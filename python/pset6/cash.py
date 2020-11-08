validInput = False
dollars = 0

# validate input 
while validInput == False:
    try:
        dollars = int(input("Change owed: "))
        if dollars > 0:
            goodinput = True
            break
    except ValueError:
        continue


coins = 0
cents = round(dollars * 100, 0)

while (cents > 0):
    if (cents >= 25):
        cents -= 25
        coins += 1
    elif (cents >= 10):
        cents -= 10
        coins += 1
    elif (cents >= 5):
        cents -= 5
        coins += 1
    else:
        cents -= 1
        coins += 1

print(f"you are owed {coins} coins")