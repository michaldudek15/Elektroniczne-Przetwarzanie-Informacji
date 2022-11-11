# DONE input check
# DONE converting to decimal
# DONE function that checks if the base is correct
# TO DO check if the number is max A for base 11, B for base 12 ... F for base 16
# TO DO converting from decimal to outputBase

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
    return control_flag


while True:
    inputBase = input('choose the base of the system for your input number: ')
    if baseCheck(inputBase):
        break

while True:
    flag = True
    inputNumber = input('what number do you want to convert? ')
    if valueCheck(inputNumber):
        break

while True:
    outputBase = input('choose the base of the system you want to convert to: ')
    if baseCheck(outputBase):
        break

outputNumber = ''
length = len(inputNumber)
decimalNumber = 0

if 64 < ord(inputNumber[length - 1]) < 71:
    currentDigit = ord(inputNumber[length - 1]) - 55
    decimalNumber = currentDigit * pow(int(inputBase), 0)
elif 47 < ord(inputNumber[length - 1]) < 58:
    currentDigit = int(inputNumber[length - 1])
    decimalNumber = currentDigit * pow(int(inputBase), 0)
else:
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

print("decimal value of your number: " + str(decimalNumber))
