def liczba_na_slowa(n):
    jednostki = ["", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć"]
    nastki = ["dziesięć", "jedenaście", "dwanaście", "trzynaście", "czternaście", "piętnaście", "szesnaście", "siedemnaście", "osiemnaście", "dziewiętnaście"]
    dziesiątki = ["", "", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt"]
    setki = ["", "sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"]

    # Nazwy grup tysięcznych z odmianą
    grupy = [
        ("", "", ""),
        ("tysiąc", "tysiące", "tysięcy"),
        ("milion", "miliony", "milionów"),
        ("miliard", "miliardy", "miliardów"),
        ("bilion", "biliony", "bilionów"),
        ("biliard", "biliardy", "biliardów"),
        ("trylion", "tryliony", "trylionów"),
        ("tryliard", "tryliardy", "tryliardów"),
        ("kwadrylion", "kwadryliony", "kwadrylionów"),
        ("kwadryliard", "kwadryliardy", "kwadryliardów"),
        ("kwintylion", "kwintyliony", "kwintylionów"),
        ("kwintyliard", "kwintyliardy", "kwintyliardów"),
        ("sekstylion", "sekstyliony", "sekstylionów"),
        ("sekstyliard", "sekstyliardy", "sekstyliardów"),
        ("septylion", "septyliony", "septylionów"),
        ("septyliard", "septyliardy", "septyliardów"),
        ("oktylion", "oktyliony", "oktylionów"),
        ("oktyliard", "oktyliardy", "oktyliardów"),
        ("nonylion", "nonyliony", "nonylionów"),
        ("nonyliard", "nonyliardy", "nonyliardów"),
        ("decyliard", "decyliardy", "decyliardów")
    ]

    # Sprawdzenie dla zera
    if n == 0:
        return "zero"

    wynik = []  # Przechowuje wynik jako listę słów
    grupa_index = 0  # Indeks grupy (tysiące, miliony itd.)

    while n > 0:
        # Pobierz ostatnie trzy cyfry
        trzy_cyfry = n % 1000
        n //= 1000

        if trzy_cyfry > 0:
            słowa_grupy = []

            # Setki
            słowa_grupy.append(setki[trzy_cyfry // 100])

            # Dziesiątki i jednostki
            dziesiątka = (trzy_cyfry % 100) // 10
            jednostka = trzy_cyfry % 10

            if dziesiątka == 1:  # Nastki (10-19)
                słowa_grupy.append(nastki[jednostka])
            else:
                słowa_grupy.append(dziesiątki[dziesiątka])
                słowa_grupy.append(jednostki[jednostka])

            # Dodaj odpowiednią nazwę grupy z odmianą
            if trzy_cyfry == 1:
                słowa_grupy.append(grupy[grupa_index][0])  # np. "tysiąc"
            elif 2 <= trzy_cyfry % 10 <= 4 and (trzy_cyfry % 100 < 10 or trzy_cyfry % 100 >= 20):
                słowa_grupy.append(grupy[grupa_index][1])  # np. "tysiące"
            else:
                słowa_grupy.append(grupy[grupa_index][2])  # np. "tysięcy"

            wynik.insert(0, " ".join(filter(bool, słowa_grupy)))

        grupa_index += 1

    return " ".join(wynik)



liczba = int(input("podaj liczbę: "))
print(liczba_na_slowa(liczba))