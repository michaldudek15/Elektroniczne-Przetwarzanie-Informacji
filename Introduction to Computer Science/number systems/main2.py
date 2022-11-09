import string

while True:
    inputBase = int(input('choose the base of the system for your input number ( [2, 16] ): '))
    if 1 < inputBase < 17:
        break
    if not str(inputBase).isdigit():
        print("please use numbers from 2 to 16")
        continue

inputNumber = input('what number do you want to convert? ')

while True:
    outputBase = int(input('choose the base of the system you want to convert to: ( [2, 16] ) '))
    if 1 < outputBase < 17:
        break
    else:
        print("please use numbers form 2 to 16")

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
    exit("please use only digits (0-9) or letters {A, B, C, D, E, F}")


for i in range(1, length):
    if ord(inputNumber[length - 1 - i]) > 64:
        currentDigit = ord(inputNumber[length - 1 - i]) - 55
    else:
        currentDigit = int(inputNumber[length - 1 - i])
    if chr(currentDigit) < '65':
        decimalNumber += currentDigit * pow(inputBase, i)
    else:
        currentDigit = int(chr(currentDigit - 55))
        decimalNumber += currentDigit * pow(inputBase, i)


print("result: " + str(decimalNumber))
