# for floor function
import math

# DONE input check
# DONE converting to decimal
# DONE function that checks if the base is correct
# DONE converting from decimal to outputBase
# DONE check if the number is max A for base 11, B for base 12 ... F for base 16
# DONE make sure converting to binary works fine
# DONE add fractions
# DONE check if fraction is 0 and if int is 0


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
    if len(str(base)) == 0:
        print("the base of the system can only be a number from range " + '\033[94m' + "[2, 16]" + '\033[0m')
        control_flag = False
    elif len(str(base)) == 1:
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
    elif int(base) > 16:
        print("the base of the system can only be a number from range " + '\033[94m' + "[2, 16]" + '\033[0m')
        control_flag = False
    else:
        print("the base of the system can only be a number from range " + '\033[94m' + "[2, 16]" + '\033[0m')
        control_flag = False
    return control_flag


def valueCheck(value):
    control_flag = True
    if len(str(value)) == 0:
        print("input was empty")
        control_flag = False
    else:
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


outputNumber = ""
first_time = True


def convert(dec):
    global outputNumber, first_time
    if dec == 0 and first_time:
        print("integer was 0 from beginning")
        outputNumber = "00"
        return
    elif dec >= 1:
        first_time = False
        convert(dec // int(outputBase))
    next_digit = str(dec % int(outputBase))
    if 0 <= int(next_digit) <= 9:
        outputNumber += next_digit
    elif 10 <= int(next_digit) <= 16:
        outputNumber += chr(int(next_digit) + 55)


outputFraction = ""
precision = 10


def convertFraction(frac):
    global precision, outputFraction
    if frac == 0:
        outputFraction = "0"
        return
    while precision:
        if frac == 0:
            break
        else:
            # print(frac * int(outputBase))
            floor = math.floor(frac * int(outputBase))
            if floor < 10:
                next_digit = floor
            else:
                next_digit = chr(int(floor) + 55)
            outputFraction += str(next_digit)
            # print("floor: " + str(floor))
            remainder = (frac * int(outputBase)) - floor
            # print("remainder: " + str(remainder))
            frac = remainder
            precision -= 1


while True:
    inputBase = input('choose the base of the system for your input number: ')
    if baseCheck(inputBase):
        break

while True:
    inputNumber = input('type the integer value of the number you want to convert: ')
    if valueCheck(inputNumber):
        break

while True:
    inputFraction = input('type the fractional value of the number you want to convert: ')
    if valueCheck(inputFraction):
        break

while True:
    outputBase = input('choose the base of the system you want to convert to: ')
    if baseCheck(outputBase):
        break

# convert input values to decimal
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

fractionLength = len(inputFraction)

if 64 < ord(inputFraction[0]) < 71:
    currentDigit = ord(inputFraction[0]) - 55
    fractionalPart = currentDigit * pow(int(inputBase), -1)
elif 47 < ord(inputFraction[0]) < 58:
    currentDigit = int(inputFraction[0])
    fractionalPart = currentDigit * pow(int(inputBase), -1)
else:
    fractionalPart = 0
    exit()

for i in range(1, fractionLength):
    if ord(inputFraction[i]) > 64:
        currentDigit = ord(inputFraction[i]) - 55
    else:
        currentDigit = int(inputFraction[i])
    if chr(currentDigit) < '65':
        fractionalPart += currentDigit * pow(int(inputBase), -(i + 1))
    else:
        currentDigit = int(chr(currentDigit - 55))
        fractionalPart += currentDigit * pow(int(inputBase), -(i + 1))

convert(decimalNumber)
convertFraction(fractionalPart)

# print("output integer: " + str(outputNumber))
# print("output fraction: " + str(outputFraction))

print("converted number: " + '\033[93m' + outputNumber[1:] + "." + outputFraction + '\033[0m')