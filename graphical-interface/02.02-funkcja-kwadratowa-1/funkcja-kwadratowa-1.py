a, b, c = 1, -12, 35
# ma działać dla dowolnych a, b, c, dla których istnieją rozwiązania 
# (int i float - bez inputa, wpisywane w kodzie)

delta = b**2-4*a*c                      # zastąp zero wzorem na deltę
x_1 = (-b+(delta**0.5))/(2*a)            # zastąp zero wzorem na rozwiązanie nr 1
x_2 = (-b-(delta**0.5))/(2*a)            # zastąp zero wzorem na rozwiązanie nr 2

# Wypisze równanie
print ("równanie: ", a, "x^2 + ", b, "x + ", c, " = 0")
# Wypisze rozwiązania
print ("rozwiązania: x_1 = ", x_1, ", x_2 = ", x_2)