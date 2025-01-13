"""
Proszę skopiować kod klasy _Vector_ z zadania 10.2 oraz klasy _Point_ z zadania 10.3.


Proszę dodać klasę _Triangle_. Trójkąt ma wypisywać wszystkie swoje punkty i udostępniać metody obliczające jego pole powierzchni i obwód. 

A = Point(0, 0, 0)
B = Point(1, 0, 0)
C = Point(0, 1, 0)

t = Triangle(A, B, C)
print(t)
# triangle: (0.00, 0.00, 0.00), (1.00, 0.00, 0.00), (0.00, 1.00, 0.00)

print(t.perimeter())
# 3.414213562373095

print(t.area())
# 0.4999999999999999

**Wszystkie klasy** powinny umożliwiać porównywanie przy pomocy '==' i '!='. 

Dwa punkty są równe, gdy maja wszystkie współrzędne o równych wartościach. 

Dwa trójkąty są równe, gdy zawierają punkty parami równe, obojętnie w jakiej kolejności.

**Wszystkie metody** powinny być udokumentowane.
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
    
class Triangle:
    """
    trójkąt w trójwymiarowej przestrzeni euklidesowej
    """

    def __init__(self, p1, p2, p3):
        """
        nicjalizuje trójkąt za pomocą trzech punktów: p1, p2, p3
        """
        self.p1 = p1
        self.p2 = p2
        self.p3 = p3

    def __repr__(self):
        """
        zwraca współrzędne wierzchołków trójkąta 
        """
        return 'triangle: %s, %s, %s' % (self.p1, self.p2, self.p3)

    def perimeter(self):
        """
        oblicza obwód trójkąta jako sumę długości jego boków.
        """
        return (self.p1 - self.p2).norm() + (self.p2 - self.p3).norm() + (self.p3 - self.p1).norm()

    def area(self):
        """
        oblicza pole powierzchni trójkąta za pomocą wzoru Herona
        """
        a = (self.p1 - self.p2).norm()
        b = (self.p2 - self.p3).norm()
        c = (self.p3 - self.p1).norm()
        s = (a + b + c) / 2
        return (s * (s - a) * (s - b) * (s - c)) ** 0.5

    def __eq__(self, other):
        """
        prawdza, czy dwa trójkąty są równe;
        trójkąty są równe, jeśli mają te same punkty, niezależnie od kolejności
        """
        points_self = {self.p1, self.p2, self.p3}
        points_other = {other.p1, other.p2, other.p3}
        return points_self == points_other

    def __ne__(self, other):
        """
        sprawdza, czy dwa trójkąty są różne.
        """
        return not self == other





A = Point(0, 0, 0)
B = Point(1, 0, 0)
C = Point(0, 1, 0)

t = Triangle(A, B, C)
print(t)
# triangle: (0.00, 0.00, 0.00), (1.00, 0.00, 0.00), (0.00, 1.00, 0.00)

print(t.perimeter())
# 3.414213562373095

print(t.area())
# 0.4999999999999999