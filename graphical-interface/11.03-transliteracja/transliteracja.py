# mapa transliteracji z rosyjskiego na łaciński
mapaZnakow = {
    'А': 'A', 'а': 'a', 
    'Б': 'B', 'б': 'b', 
    'В': 'V', 'в': 'v',
    'Г': 'G', 'г': 'g', 
    'Д': 'D', 'д': 'd', 
    'Е': 'E', 'е': 'e',
    'Ё': 'Ё', 'ё': 'ё', 
    'Ж': 'Ž', 'ж': 'ž', 
    'З': 'Z', 'з': 'z',
    'И': 'I', 'и': 'i', 
    'Й': 'J', 'й': 'j', 
    'К': 'K', 'к': 'k',
    'Л': 'L', 'л': 'l', 
    'М': 'M', 'м': 'm', 
    'Н': 'N', 'н': 'n',
    'О': 'O', 'о': 'o', 
    'П': 'P', 'п': 'p', 
    'Р': 'R', 'р': 'r',
    'С': 'S', 'с': 's', 
    'Т': 'T', 'т': 't', 
    'У': 'U', 'у': 'u',
    'Ф': 'F', 'ф': 'f', 
    'Х': 'H', 'х': 'h', 
    'Ц': 'C', 'ц': 'c',
    'Ч': 'Č', 'ч': 'č', 
    'Ш': 'Š', 'ш': 'š', 
    'Щ': 'Ŝ', 'щ': 'ŝ',
    'Ь': '″', 'ь': '″', 
    'Ы': 'Y', 'ы': 'y', 
    'Э': 'È', 'э': 'è', 
    'Ю': 'Û', 'ю': 'û',
    'Я': 'Â', 'я': 'â', 
    'Ъ': '’', 'ъ': '’'
}

def transliteracja(tekstRosyjski):
    """
    transliteruje tekst zapiasny w języku rosyjskim na alfabet łaciński
    """
    wynik = []
    for char in tekstRosyjski:
        wynik.append(mapaZnakow.get(char, char))
    return ''.join(wynik)


with open("ru.txt", "r", encoding="utf-8") as file:
    input = file.read()

wynik = transliteracja(input)

with open("transliteracja.txt", "w", encoding="utf-8") as file:
    file.write(wynik)
