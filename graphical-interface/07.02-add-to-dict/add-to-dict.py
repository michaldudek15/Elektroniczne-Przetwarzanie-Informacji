def add_to_dict(key, value, d=None):
    """
    funkcja dodaje parę klucz-wartość do słownika lub tworzy słownik z nową parą klucz-wartość, jeśli trzeci argument nie został podany;
    funkcja zwraca słownik z dodaną parą klucz-wartość
    """
    if d is None:
        d = {}
    d[key] = value
    return d


print(add_to_dict(1, 2))
print(add_to_dict('a', 'b'))
print(add_to_dict('c', 'd', {5: 6}))

d = {'x': 'y'}
print(add_to_dict(10, 20, d))
print(d)