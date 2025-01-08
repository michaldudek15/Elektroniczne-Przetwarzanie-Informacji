def fib_gen():
    """
    generuje kolejne liczby fibonacciego
    """
    a, b = 0, 1
    while True:
        yield a
        (a, b) = (b, a + b)


fib = fib_gen()

for i in range(15):
    print(next(fib))