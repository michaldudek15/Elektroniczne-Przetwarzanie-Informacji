n, p = 60, 37
# ma działać dla dowolnych n i p (bez input, tylko zmiana zmiennych w kodzie)

# Wypisz dzielniki n
print([i for i in range(1, n + 1) if n % i == 0])
# Wypisz dzielniki p
print([i for i in range(1, p + 1) if p % i == 0])
