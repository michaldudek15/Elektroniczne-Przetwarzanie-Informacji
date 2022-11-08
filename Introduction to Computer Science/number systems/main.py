inputBase = int(input('choose the base of the system for your input number ( [2, 16] ): '))
inputNumber = input('what number do you want to convert? ')
outputBase = int(input('choose the base of the system you want to convert to: ( [2, 16] ) '))
outputNumber = ''
length = len(inputNumber)

if inputNumber[length - 1] > '64':
    currentDigit = int(inputNumber[length - 1] - '55')

decimalNumber = int(inputNumber[length - 1]) * pow(int(inputBase), 0)

for i in range(1, length):
    currentDigit = int(inputNumber[length - 1 - i])
    if chr(currentDigit) < '65':
        decimalNumber += currentDigit * pow(inputBase, i)
    else:
        currentDigit = int(chr(currentDigit - 55))
        decimalNumber += currentDigit * pow(inputBase, i)

print("result: " + str(decimalNumber))
