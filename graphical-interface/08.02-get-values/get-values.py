def get_values(iterator, n):
    """
    funkcja zwraca listę kolejnych wartości pobranych z iteratora
    """
    lista = []
    for x in range(n):
        value = next(iterator, None)
        if value is None:
            break
        lista.append(value)
    return lista

i = iter(range(10))
print(get_values(i, 3))
print(get_values(i, 5))
print(get_values(i,4))
print(get_values(i,4))