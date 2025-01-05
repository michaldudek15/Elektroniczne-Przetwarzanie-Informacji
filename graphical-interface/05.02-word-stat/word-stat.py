# Funkcje pomocnicze
import re

def _words_from_line(line):
    "Zwraca listę słów dla linijki tekstu unicode."
    words = re.split(r'[\W\d]+', line)
    return [w.lower() for w in words if w]

def _sort_stat(stat):
    "Sortuje malejąco listę par według drugiego elementu."
    return sorted(stat, key=lambda p: p[1], reverse=True)

###################


def word_stat(filename):
    '''
    Zwraca posortowaną malejąco statystykę wystąpień słów
    w pliku w postaci listy par (słowo, liczba).
    '''

    #uzupełnij

    word_count = {}

    with open(filename, 'r', encoding='utf-8') as file:
        for line in file:
            words = _words_from_line(line)
            for word in words:
                if word in word_count:
                    word_count[word] += 1
                else:
                    word_count[word] = 1

    count = list(word_count.items())
    
    return _sort_stat(count)

print(word_stat("wiki_small.txt"))