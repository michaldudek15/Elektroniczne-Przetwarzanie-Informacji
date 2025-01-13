"""
Proszę napisać funkcję **get_values(iterator, n)**, zwracającą listę _n_ kolejnych wartości pobranych z iteratora. 
Gdy wartości się skończą, należy odpowiednio skrócić zwracaną listę. 

Funkcja powinna działać, jak poniżej:

```
>>> i = iter(range(10))
>>> get_values(i, 3)
[0, 1, 2]
>>> get_values(i, 5)
[3, 4, 5, 6, 7]
>>> get_values(i, 4)
[8, 9]
>>> get_values(i, 4)
[]
```
"""

def get_values(iterator, n):
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