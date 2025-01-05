def call(function, *args, **kw_args):
    'funkcja przyjmuje jako pierwszy argument funkcję, którą chcemy wykonać, a później dowolną liczbę argumentów, które przyjmie funkcja z pierwszego arguemntu'
    return function(*args, **kw_args)
    
    


print( call(max, 4, -1, 3) )

print( call(max, 4, -5, 3, key=lambda x: abs(x)) )

print( call(sorted, [1, 3, 2], reverse=True) )

print( call(min, 1, 10, -2) )

print( call(pow, 2, 4) )