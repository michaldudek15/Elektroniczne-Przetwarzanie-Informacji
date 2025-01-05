def faktoryzacja(liczba):
    czynnik = 2
    czynniki = []
    while czynnik * czynnik <= liczba:
        while liczba % czynnik == 0:
            czynniki.append(czynnik)
            liczba = liczba // czynnik
        czynnik = czynnik + 1
    if liczba > 1:
        czynniki.append(liczba)
    return czynniki
        
def czy_pierwsze(x):
    "Wypisuje liczby od 2 do x. Określa czy są pierwsze czy złożone (i z jakich pierwszych się składają)."
    #
    # do uzupełnienia
    #
    for liczba in range (2, x + 1):
        czynniki = faktoryzacja(liczba)
        if len(czynniki) == 1:
            print(liczba, "liczba pierwsza")
        else:
            print(liczba, "liczba złożona: ", czynniki)

    
czy_pierwsze(100)