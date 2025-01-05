def czy_parzyste(x, y):
    "Wypisuje liczby od x do y. Określa czy są parzyste czy nie."
    for i in range (x, y + 1):
        if (i % 2 == 0):
            print(i, "parzyste", sep = " -> ")
        else:
            print(i, "nieparzyste", sep = " -> ")
  
    
czy_parzyste(69, 123)
# coś jeszcze? nie, dziękuję