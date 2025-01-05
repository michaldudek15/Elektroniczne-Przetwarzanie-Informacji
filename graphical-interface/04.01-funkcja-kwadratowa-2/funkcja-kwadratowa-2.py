# ma działać dla dowolnych a, b, c 
#(int i float, wczytywane od użytkownika - input)
# a
a = float(input('podaj a: '))
# b
b = float(input('podaj b: '))
# c
c = float(input('podaj c: '))

delta = b**2-4*a*c                      # zastąp zero wzorem na deltę
x_1 = (-b+(delta**0.5))/(2*a)            # zastąp zero wzorem na rozwiązanie nr 1
x_2 = (-b-(delta**0.5))/(2*a)            # zastąp zero wzorem na rozwiązanie nr 2

# Wypisz równanie
print ("równanie: ", a, "x^2 + ", b, "x + ", c, " = 0")
# Wypisz rozwiązania
if (delta > 0):
    print ("rozwiązania: x_1 = ", round(x_1, 2), ", x_2 = ", round(x_2, 2))
elif (delta == 0):
    print ("rozwiązanie: x_1 = ", round(x_1, 2))
else:
    print ('brak')