def invert(in_filename, out_filename):
    "Odwraca zawartość pliku tekstowego."
    input_file  = open(in_filename, 'r')
    output_file = open(out_filename, 'w')

    # uzupełnij
    linie_tekstu = input_file.readlines()
    
    odwrócone_linie_tekstu = [linia[::-1] for linia in reversed(linie_tekstu)]
    
    for linia in odwrócone_linie_tekstu:
        output_file.write(linia)

    input_file.close()
    output_file.close()

# wykonaj funkcję
invert("inverted.txt", "wiki10.txt")    