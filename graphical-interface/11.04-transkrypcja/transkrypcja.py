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

def transkrypcja(tekstRosyjski):
    wynik = []
    poprzedni = " "
    for char in tekstRosyjski:
        
        # literka "е"
        if char == "е" and (poprzedni in (" -.,/n!?" or "ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            print("dodaj je")
            wynik.append("je")
        elif char == "е" and poprzedni in "ЖжЛлЦцЧчШшЩщ":
            print("dodaj e")
            wynik.append("e")
        elif char == "е":
            print("dodaje ie")
            wynik.append("ie")
        
        # literka "Е"
        if char == "Е" and (poprzedni in (" -.,/n!?" or "ъьЪЬАаЕеЁёИиОоУуЫыЭэЮюЯя")):
            print("dodaj je")
            wynik.append("je")
        elif char == "Е" and poprzedni in "ЖжЛлЦцЧчШшЩщ":
            print("dodaj e")
            wynik.append("e")
        elif char == "Е":
            print("dodaje ie")
            wynik.append("ie")
            
        else:
            wynik.append(mapaZnakow.get(char,char))
        poprzedni = char
    return ''.join(wynik)


with open("ru.txt", "r", encoding="utf-8") as file:
    input = file.read()

wynik = transkrypcja(input)

with open("transkrypcja.txt", "w", encoding="utf-8") as file:
    file.write(wynik)