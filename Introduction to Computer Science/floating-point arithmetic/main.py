# 1. pobierz liczbę
# 2. zamien liczbę na dwójkowy
# 3. znormalizuj z cechą dziesiętną
# 4. zamien cechę dziesiętną na binarną
# 5. wypisz mantysę UZP
# 6. wypisz cechę ODW
# 7. wypisz cały rejestr

significandSign = 0
significand = [0, 0, 0, 0, 0, 0, 0, 0, 0]
significandSize = len(significand)

exponentSign = 0
exponent = [0, 0, 0, 0]
exponentSize = len(exponent)

number = int(input('type your number: '))

if number < 0:
    significandSign = 1

binaryNumber = bin(abs(number))[2:]

print("number" + str(number))
print("binary number" + binaryNumber)
print("length of binary number" + str(len(binaryNumber)))
print("length of signifiand" + str(significandSize))

cut = len(binaryNumber) - significandSize
print("how much to cut" + str(cut))

normalizedBinary = binaryNumber[:len(binaryNumber) - cut]

print("normalized binary" + str(normalizedBinary))

if len(binaryNumber) < significandSize:
    for i in range(len(binaryNumber)):
        significand[significandSize - i - 1] = binaryNumber[len(binaryNumber) - i - 1]

print(significand)
