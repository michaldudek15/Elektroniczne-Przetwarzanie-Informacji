a = 10

def print_global():
    '''wypisuje wartość zmiennej globalnej a'''
    print("globalna: ", a)

print_global()

def shadow_a():
    '''tworzy lokalną zmienną a, następnie wypisuje jej wartość'''
    a = 5
    print("lokalna: ", a)
    
shadow_a()

counter = 1

def increase_counter(n):
    '''zwiększa wartość zmiennej globalnej counter o n'''
    global counter
    counter += n
    print("wartość licznika po zwiększeniu: ", counter)

increase_counter(5)