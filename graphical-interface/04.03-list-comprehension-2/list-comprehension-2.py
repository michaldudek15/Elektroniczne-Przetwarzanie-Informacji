limit = 100
numbers = range(1, limit+1)

# Zastąp pustą listę wyrażeniem zwracającym liczby pierwsze z zakresu od 1 do 'limit'
primes = [n for n in numbers if len([i for i in range(1, n + 1) if n % i == 0]) == 2]

# używam list comprehension z poprzedniego zadania do policzenia dzielników liczby n
# następnie wypisuję te liczby, dla których ta lista ma tylko dwa elementy

print('Liczby pierwsze od 1 do %d: %s' % (limit, primes))