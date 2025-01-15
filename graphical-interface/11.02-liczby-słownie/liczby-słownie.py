def liczba_slownie(n):
    """
    zamienia liczbę na odpowiadające jej wyrazy w języku polskim
    """
    jednostki = ["", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć"]
    nastki = ["", "jedenaście", "dwanaście", "trzynaście", "czternaście", "piętnaście", "szesnaście", "siedemnaście", "osiemnaście", "dziewiętnaście"]
    dziesiatki = ["", "dziesięć", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt"]
    setki = ["", "sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"]
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
        ("sekstylion", "sekstyliony", "sekstylionów"),
        ("septylion", "septyliony", "septylionów"),
        ("oktylion", "oktyliony", "oktylionów"),
        ("nonylion", "nonyliony", "nonylionów"),
        ("decyliard", "decyliardy", "decyliardów")
    ]

    if n == 0:
        return "zero"

    wynik = []
    indeksGrupy = 0

    while n > 0:
        trzyCyfry = n % 1000 # iteracja działa na trójce znaków
        n //= 1000 # dzielenie całkowitoliczbowe -> ucięcie trzech ostatnich znaków liczby

        if trzyCyfry == 0:
            indeksGrupy += 1
            continue

        slownie = []

        indeksSetek = trzyCyfry // 100
        indeksDziesiatek = (trzyCyfry // 10) % 10
        indeksJednostekLubNastek = trzyCyfry % 10

        if indeksSetek > 0:
            slownie.append(setki[indeksSetek])

        if indeksDziesiatek == 1 and indeksJednostekLubNastek > 0: # przypadek nastek
            slownie.append(nastki[indeksJednostekLubNastek])
        else:
            if indeksDziesiatek > 0:
                slownie.append(dziesiatki[indeksDziesiatek])
            if indeksJednostekLubNastek > 0:
                if not (indeksJednostekLubNastek == 1 and indeksGrupy > 0): # przypadek jedności cyfry calej grupy (np. milion, tysiąc)
                    slownie.append(jednostki[indeksJednostekLubNastek])

        if indeksGrupy > 0: # dodanie nazwy grupy
            if trzyCyfry == 1:
                slownie.append(grupy[indeksGrupy][0])
            elif 2 <= trzyCyfry % 10 <= 4 and (trzyCyfry % 100 < 10 or trzyCyfry % 100 >= 20):
                slownie.append(grupy[indeksGrupy][1])
            else:
                slownie.append(grupy[indeksGrupy][2])

        wynik.append(" ".join(slownie))
        indeksGrupy += 1

    return " ".join(reversed(wynik))


liczba = int(input("podaj liczbę: "))
print(liczba_slownie(liczba))