"""
Proszę napisać funkcję **sequence_gen()**, generującą kolejne wyrazy dowolnego ciągu
danego przy pomocy definicji rekurencyjnej. Dane jest **n** pierwszych wyrazów ciągu
i funkcja obliczająca kolejny wyraz na podstawie _n_ poprzednich. 

Funkcja **sequence_gen()** przyjmuje jako kolejne argumenty: funkcję obliczającą 
kolejny wyraz na podstawie _n_ poprzednich, a następnie _n_ początkowych wyrazów ciągu. 
Funkcja obliczająca kolejny wyraz przyjmuje _n_ argumentów i zwraca kolejny wyraz. 
Wyrazy nie muszą być liczbami. Funkcja nie powinna tworzyć listy wszystkich kolejnych wyrazów. 

Podczas oceny można się spodziewać: polecenia zdefiniowania nowego ciągu opisanego 
przez prowadzącego, polecenia użycia wyrażenia lambda i pytań sprawdzających stopień 
zrozumienia własnego rozwiązania. 

Przykład użycia funkcji pokazano poniżej:

# przykład użycia: ciąg Fibonacciego
 def next_fibonacci(a, b):
     return a + b

 g = sequence_gen(next_fibonacci, 0, 1)
 next(g)
0
 next(g)
1
 next(g)
1
>>> next(g)
2
>>> next(g)
3

# przykład użycia: ciąg liczb parzystych
>>> def next_even(a):
...     return a + 2
...
>>> g = sequence_gen(next_even, 0)
>>> next(g)
0
>>> next(g)
2
>>> next(g)
4
>>> next(g)
6

# oczywiście można użyć lambdy (ciąg "Tribonacciego")
>>> g = sequence_gen(lambda a,b,c: a+b+c, 0, 0, 1)
>>> next(g)
0
>>> next(g)
0
>>> next(g)
1
>>> next(g)
1
>>> next(g)
2
>>> next(g)
4
>>> next(g)
7

# ciąg nienumeryczny
>>> g = sequence_gen(lambda a,b: a+b, 'a', 'b')
>>> next(g)
'a'
>>> next(g)
'b'
>>> next(g)
'ab'
>>> next(g)
'bab'
>>> next(g)
'abbab'
>>> next(g)
'bababbab'
>>> next(g)
'abbabbababbab'
>>> next(g)
'bababbababbabbababbab'
```
"""

def sequence_gen(function, *args):
    previous = list(args)

    for value in previous:
        yield value

    while True:
        next = function(*previous)
        yield next
        previous.pop(0)
        previous.append(next)

def next_fib(a, b):
    return a + b

def next_even(a):
    return a + 2

fibonacci = sequence_gen(next_fib, 0, 1)
even = sequence_gen(next_even, 0)
tribonacci = sequence_gen(lambda a,b,c: a+b+c, 0, 0, 1)
nums = sequence_gen(lambda a,b: a+b, 'a', 'b')


for i in range(15):
    print(next(fibonacci))