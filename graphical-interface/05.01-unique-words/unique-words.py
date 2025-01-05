# Funkcje pomocnicze
import re

def _words_from_line(line):
    "Zwraca listę słów dla linijki tekstu unicode."
    words = re.split('[\W\d]+', line)
    return [w.lower() for w in words if w]



#######################


def unique_words(filename):
    "Zwraca posortowaną alfabetycznie listę wszystkich słów z pliku."
    wordset = set()

    # uzupełnij
    with open(filename, 'r', encoding='utf-8') as file:
        for line in file:
            words = _words_from_line(line)
            wordset.update(words)
            
    return sorted(wordset)
    
    
# uruchom funkcję unique_words()

print(unique_words("wiki_small.txt"))