# DONE input check
# DONE converting to decimal
# DONE function that checks if the base is correct
# DONE converting from decimal to outputBase
# DONE check if the number is max A for base 11, B for base 12 ... F for base 16

# 2  -> {0, 1}                                              -> {48, 49}
# 3  -> {0, 1, 2}                                           -> {48,49, 50}
# 4  -> {0, 1, 2, 3}
...
# 10 -> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}                      -> {48, 49, 50, 51, 52, 53, 54, 55, 56, 57}
# 11 -> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A}                   -> {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65}
...
# 15 -> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E}       -> {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67,
#                                                               68, 69}
# 16 -> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}    -> {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65,
#                                                               66, 67, 68, 69, 70} 54 + 16


def baseCheck(base):
    control_flag = True
    if len(str(base)) == 1:
        if ord(str(base)[0]) < 50 or ord(str(base)[0]) > 57:
            print("the base of the system can only be a number from range " + '\033[94m' + "[2, 16]" + '\033[0m')
            control_flag = False
    elif len(str(base)) == 2:
        if ord(str(base)[0]) < 49 or ord(str(base)[0]) > 57:
            print("the base of the system can only be a number from range " + '\033[94m' + "[2, 16]" + '\033[0m')
            control_flag = False
        elif ord(str(base)[1]) < 48 or ord(str(base)[1]) > 54:
            print("the base of the system can only be a number from range " + '\033[94m' + "[2, 16]" + '\033[0m')
            control_flag = False
    else:
        print("the base of the system can only be a number from range " + '\033[94m' + "[2, 16]" + '\033[0m')
        control_flag = False
    return control_flag


def valueCheck(value):
    control_flag = True
    for j in range(len(value)):
        if (ord(value[j]) > 70 or ord(value[j]) < 48) or (57 < ord(value[j]) < 65):
            print("this character is not allowed: " + "\033[91m" + str(value[j]) + "\033[0m")
            control_flag = False
        elif int(inputBase) < 10:
            if ord(value[j]) < 48 or ord(value[j]) > (47 + int(inputBase)):
                print("this character is not allowed for this input base: " + "\033[91m" + str(value[j]) + "\033[0m")
                control_flag = False
        elif int(inputBase) >= 10:
            if ord(value[j]) < 48 or ord(value[j]) > (54 + int(inputBase)):
                print("this character is not allowed for this input base: " + "\033[91m" + str(value[j]) + "\033[0m")
                control_flag = False
    return control_flag


while True:
    inputBase = input('choose the base of the system for your input number: ')
    if baseCheck(inputBase):
        break

while True:
    inputNumber = input('what number do you want to convert? ')
    if valueCheck(inputNumber):
        break

while True:
    outputBase = input('choose the base of the system you want to convert to: ')
    if baseCheck(outputBase):
        break

outputNumber = ''
length = len(inputNumber)

if 64 < ord(inputNumber[length - 1]) < 71:
    currentDigit = ord(inputNumber[length - 1]) - 55
    decimalNumber = currentDigit * pow(int(inputBase), 0)
elif 47 < ord(inputNumber[length - 1]) < 58:
    currentDigit = int(inputNumber[length - 1])
    decimalNumber = currentDigit * pow(int(inputBase), 0)
else:
    decimalNumber = 0
    exit()

for i in range(1, length):
    if ord(inputNumber[length - 1 - i]) > 64:
        currentDigit = ord(inputNumber[length - 1 - i]) - 55
    else:
        currentDigit = int(inputNumber[length - 1 - i])
    if chr(currentDigit) < '65':
        decimalNumber += currentDigit * pow(int(inputBase), i)
    else:
        currentDigit = int(chr(currentDigit - 55))
        decimalNumber += currentDigit * pow(int(inputBase), i)

# print("decimal value of your number: " + str(decimalNumber))

# 1. divide by base
# 2. remainder is the youngest digit
# 3. keep doing that until your number is 0


while decimalNumber > 0:
    nextDigit = (decimalNumber % int(outputBase))
    if (decimalNumber % int(outputBase)) > 9:
        nextDigit = chr(nextDigit+55)
    decimalNumber = int(decimalNumber) // int(outputBase)

    # print("next digit: " + str(nextDigit))
    # print("remainder: " + str(int(decimalNumber)))

    outputNumber = str(nextDigit) + str(outputNumber)

print("output number: " + '\033[93m' + outputNumber + '\033[0m')
