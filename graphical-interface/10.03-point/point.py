"""
Proszę skopiować kod klasy Vector z zadania 10.2.
Proszę dodać klasę _Point_, reprezentującą punkt w przestrzeni euklidesowej 3D. 
Powinien on mieć 3 współrzędne rzeczywiste (jak wektor) i wypisywać się w nawiasach okrągłych z dokładnością do 2 cyfr po przecinku.

A = Point(0, 1, 0)
print(A)
# (0.00, 1.00, 0.00)

Odejmowanie dwóch punktów powinno zwrócić wektor prowadzący od drugiego do pierwszego.

A = Point(2, 1, 0)
B = Point(0, 1, 1)
print(A - B)
# [2.00, 0.00, -1.00]

Dodawanie punktu i wektora powinno zwrócić punkt o nowych współrzędnych. Obsłuż zarówno _\_\_add\_\__ jak i ___iadd\___.  Metoda \__add\__() tworzy nowy punkt, \__iadd\__() przesuwa istniejący.

A = Point(0, 1, 0)
v = Vector(3, 4, 5)
print(A + v)
# (3.00, 5.00, 5.00)

print(id(A))
# 15120400

A += v
print(A)
# (3.00, 5.00, 5.00)

print(A)
# (6.00, 9.00, 10.00)

print(id(A))
# 15120400
"""

class Vector:
    """
    wektor w trójwymiarowej przestrzeni euklidesowej
    """

    def __init__(self, x, y, z):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)

    def __repr__(self):
        return '[%.2f, %.2f, %.2f]' % (self.x, self.y, self.z)

    def __add__(self, vec):
        "suma: self + vec"
        return Vector(self.x + vec.x, self.y + vec.y, self.z + vec.z)

    def __iadd__(self, vec):
        "suma: self += vec"
        self.x += vec.x
        self.y += vec.y
        self.z += vec.z
        return self

    def __mul__(self, vec):
        """
        iloczny skalarny: self + vec
        """
        return self.x * vec.x + self.y * vec.y + self.z * vec.z

    def norm(self):
        """
        norma wektora - jego długość
        """
        return (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5

    def __eq__(self, vec):
        return self.x == vec.x and self.y == vec.y and self.z == vec.z

    def __ne__(self, vec):
        return not self == vec
    
    def __bool__(self):
        """
        zwraca True, jeśli norma wektora jest niezerowa, w przeciwnym wypadku zwraca False
        """
        return self.norm() != 0
    
class Point:
    """
    punkt w trójwymiarowej przestrzeni euklidesowej
    """
    def __init__(self, x, y, z):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)

    def __repr__(self):
        """
        zwraca współrzędne punktu w nawiasach okrągłych
        """
        return '(%.2f, %.2f, %.2f)' % (self.x, self.y, self.z)

    def __sub__(self, other):
        """
        odejmowanie dwóch punktów, zwraca wektor prowadzący od other do self
        """
        return Vector(self.x - other.x, self.y - other.y, self.z - other.z)

    def __add__(self, vec):
        """
        dodawanie punktu i wektora, zwraca nowy punkt
        """
        return Point(self.x + vec.x, self.y + vec.y, self.z + vec.z)

    def __iadd__(self, vec):
        """
        dodawanie punktu i wektora, przesuwa istniejący punkt
        """
        self.x += vec.x
        self.y += vec.y
        self.z += vec.z
        return self


A = Point(0, 1, 0)
print(A)
# (0.00, 1.00, 0.00)

A = Point(2, 1, 0)
B = Point(0, 1, 1)
print(A - B)
# [2.00, 0.00, -1.00]

A = Point(0, 1, 0)
v = Vector(3, 4, 5)
print(A + v)
# (3.00, 5.00, 5.00)

print(id(A))
# 15120400

A += v
print(A)
# (3.00, 5.00, 5.00)

A += v
print(A)
# (6.00, 9.00, 10.00)

print(id(A))
# 15120400