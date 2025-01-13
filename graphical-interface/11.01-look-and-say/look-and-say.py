def sequence_gen(function, *args):
    previous = list(args)

    for value in previous:
        yield value

    while True:
        next = function(*previous)
        yield next
        previous.pop(0)
        previous.append(next)


def next_look_and_say(n):
    """
    zwraca kolejny wyraz ciągu look-and-say dla podanego wyrazu n.
    """
    znaki = str(n)  # zamiana liczby na ciąg znaków
    wynik = ""     # przechowuje wynikowy wyraz ciągu
    licznik = 1       # licznik powtórzeń bieżącej cyfry

    for i in range(1, len(znaki)):
        if znaki[i] == znaki[i - 1]:
            licznik += 1  # zwiększ licznik, jeśli bieżąca cyfra jest taka sama jak poprzednia
        else:
            # dodaj do wyniku licznik i cyfrę
            wynik += str(licznik) + znaki[i - 1]
            licznik = 1  # zresetuj licznik dla nowej cyfry

    # dodaj ostatnią grupę cyfr
    wynik += str(licznik) + znaki[-1]

    return int(wynik)


g = sequence_gen(next_look_and_say, 1)
print(next(g))  # 1
print(next(g))  # 11
print(next(g))  # 21
print(next(g))  # 1211
print(next(g))  # 111221
print(next(g))  # 312211
print(next(g))  # 13112221
print(next(g))  # 1113213211
print(next(g))
print(next(g))
print(next(g))
