# potęgowanie elementów listy
lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
potęgi = list(map(lambda x: x**2, lista))
print(potęgi)

# wybranie tylko liczb pierwszych z listy
def znajdzPierwsze(lista):
    pierwsze = lambda n: all(n % i != 0 for i in range(2, int(n**0.5) + 1)) if n > 1 else False
    return list(filter(pierwsze, lista))
print(znajdzPierwsze(lista))

# oblicza wartość funkcji kwadratowej w podanym iksie
kwadratowa = lambda x, a=1, b=0, c=0: a * x**2 + b * x + c
print(kwadratowa(9, 2, 7, 4)) 