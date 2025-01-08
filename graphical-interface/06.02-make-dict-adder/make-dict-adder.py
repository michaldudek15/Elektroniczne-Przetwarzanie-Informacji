def make_dict_adder():
    dictionary = {}
    def add(key, value):
        dictionary[key] = value
        return dictionary
    return add


m = make_dict_adder()
print( m('klucz1', 'aaa') )
print( m('klucz2', 'bbb') )

n = make_dict_adder()
print( n('kluczX', 'xxx') )
print( n('kluczY', 'yyy') )