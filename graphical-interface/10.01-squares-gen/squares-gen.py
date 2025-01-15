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