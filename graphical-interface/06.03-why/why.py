def complicated():
    '''ustawia wartość zmiennej x na 5,
    definiuje funkcję v1,
    wywołuje funkcję v1'''
    x = 5
    def f1():
        '''definiuje funkcję v2, 
        ustawia wartość x na 6,
        wywołuje funkcję v2,
        ustawia wartość x na 7,
        definiuje funkcję v3,
        wywołuje funkcję v3,
        wywołuje funkcję v2'''
        def f2(): 
            ''' wypisuje wartość zmiennej x'''
            print(x)
        x = 6
        f2()
        x = 7
        def f3(): 
            '''zmienia wartość lokalnej zmiennej x na 8'''
            x = 8
        f3()
        f2()
    f1()

'''
wypisze się:
6
7
ponieważ wywołanie funkcji f2 powoduje wypisanie wartości zmiennej x,
bezpośrednio przed pierwszym wypisaniem przypisujemy do zmiennej wartość 6,
wywołanie funkcji f3 zmienia wartość lokalnej x na 8, nie wpływa na x sprzed definicji funkcji f3,
a przed drugim wywołaniem funkcji f3, pomijając definicję i wywołanie funkcji f3, zmieniamy wartość x na 7
'''

complicated()