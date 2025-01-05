def make_dict_adder():
    def add(key, value):
        if not hasattr(add, "dictionary"):
            add.dictionary = {}
        add.dictionary[key] = value
        return add.dictionary
    return add


m = make_dict_adder()
print( m('klucz1', 'aaa') )
print( m('klucz2', 'bbb') )

n = make_dict_adder()
print( n('kluczX', 'xxx') )
print( n('kluczY', 'yyy') )