def sequence_gen(function, *args):
    """
    generuje kolejne wyrazy dowolnego ciągu danego przy pomocy definicji rekurencyjnej z pierwszego argumentu, przyjmuje też pierwsze wyrazy ciągu
    """
    previous = list(args)

    for value in previous:
        yield value

    while True:
        next = function(*previous)
        yield next
        previous.pop(0)
        previous.append(next)

def next_fib(a, b):
    return a + b

def next_even(a):
    return a + 2

fibonacci = sequence_gen(next_fib, 0, 1)
even = sequence_gen(next_even, 0)
tribonacci = sequence_gen(lambda a,b,c: a+b+c, 0, 0, 1)
nums = sequence_gen(lambda a,b: a+b, 'a', 'b')


for i in range(15):
    print(next(fibonacci))