# Mapa transliteracji z rosyjskiego na łaciński
translit_map = {
    'А': 'A', 'а': 'a', 'Б': 'B', 'б': 'b', 'В': 'V', 'в': 'v',
    'Г': 'G', 'г': 'g', 'Д': 'D', 'д': 'd', 'Е': 'E', 'е': 'e',
    'Ё': 'Yo', 'ё': 'yo', 'Ж': 'Zh', 'ж': 'zh', 'З': 'Z', 'з': 'z',
    'И': 'I', 'и': 'i', 'Й': 'Y', 'й': 'y', 'К': 'K', 'к': 'k',
    'Л': 'L', 'л': 'l', 'М': 'M', 'м': 'm', 'Н': 'N', 'н': 'n',
    'О': 'O', 'о': 'o', 'П': 'P', 'п': 'p', 'Р': 'R', 'р': 'r',
    'С': 'S', 'с': 's', 'Т': 'T', 'т': 't', 'У': 'U', 'у': 'u',
    'Ф': 'F', 'ф': 'f', 'Х': 'Kh', 'х': 'kh', 'Ц': 'Ts', 'ц': 'ts',
    'Ч': 'Ch', 'ч': 'ch', 'Ш': 'Sh', 'ш': 'sh', 'Щ': 'Shch', 'щ': 'shch',
    'Ы': 'Y', 'ы': 'y', 'Э': 'E', 'э': 'e', 'Ю': 'Yu', 'ю': 'yu',
    'Я': 'Ya', 'я': 'ya', 'Ь': '', 'ь': '', 'Ъ': '', 'ъ': ''
}

def transliterate_ru_to_lat(text):
    """
    Transliteruje rosyjski tekst na łaciński używając mapy translit_map.
    """
    result = []
    for char in text:
        result.append(translit_map.get(char, char))  # Użyj mapy lub zostaw znak bez zmian
    return ''.join(result)

def main():
    # Odczytanie tekstu z pliku "ru.txt"
    with open("ru.txt", "r", encoding="utf-8") as file:
        input_text = file.read()

    # Transliteracja tekstu
    transliterated_text = transliterate_ru_to_lat(input_text)

    # Zapisanie transliterowanego tekstu do pliku "transliteracja.txt"
    with open("transliteracja.txt", "w", encoding="utf-8") as file:
        file.write(transliterated_text)

    print("Transliteracja zakończona. Wynik zapisano w 'transliteracja.txt'.")

if __name__ == "__main__":
    main()