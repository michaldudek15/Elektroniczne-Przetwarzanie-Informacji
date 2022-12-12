a = int(input())
b = int(input())
suma = a

if a == 0 or b == 0:
    print("0")

while b != 1:
    suma = suma + a
    b = b - 1

print(suma)
