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
    

v1 = Vector(0, 1, 0)
v2 = Vector(3, 5, 3)
v1 * v2

print(v1.norm())
print(v2.norm())