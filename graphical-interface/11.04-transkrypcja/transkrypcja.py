mapaZnakow = {
    'А': 'A', 'а': 'a', 
    'Б': 'B', 'б': 'b', 
    'В': 'W', 'в': 'w',
    'Г': 'G', 'г': 'g', 
    'Д': 'D', 'д': 'd', 
    'Е': 'E', 'е': 'e',
    'Ё': 'Ё', 'ё': 'ё', 
    'Ж': 'Ż', 'ж': 'ż', 
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
    'Х': 'Ch', 'х': 'ch', 
    'Ц': 'C', 'ц': 'c',
    'Ч': 'Cz', 'ч': 'cz', 
    'Ш': 'Sz', 'ш': 'sz', 
    'Щ': 'Szcz', 'щ': 'szcz',
    'Ь': '´', 'ь': '´', 
    'Ы': 'Y', 'ы': 'y', 
    'Э': 'È', 'э': 'è', 
    'Ю': 'Û', 'ю': 'û',
    'Я': 'Â', 'я': 'â', 
    'Ъ': '', 'ъ': ''
}

def transkrypcja(tekstRosyjski):
    """
    transkrybuje tekst zapisany alfabetem rosyjskim na język polski
    """
    wynik = []
    poprzedni = " "
    for char in tekstRosyjski:
        
        # poprawka na literke "л"
        if poprzedni == "л" and char in "еёиьюя":
            wynik.pop()
            wynik.append("l")

        # poprawka na literke "ь"
        if poprzedni == "ь" and char in "ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя":
            wynik.pop()

        # literka "е"
        if char == "е" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("je")
            poprzedni = char
            continue
        elif char == "е" and poprzedni in "ЖжЛлЦцЧчШшЩщ":
            wynik.append("e")
            poprzedni = char
            continue
        elif char == "е":
            wynik.append("ie")
            poprzedni = char
            continue
        
        # literka "Е"
        if char == "Е" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("Je")
            poprzedni = char
            continue
        elif char == "Е" and poprzedni in "ЖжЛлЦцЧчШшЩщ":
            wynik.append("E")
            poprzedni = char
            continue
        elif char == "Е":
            wynik.append("Ie")
            poprzedni = char
            continue

        # literka "ё"
        elif char == "ё" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("jo")
            poprzedni = char
            continue
        if char == "ё" and poprzedni in "ЖжЛлЧчШшЩщ":
            wynik.append("o")
            poprzedni = char
            continue
        elif char == "ё":
            wynik.append("io")
            poprzedni = char
            continue

        # literka "Ё"
        elif char == "Ё" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("Jo")
            poprzedni = char
            continue
        elif char == "Ё" and poprzedni in "ЖжЛлЧчШшЩщ":
            wynik.append("O")
            poprzedni = char
            continue
        elif char == "Ё":
            wynik.append("Io")
            poprzedni = char
            continue

        # literka "и"
        elif char == "и" and (poprzedni in ("ЧчЩщ")):
            wynik.append("i")
            poprzedni = char
            continue
        elif char == "и" and (poprzedni in ("Ьь")):
            wynik.append("ji")
            poprzedni = char
            continue
        elif char == "и" and (poprzedni in ("ЖжЦцШш")):
            wynik.append("y")
            poprzedni = char
            continue

        # literka "И"
        elif char == "И" and (poprzedni in ("ЧчЩщ")):
            wynik.append("I")
            poprzedni = char
            continue
        elif char == "И" and (poprzedni in ("Ьь")):
            wynik.append("Ji")
            poprzedni = char
            continue
        elif char == "И" and (poprzedni in ("ЖжЦцШш")):
            wynik.append("Y")
            poprzedni = char
            continue

        # literka "л"
        elif char == "л" and (poprzedni in ("ЕеЁёИиЬьЮюЯя")):
            wynik.append("l")
            poprzedni = char
            continue
        elif char == "л":
            wynik.append("ł")
            poprzedni = char
            continue
         # literka "Л"
        elif char == "Л" and (poprzedni in ("ЕеЁёИиЬьЮюЯя")):
            wynik.append("L")
            poprzedni = char
            continue
        elif char == "Л":
            wynik.append("Ł")
            poprzedni = char
            continue

        # literka "ю"
        elif char == "ю" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("ju")
            poprzedni = char
            continue
        elif char == "ю" and (poprzedni in ("Лл")):
            wynik.append("u")
            poprzedni = char
            continue
        elif char == "ю":
            wynik.append("iu")
            poprzedni = char
            continue
        # literka "Ю"
        elif char == "Ю" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("Ju")
            poprzedni = char
            continue
        elif char == "Ю" and (poprzedni in ("Лл")):
            wynik.append("U")
            poprzedni = char
            continue
        elif char == "Ю":
            wynik.append("Iu")
            poprzedni = char
            continue

        # literka "я"
        elif char == "я" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("ja")
            poprzedni = char
            continue
        elif char == "я" and (poprzedni in ("Лл")):
            wynik.append("a")
            poprzedni = char
            continue
        elif char == "я":
            wynik.append("ia")
            poprzedni = char
            continue
         # literka "Я"
        elif char == "Я" and (poprzedni in (" -.,\n!?ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            wynik.append("Ja")
            poprzedni = char
            continue
        elif char == "Я" and (poprzedni in ("Лл")):
            wynik.append("A")
            poprzedni = char
            continue
        elif char == "Я":
            wynik.append("Ia")
            poprzedni = char
            continue
        else:
            wynik.append(mapaZnakow.get(char,char))
            poprzedni = char

    return ''.join(wynik)


with open("ru.txt", "r", encoding="utf-8") as file:
    input = file.read()

wynik = transkrypcja(input)

with open("transkrypcja.txt", "w", encoding="utf-8") as file:
    file.write(wynik)