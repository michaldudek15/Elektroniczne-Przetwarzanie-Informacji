"""
Klasa _SquaresGen_ umożliwia tylko jednokrotną iterację, ponieważ metoda _\_\_iter\_\__ 
zwraca bieżący obiekt. 

Proszę zmodyfikować kod tak, aby możliwa była wielokrotna iteracja - metoda _\_\_iter\_\__ 
powinna zwracać za każdym razem nowy obiekt, który udostępni metodę ___next\___. 
W tym celu proszę podzielić funkcjonalność klasy _SquaresGen_ na dwie 
klasy - jedna z nich powinna posiadać metodę _\__iter\___, a druga _\__next\___.

Przykład działania poprawnego rozwiązania.

g = SquaresGen(20)
print(list(g))
# [1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400]

# ponowne wywołanie list pobiera nowy iterator
print(list(g))
# [1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400]
"""

class SquaresGenIterator:
    """
    iterator, generujący kwadraty kolejnych liczb naturalnych
    """
    def __init__(self, limit):
        self.limit = limit
        self.count = 0

    def __next__(self):
        "Zwraca kolejny element ciągu"
        self.count += 1
        if self.count > self.limit:
            raise StopIteration
        return self.count ** 2

class SquaresGen:
    """
    generator iteratorów kwadratów kolejnych liczb naturalnych
    """
    def __init__(self, limit):
        self.limit = limit

    def __iter__(self):
        "Pobiera iterator, którym jest ten sam obiekt"
        return SquaresGenIterator(self.limit)


g = SquaresGen(20)
print(list(g))
print(list(g))