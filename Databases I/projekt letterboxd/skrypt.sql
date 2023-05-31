/* 
Maja Flaczek
Michał Dudek
Bazy danych I – miniprojekt
system inspirowany aplikacją Letterboxd
*/

-- 1. Użytkownik
CREATE TABLE Użytkownik(
    login VARCHAR(20) NOT NULL,
    hasło VARCHAR(32) NOT NULL,
    email VARCHAR(255) NOT NULL,
    PRIMARY KEY(login), -- login jest kluczem, bo jednoznacznie wyznacza konkretnego uzytkownika
    UNIQUE INDEX(login, email) -- ani login, ani email nie mogą się powtarzać
);

INSERT INTO Użytkownik VALUES
	("AnnaKowalska87", MD5("haslo1"),"ania87@email.com"),
	("JanNowak123", MD5("haslo2"),"janeek@email.com"),
	("KarolinaWójcik19", MD5("haslo3"),"karola19wojcik@email.com"),
	("PiotrSzymański2022", MD5("haslo4"),"piotrek22@email.com"),
	("MagdaKaczmarek555", MD5("haslo5"),"magkacz5@email.com"),
	("KamilLewandowski77", MD5("haslo6"),"lewy77@email.com"),
	("MartaZielińska2023", MD5("haslo7"),"zielinska23@email.com"),
	("AdrianKubiak1234", MD5("haslo8"),"adkub1234@email.com"),
	("OlaWiśniewska1990", MD5("haslo9"),"wisnia9019@email.com"),
	("DamianJankowski22", MD5("haslo10"),"damianjankowskiUżytkownik@email.com");

-- 2. Obserwacja
CREATE TABLE Obserwacja (
  obserwujacy VARCHAR(255),
  obserwowany VARCHAR(255),
  PRIMARY KEY (obserwujacy, obserwowany), -- obserwujący i obserwowany jednoznacznie wyznaczają daną obserwację
  FOREIGN KEY (obserwujacy) REFERENCES Użytkownik(login),
  FOREIGN KEY (obserwowany) REFERENCES Użytkownik(login)
);

INSERT INTO Obserwacja VALUES 
    ("AdrianKubiak1234","AnnaKowalska87"),
    ("JanNowak123","KarolinaWójcik19"),
    ("JanNowak123","MartaZielińska2023"),
    ("DamianJankowski22","OlaWiśniewska1990"),
    ("DamianJankowski22","MartaZielińska2023"),
    ("OlaWiśniewska1990","DamianJankowski22");

-- 3. Film
CREATE TABLE Film(
	tytuł VARCHAR(255) NOT NULL,
	rok_produkcji YEAR NOT NULL,
	czas_trwania INT NOT NULL, -- nie moze byc filmu, ktory nie trwa
   	opis TEXT(700),
	PRIMARY KEY(tytuł, rok_produkcji) -- moze byc kilka filmow o takim samym tytule, oraz kilka filmow wydanych w jednym roku; jednak jednocześnie zdarza się to na tyle rzadko, ze mozna potraktowac te dwie kolumny jako klucz
);

INSERT INTO Film VALUES 
    ("Persona", 1966, 83, "A young nurse, Alma, is put in charge of Elisabeth Vogler: an actress who is seemingly healthy in all respects, but will not talk. As they spend time together, Alma speaks to Elisabeth constantly, never receiving any answer. Alma eventually confesses her secrets to a seemingly sympathetic Elisabeth and finds that her own personality is being submerged into Elisabeth's persona."),
    ("Call Me by Your Name", 2017, 132, "In 1980s Italy, a relationship begins between seventeen-year-old teenage Elio and the older adult man hired as his father's research assistant."),
    ("Portrait of a Lady on Fire", 2019, 120, "On an isolated island in Brittany at the end of the eighteenth century, a female painter is obliged to paint a wedding portrait of a young woman."),
    ("Asterix & Obelix: Mission Cleopatra", 2002, 108, "The Egyptian Queen Cleopatra bets against the Roman Emperor, Julius Caesar, that her people are still great, even if the times of the Pharaohs has long passed. She vows (against all logic) to build a new palace for Caesar within three months. Since all her architects are either busy otherwise or too conservative in style, this ambivalent honor falls to Edifis. He is to build the palace and be covered in gold or, if not, his fate is to be eaten by crocodiles. Edifis calls upon an old friend to help him out: The fabulous Druid Getafix from Gaul, who brews a fantastic potion that gives supernatural strength. In order to help and protect the old Druid, Asterix and Obelix accompany him on his journey to Egypt. When Julius Caesar gets wind of the project succeeding, he has the building site attacked by his troops in order to win the bet and not lose face. But just like the local pirates, he hasn't counted on Asterix and Obelix."),
    ("Eraserhead", 1977, 89, "Henry Spencer tries to survive his industrial environment, his angry girlfriend, and the unbearable screams of his newly born mutant child."),
    ("Mulholland Drive", 2001, 147, "Blonde Betty Elms has only just arrived in Hollywood to become a movie star when she meets an enigmatic brunette with amnesia. Meanwhile, as the two set off to solve the second woman's identity, filmmaker Adam Kesher runs into ominous trouble while casting his latest project."),
    ("Twin Peaks: Fire Walk with Me", 1992, 135, "In the questionable town of Deer Meadow, Washington, FBI Agent Desmond inexplicably disappears while hunting for the man who murdered a teen girl. The killer is never apprehended, and, after experiencing dark visions and supernatural encounters, Agent Dale Cooper chillingly predicts that the culprit will claim another life. Meanwhile, in the more cozy town of Twin Peaks, hedonistic beauty Laura Palmer hangs with lowlifes and seems destined for a grisly fate."),
    ("Everything Everywhere All at Once", 2022, 140, "An aging Chinese immigrant is swept up in an insane adventure, where she alone can save what's important to her by connecting with the lives she could have led in other universes."),
    ("Midsommar", 2019, 147, "Several friends travel to Sweden to study as anthropologists at a summer festival that is held every ninety years in the remote hometown of one of them. What begins as a dream vacation in a place where the sun never sets, gradually turns into a dark nightmare as the mysterious inhabitants invite them to participate in their disturbing festive activities."),
    ("The Witch", 2015, 92, "In 1630s New England, William and Katherine lead a devout Christian life with five children, homesteading on the edge of an impassable wilderness, exiled from their settlement when William defies the local church. When their newborn son vanishes and crops mysteriously fail, the family turns on one another.");

-- 4. Osoba_filmu
CREATE TABLE Osoba_filmu(
	id_osoby INT AUTO_INCREMENT NOT NULL UNIQUE,
	imię VARCHAR(32),
	nazwisko VARCHAR(32),
	bio TEXT(4000),
	PRIMARY KEY (id_osoby)
);

INSERT INTO Osoba_filmu(imię, nazwisko, bio) VALUES 
    ("David", "Lynch", "David Keith Lynch (born January 20, 1946) is an American filmmaker, painter, visual artist, musician, and writer. Known for his surrealist films, he has developed his own unique cinematic style, which has been dubbed 'Lynchian', and which is characterized by its dream imagery and meticulous sound design. Indeed, the surreal and in many cases violent elements to his films have earned them the reputation that they 'disturb, offend or mystify' their audiences.

    Moving around various parts of the United States as a child within his middle class family, Lynch went on to study painting in Philadelphia, where he first made the transition to producing short films. Deciding to devote himself more fully to this medium, he moved to Los Angeles, where he produced his first motion picture, the surrealist horror Eraserhead (1977). After Eraserhead became a cult classic on the midnight movie circuit, Lynch was employed to direct The Elephant Man (1980), from which he gained mainstream success. Then being employed by the De Laurentiis Entertainment Group, he proceeded to make two films. First, the science-fiction epic Dune (1984), which proved to be a critical and commercial failure, and then a neo-noir crime film, Blue Velvet (1986), which was highly critically acclaimed.

    Proceeding to create his own television series with Mark Frost, the highly popular murder mystery Twin Peaks (1990-1992), he also created a cinematic prequel, Fire Walk With Me (1992), a road movie, Wild at Heart (1990), and a family film, The Straight Story (1999) in the same period. Turning further towards surrealist filmmaking, three of his following films worked on 'dream logic' non-linear narrative structures, Lost Highway (1997), Mulholland Drive (2001) and Inland Empire (2006).

    Lynch has received three Academy Award nominations for Best Director, for his films The Elephant Man, Blue Velvet and Mulholland Drive, and also received a screenplay Academy Award nomination for The Elephant Man. Lynch has twice won France's César Award for Best Foreign Film, as well as the Palme d'Or at the Cannes Film Festival and a Golden Lion award for lifetime achievement at the Venice Film Festival. The French government awarded him the Legion of Honor, the country's top civilian honor, as a Chevalier in 2002 and then an Officier in 2007, while that same year, The Guardian described Lynch as 'the most important director of this era'. Allmovie called him 'the Renaissance man of modern American filmmaking', whilst the success of his films have led to him being labeled 'the first popular Surrealist'."),

    ("Alan", "Splet", null ),

    ("Jack", "Nance", "Marvin John Nance (December 21, 1943 - December 30, 1996), known professionally as Jack Nance and occasionally credited as John Nance, was an American actor of stage and screen, primarily starring in offbeat or avant-garde productions. He was known for his work with director David Lynch, particularly for his roles in Eraserhead, Blue Velvet and Twin Peaks."),

    ("Charlotte", "Stewart","Charlotte Stewart (born February 27, 1941 in Yuba City, California, USA) is an American film and television actress.

    She is most famous for her role as the schoolmarm 'Miss Beadle' on Little House on the Prairie and her work with director David Lynch."),

    ("Allen", "Joseph", "Allen Joseph was born on May 29, 1919 in Minneapolis, Minnesota, USA. He was an actor, known for Eraserhead (1977), Chilly Scenes of Winter (1979) and Raging Bull (1980). He died on November 30, 2012 in Minneapolis, Minnesota, USA."),

    ("Jeanne", "Bates", "Jeanne Bates (May 21, 1918 - November 28, 2007) was an American actress. After performing in radio serials, she signed a contract with Columbia Pictures in 1942 which began her career in films both in bit parts and larger roles in a series of horror films and noirs, including The Return of the Vampire (1943) and Shadows in the Night (1946).

    In her later career, Bates would collaborate with David Lynch on his films Eraserhead (1977) and Mulholland Drive (2001), the latter of which was her last film credit before her death in 2007."),

    ("Ingmar", "Bergman", "Ernst Ingmar Bergman (14 July 1918 - 30 July 2007) was a Swedish filmmaker. Widely considered one of the greatest and most influential filmmakers of all time, his films are known as 'profoundly personal meditations into the myriad struggles facing the psyche and the soul.'

    Bergman directed more than 60 films and documentaries for cinematic release and for television screenings, most of which he also wrote. Most of his films were set in Sweden, and many films from 1961 onward were filmed on the island of Fårö. He also had a theatrical career that ran in parallel with his film career. It included periods as Leading Director of the Royal Dramatic Theatre in Stockholm and of the Residenztheater in Munich. He directed more than 170 plays. He forged a creative partnership with his cinematographers Gunnar Fischer and Sven Nykvist. Among his company of actors were Harriet Andersson, Bibi Andersson, Liv Ullmann, Gunnar Björnstrand, Erland Josephson, Ingrid Thulin, Gunnel Lindblom and Max von Sydow."),

    ("Bibi", "Lindström", null ),

    ("Luca", "Guadagnino", "Luca Guadagnino is an Italian film director. He rose to notability with the 2005 film Melissa P., and he is a frequent collaborator with actress Tilda Swinton, including the 1999 film The Protagonists, the 2010 film I Am Love, the 2015 film A Bigger Splash, and the 2018 film Suspiria. In 2017, Guadagnino gained widespread recognition for directing and producing the critically acclaimed romance film Call Me by Your Name. For the film, he received various accolades including nominations for the Academy Award for Best Picture and the BAFTA Award for Best Direction."),

    ("James", "Ivory", "James Francis Ivory (born June 7, 1928) is an American film director, best known for the results of his long collaboration with Merchant Ivory Productions, which included both Indian-born film producer Ismail Merchant, and screenwriter Ruth Prawer Jhabvala. Their films won six Academy Awards.

    Ivory has been nominated three times for the Best Director Oscar, and won his first Academy Award at the age of 89 in 2018, Best Adapted Screenplay for Call Me by Your Name."),

    ("Sayombhu", "Mukdeeprom", "Sayombhu Mukdeeprom is a Thai cinematographer, best known for his work on the films of Apichatpong Weerasethakul and Luca Guadagnino."),

    ("Sufjan", "Stevens", null ),

    ("Timothée", "Chalamet", "Timothée Hal Chalamet (born December 27, 1995) is an American actor. He began his career appearing in the drama series Homeland in 2012. Two years later, he made his film debut in the comedy-drama Men, Women & Children and appeared in Christopher Nolan's science fiction film Interstellar. He came into attention in Luca Guadagnino's coming-of-age film Call Me by Your Name (2017). Alongside supporting roles in Greta Gerwig's films Lady Bird (2017) and Little Women (2019), he took on starring roles in Beautiful Boy (2018) and Dune (2021)."),
        ("Armie", "Hammer", "Armand Douglas 'Armie' Hammer (born August 28, 1986) is an American actor. After appearing on television and playing the title role in 2008's Billy: The Early Years, he became known for his portrayal of the Winklevoss twins in the 2010 film The Social Network. His notorious film roles include Clyde Tolson in J. Edgar, Prince Albert Alcott in Tarsem Singh's Snow White, and The Lone Ranger."),

    ("John", "Adams", "John Adams is an American musician, conductor, and music composer. Together with Steve Reich, Philip Glass and Terry Riley, he is one of the most famous representatives of minimal music."),

    ("Céline", "Sciamma", "Céline Sciamma is a French screenwriter and film director. Sciamma's work is strikingly minimalist, partly the legacy of her mentor, Xavier Beauvois, who advised her while she was a student at the major French film school, La Fémis."),

    ("Alain", "Chabat", "Alain Chabat (born 24 November 1958) is a French actor and director who appeared in La Cité de la peur, French Twist, The Taste of Others and The Science of Sleep."),

    ("Daniel", "Scheinert", "Daniel Scheinert is best known as the redneck half of the filmmaking duo DANIELS along with Daniel Kwan. Together, they've directed several award-winning music videos and commercials including the MTV VMA-winning video for DJ Snake and Lil' Jon's 'Turn Down For What,' as well as the dark comedy-drama Swiss Army Man and the absurdist science-fiction film Everything, Everywhere, All At Once, for which the duo received the Academy Awards for Best Picture, Best Director, and Best Original Screenplay."),

    ("Daniel", "Kwan", "Daniel Kwan is one half of the filmmaking duo known as DANIELS, along with Daniel Scheinert. Together, they've directed several award-winning music videos and commercials including the MTV VMA-winning video for DJ Snake and Lil' Jon's 'Turn Down For What,' as well as the dark comedy-drama Swiss Army Man and the absurdist science-fiction film Everything, Everywhere, All At Once, for which the duo received the Academy Awards for Best Picture, Best Director, and Best Original Screenplay."),

    ("Robert", "Eggers","Robert Houston Eggers (born July 7, 1983) is an American filmmaker and production designer. He is best known for writing and directing the historical horror films The Witch (2015) and The Lighthouse (2019), as well as directing and co-writing the historical fiction epic film The Northman (2022). His films are noted for their folkloric elements, as well as his efforts to ensure historical authenticity."),

    ("Louise", "Ford", null ),

    ("Angelo", "Badalamenti", "Angelo Badalamenti (March 22, 1937 - December 11, 2022) was an American composer, best known for his work scoring films for director David Lynch, notably Blue Velvet, the Twin Peaks saga (1990-1992, 2017), The Straight Story and Mulholland Drive. Badalamenti received the 1990 Grammy Award for Best Pop Instrumental Performance for his 'Twin Peaks Theme', and had received a Lifetime Achievement Award from the World Soundtrack Awards and the Henry Mancini Award from the American Society of Composers, Authors and Publishers."),

    ("Ari", "Aster", "Ari Aster (born July 15, 1986) is an American writer-director, best known for the acclaimed horror films 'Hereditary' (2018) and 'Midsommar' (2019). He has also written and directed several short films, including 'The Strange Thing About the Johnsons' (2011), 'Beau' (2011), 'Munchausen' (2013), and 'Basically' (2014)."),

    ("Bibi", "Andersson", "Berit Elisabet Andersson (11 November 1935 - 14 April 2019) or better known professionally as Bibi Andersson (Swedish: [ˈbɪ̂bːɪ ˈânːdɛˌʂɔn]), was a Swedish actress who was best known for her frequent collaborations with filmmaker Ingmar Bergman

    Her artistic dreams came early in life and were further supported by her older sister Gerd Andersson who became a ballet dancer at the Royal Opera and made her acting debut in 1951. Bibi, on the other hand, had to make do with bit parts and commercials. She debuted in Dum-Bom (1953), playing against Nils Poppe. Eventually, she was able to start at the Royal Dramatic Theatre's acting school in 1954. A brief relationship with Ingmar Bergman made her quit school and follow him to the Malmö city theater, where he was a director, performing in plays by August Strindberg and Hjalmar Bergman. Bergman also gave her a small part in his comedy Smiles of a Summer Night (1955), and larger roles in his Wild Strawberries (1957) and The Seventh Seal (1957). From the 1960s she got offers from abroad, with best result in I Never Promised You a Rose Garden (1977). During the civil war in Yugoslavia she has worked with several initiatives to give the people of Sarajevo theater and other forms of culture."),

    ("Liv", "Ullmann", "Liv Johanne Ullmann (born 16 December 1938) is a Norwegian actress and film director. Recognised as one of the greatest European actresses, Ullmann is known for her numerous acclaimed collaborations with filmmaker Ingmar Bergman.

    Ullmann won a Golden Globe Award for Best Actress - Motion Picture Drama in 1972 for the film The Emigrants (1971), and has been nominated for another four. In 2000, she was nominated for the Palme d'Or for her second directorial feature film, Faithless. She has also received two BAFTA Award nominations, for her performances in Scenes from a Marriage (1973) and Face to Face (1976), and two Academy Award nominations, for The Emigrants and Face to Face."),

    ("Noémie", "Merlant", "Noémie Merlant (born 27 November 1988) is a French actress. She has been nominated for her performances twice at the César Awards, including a nomination for her breakout role in Portrait of a Lady on Fire (2019)."),

    ("Adèle", "Haenel", "Adèle Haenel (born 11 February 1989) is a French actress. She is the recipient of several accolades, including two César Awards from seven nominations and one Lumières Award from two nominations.

    Haenel began her career as a child actress, making her film debut with Les Diables (2002) at the age of 12, and quickly rose to prominence in the French entertainment industry as a teenager. She received her first César Award nomination for her performance in Water Lilies (2007), which also marked the beginning of her long professional and personal relationship with director Céline Sciamma. In 2014, Haenel received her first César Award for her supporting role in Suzanne, and in 2015 won the César Award for Best Actress for Love at First Fight. She continued to garner recognition for her performances in BPM (Beats per Minute) (2017), The Trouble with You (2018) and Portrait of a Lady on Fire (2019)."),

    ("Christian", "Clavier", "Christian Clavier is a French actor, screenwriter, film producer and film director. He is the brother of French film director Stéphane Clavier.

    After his high class studies at the Neuilly Lycée Pasteur--though asserted here and there, he never studied at Institut d'Études Politiques de Paris (Sciences Po) --he started his actor career with the comedic theater troupe Splendid, which had hits with films like Les Bronzés font du ski and Le Père Noël est une ordure.

    His most notable success without the Splendid group, and by far his biggest hit to date, was in the 1993 film les Visiteurs, where he played a character known as Jacquouille la fripouille; the character's cry of 'Okkkayyy!!' became a popular exclamation after the movie's success.

    After les Visiteurs he was a certified star, participating in big-budget films like Astérix et Obélix contre César, Astérix & Obélix: Mission Cléopâtre, and the sequel and remake of Visiteurs. He also played several dramatic roles on television, including M. Thénardier in Les Misérables (2000 television version) and Napoléon in a biographical television film.

    Clavier has played in notable duos with: Jean Reno in les Visiteurs (the Visitors) and the US remake, Just Visiting, L'Opération Corned-Beef and L'Enquête corse (The Corsican investigation). Gérard Depardieu in Astérix et Obélix (Asterix and Obelix) and Les anges gardiens. He also runs a production company, Ouille Production.

    He was made Chevalier (Knight) of the Ordre national du Mérite on 13 June 1998, and promoted Officer (Officer) in 2005. He was made Chevalier (Knight) of the Légion d'honneur in 2008.

    He is a friend of former French président Nicolas Sarkozy, and recently emigrated to England as a result of Francois Hollande's punitive tax policy, mirrored in his Astérix co-star Gérard Depardieu's self-imposed exile to Belgium."),

    ("Gérard", "Depardieu", "Gérard Xavier Marcel Depardieu (born 27 December 1948) is a French actor, film-maker, businessman and vineyard owner. He is one of the most prolific character actors in film history, having completed approximately 170 movies since 1967. He has twice won the César Award for Best Actor as well as the Golden Globe award for Best Actor in Green Card. After he garnered huge critical acclaim for the title role in Cyrano de Bergerac, which landed him a nomination for an Academy Award, Depardieu acted in many big budget Hollywood movies. He is a Chevalier of the Légion d'honneur and Chevalier of the Ordre national du Mérite. He was granted citizenship of Russia in January 2013 and the same month became a cultural ambassador of Montenegro. In 2015 he left Russia declaring that he intends to give up the citizenship and to live in Belgium."),

    ("Jamel", "Debbouze", "Jamel Debbouze ( born 18 June 1975) is a French actor, comedian and producer of Moroccan descent."),

    ("Monica", "Bellucci", "Monica Anna Maria Bellucci (Italian: [ˈmɔːnika belˈluttʃi]; born 30 September 1964) is an Italian actress and model. She began her career as a fashion model, modeling for Dolce & Gabbana and Dior, before making a transition to Italian films and later American and French films.

    Bellucci played a Bride of Dracula in Francis Ford Coppola's gothic horror romance film Bram Stoker's Dracula (1992) and Malèna Scordia in the Italian-language romantic drama Malèna (2000). She was in the controversial Gaspar Noé arthouse horror film Irréversible (2002), and portrayed Mary Magdalene in Mel Gibson's biblical drama The Passion of the Christ (2004).

    In the 2003 science-fiction films The Matrix Reloaded and The Matrix Revolutions, she played Persephone. In the 2015 James Bond film Spectre, she became the oldest Bond girl in the history of the franchise."),

    ("Michelle", "Yeoh", "Michelle Yeoh Choo Kheng (born Yeoh Choo Kheng; 6 August 1962) is a Malaysian actress. Credited as Michelle Khan in her early films in Hong Kong, she rose to fame in the 1990s after starring in a series of Hong Kong action films where she performed her own stunts, such as Yes, Madam (1985), Magnificent Warriors (1987), Police Story 3: Supercop (1992), The Heroic Trio (1993), and Holy Weapon (1993).

    After moving to the United States, Yeoh gained recognition for starring in the James Bond film Tomorrow Never Dies (1997) and in Ang Lee's martial arts film Crouching Tiger, Hidden Dragon (2000), for which she was nominated for the BAFTA Award for Best Actress in a Leading Role. For her role as an overwhelmed mother navigating the multiverse in Everything Everywhere All at Once (2022) she won the Academy Award for Best Actress, becoming the first Asian woman to win the award. Yeoh's other works include Memoirs of a Geisha (2005), Sunshine (2007), The Mummy: Tomb of the Dragon Emperor (2008), Reign of Assassins (2010), Kung Fu Panda 2 (2011), and The Lady (2011), where she portrayed Aung San Suu Kyi. She played supporting roles in the romantic comedies Crazy Rich Asians (2018) and Last Christmas (2019), and the Marvel Cinematic Universe film Shang-Chi and the Legend of the Ten Rings (2021). On television, Yeoh has starred in Star Trek: Discovery (2017-2020) and The Witcher: Blood Origin (2022)."),

    ("Ke", "Huy Quan", "Ke Huy Quan (born August 20, 1971), also known as Jonathan Ke Quan, is an American actor. As a young actor, Quan rose to fame playing Short Round in Indiana Jones and the Temple of Doom (1984) and Data in The Goonies (1985).

    Following a few roles in the 1990s, Quan took an almost 20-year acting hiatus during which he worked as a stunt choreographer and assistant director. He returned to acting with the science fiction film Everything Everywhere All at Once (2022). His performance was widely praised and won him many accolades, including an Academy Award, Critics Choice, Golden Globe, Independent Spirit, and SAG Award."),

    ("Anya", "Taylor-Joy", "Anya-Josephine Marie Taylor-Joy (born 16 April 1996) is a British-American actress and model. She left school at age sixteen and began to pursue an acting career. After small television roles, she made her film debut with the lead role of Thomasin in the horror film The Witch (2015). She went on to star in the horror film Split and the black comedy Thoroughbreds (both 2017). She also appeared in the drama miniseries The Miniaturist (2017), the fifth and sixth series of Peaky Blinders (2019-2022) and The Dark Crystal: Age of Resistance (2019), and the superhero film Glass (2019), reprising her role from Split. Taylor-Joy will voice Princess Peach in the upcoming Mario film (2022) and portray the title character in Furiosa (2024)."),

    ("Sheryl", "Lee", "Sheryl Lee (born April 22, 1967) is an American actress. She came to international attention for her performances as Laura Palmer and Maddy Ferguson on the 1990 cult TV series Twin Peaks and in the 1992 film Twin Peaks: Fire Walk with Me. She is also known for portraying photographer Astrid Kirchherr in Backbeat (1994) and for her roles in Vampires (1998) and Winter's Bone (2010), as well as for her television series roles in LA Doctors, Kingpin, One Tree Hill and Dirty Sexy Money."),

    ("Ray", "Wise", "Raymond Nicolas 'Ray' Wise (born August 20, 1947) is an American actor, known for his roles as Leland Palmer in Twin Peaks, as Leon C. Nash, right-hand henchman to villain Clarence Boddicker in the science fiction classic RoboCop, and recently as the Devil in the CW television series Reaper."),

    ("Naomi", "Watts", "Naomi Ellen Watts (born 28 September 1968) is a British actress. After her family moved to Australia, she made her film debut there in the drama For Love Alone (1986) and then appeared in three television series, Hey Dad..! (1990), Brides of Christ (1991), and Home and Away (1991), and the film Flirting (1991). After moving to the United States, Watts initially struggled as an actress, taking roles in small-scale films until she starred in David Lynch's psychological thriller Mulholland Drive in 2001 as an aspiring actress. This role started her rise to international prominence.

    Watts then played a tormented journalist in the horror remake The Ring (2002). She was nominated for the Academy Award for Best Actress for her performance as a grief-stricken mother in Alejandro González Iñárritu's film 21 Grams (2003). Her profile continued to grow with starring roles in I Heart Huckabees (2004), King Kong (2005), Eastern Promises (2007), and The International (2009).

    For her role as Maria Bennett in the disaster film The Impossible (2012), Watts received another Academy Award nomination for Best Actress. In the 2010s, she starred in such films as Birdman (2014), St. Vincent (2014), While We're Young (2015), The Glass Castle (2017), and Luce (2019). Watts also continued to act in blockbusters, with appearances in the Divergent franchise (2015-2016), and she ventured into television with the Showtime mystery drama series Twin Peaks (2017) and the biographical limited series The Loudest Voice (2019).

    Watts is particularly known for her work in remakes and independent productions with dark or tragic themes, as well as portrayals of characters that endure loss or suffering."),

    ("Laura", "Harring", "Laura Harring (born Laura Elena Herring Martínez on March 3, 1964) is a Mexican actress and former Miss USA (1985). She is known for her role as Rita in Mulholland Drive."),

    ("Florence", "Pugh", "Florence Pugh (born 3 January 1996) is an English actress. She made her acting debut in 2014 in the drama film The Falling. Pugh gained recognition in 2016 for her leading role as a young bride in the independent drama Lady Macbeth, winning a British Independent Film Award. After starring in the 2018 television film King Lear, she drew praise for her leading role in the miniseries The Little Drummer Girl and earned a nomination for the BAFTA Rising Star Award that year.

    Pugh's international breakthrough came in 2019 with her portrayals of professional wrestler Paige in the biographical sports film Fighting with My Family, a despondent American woman in the horror film Midsommar, and Amy March in the period drama Little Women. For the last of these, she received nominations for an Academy Award and a BAFTA Award. Pugh was awarded the Trophée Chopard at the 2019 Cannes Film Festival. In 2021, she starred as Yelena Belova in the Marvel Cinematic Universe superhero film Black Widow and the Disney+ miniseries Hawkeye. She has since starred in the thriller Don't Worry Darling and the drama The Wonder (both 2022)."),

    ("Jack", "Reynor", "Jack Reynor (born January 23, 1992) is an Irish actor. Notable roles include a lead character in Lenny Abrahamson's critically acclaimed Irish film What Richard Did (2012), for which he won an IFTA Award for Best Film Actor, in Transformers: Age of Extinction, Gerard Barrett's film Glassland where Reynor won the World Cinema Dramatic Special Jury Award for Acting at the Sundance Film Festival, in Macbeth and lead role in Irish film Sing Street.");

-- 5. Gatunek_filmu
CREATE TABLE Gatunek_filmu(
	tytuł VARCHAR(255) NOT NULL,
   	rok_produkcji INT NOT NULL,
	nazwa VARCHAR(32) NOT NULL,
	PRIMARY KEY(tytuł, rok_produkcji, nazwa) -- jeden film moze nalezec do kilku gatunkow 
);

INSERT INTO Gatunek_filmu VALUES 
    ("Eraserhead", 1977, "fantasy"),
    ("Eraserhead", 1977, "horror"),
    ("Persona", 1966, "drama"),
    ("Call Me by Your Name", 2017, "drama"),
    ("Call Me by Your Name", 2017, "romance"),
    ("Portrait of a Lady on Fire", 2019, "drama"),
    ("Portrait of a Lady on Fire", 2019, "romance"),
    ("Asterix & Obelix: Mission Cleopatra", 2002, "comedy"),
    ("Asterix & Obelix: Mission Cleopatra", 2002, "family"),
    ("Asterix & Obelix: Mission Cleopatra", 2002, "adventure"),
    ("Asterix & Obelix: Mission Cleopatra", 2002, "fantasy"),
    ("Everything Everywhere All at Once", 2022, "adventure"),
    ("Everything Everywhere All at Once", 2022, "action"),
    ("Everything Everywhere All at Once", 2022, "science-fiction"),
    ("Midsommar", 2019, "drama"),
    ("Midsommar", 2019, "horror"),
    ("Midsommar", 2019, "mystery"),
    ("The Witch", 2015, "horror"),
    ("The Witch", 2015, "drama"),
    ("The Witch", 2015, "mystery"),
    ("The Witch", 2015, "fantasy"),
    ("Mulholland Drive", 2001, "thriller"),
    ("Mulholland Drive", 2001, "mystery"),
    ("Mulholland Drive", 2001, "drama"),
    ("Twin Peaks: Fire Walk with Me", 1992, "horror"),
    ("Twin Peaks: Fire Walk with Me", 1992, "drama"),
    ("Twin Peaks: Fire Walk with Me", 1992, "mystery");

-- 6. Motyw_filmu
CREATE TABLE Motyw_filmu(
	tytuł VARCHAR(255) NOT NULL,
   	rok_produkcji INT NOT NULL,
	nazwa VARCHAR(100) NOT NULL,
	PRIMARY KEY(tytuł, rok_produkcji, nazwa) -- jeden film moze nalezec do kilku motywow
);

INSERT INTO Motyw_filmu VALUES 
	("Eraserhead", 1977, "Weird, Surreal, Bizarre, Dream Or Confusing"),
	("Eraserhead", 1977, "Horror, Creepy, Eerie, Blood Or Gothic"),
	("Persona", 1966, "Humanity And The World Around Us"),
	("Call Me by Your Name", 2017, "Gay, Sexual, Relationships, Feelings Or Homophobic"),
	("Call Me by Your Name", 2017, "Emotional, Emotion, Family, Moving Or Feelings"),
	("Portrait of a Lady on Fire", 2019, "Artists, Biography, Musician, Songs Or Emotional"),
	("Portrait of a Lady on Fire", 2019, "Romance, Emotion, Relationships, Feelings Or Captivating"),
	("Asterix & Obelix: Mission Cleopatra", 2002, "Funny, Comedy, Humor, Jokes Or Hilarious"),
	("Asterix & Obelix: Mission Cleopatra", 2002, "Crude Humor And Satire"),
	("Everything Everywhere All at Once", 2022, "Martial Arts, Kung Fu, Choreography, Cool Or Action-Packed"),
	("Everything Everywhere All at Once", 2022, "Sci-Fi, Aliens, Space, Spaceship Or Earth"),
	("Midsommar", 2019, "Intense Violence And Sexual Transgression"),
	("Midsommar", 2019, "Horror, Gory, Scary, Killing Or Gruesome"),
	("The Witch", 2015, "Faith And Religion"),
	("The Witch", 2015, "Horror, Creepy, Eerie, Blood Or Gothic"),
	("Mulholland Drive", 2001, "Film Noir, Femme Fatale, 1940s, Thriller Or Intriguing"),
	("Mulholland Drive", 2001, "Thrillers And Murder Mysteries"),
	("Twin Peaks: Fire Walk with Me", 1992, "Weird, Surreal, Bizarre, Dream Or Confusing"),
	("Twin Peaks: Fire Walk with Me", 1992, "Violence And Sexual Transgression");

-- 7. Kraj_filmu
CREATE TABLE Kraj_filmu(
	tytuł VARCHAR(255) NOT NULL,
   	rok_produkcji INT NOT NULL,
	nazwa VARCHAR(32) NOT NULL,
	PRIMARY KEY(tytuł, rok_produkcji, nazwa) -- jeden film moze byc produkowany w kilku krajach
);

INSERT INTO Kraj_filmu VALUES 
	("Eraserhead", 1977, "USA"),
	("Persona", 1966, "Sweden"),
	("Call Me by Your Name", 2017, "Brazil"),
	("Call Me by Your Name", 2017, "USA"),
	("Call Me by Your Name", 2017, "France"),
	("Call Me by Your Name", 2017, "Italy"),
	("Portrait of a Lady on Fire", 2019, "France"),
	("Asterix & Obelix: Mission Cleopatra", 2002, "France"),
	("Asterix & Obelix: Mission Cleopatra", 2002, "Germany"),
	("Everything Everywhere All at Once", 2022, "USA"),
	("Midsommar", 2019, "Sweden"),
	("Midsommar", 2019, "USA"),
	("The Witch", 2015, "UK"),
	("The Witch", 2015, "Brazil"),
	("The Witch", 2015, "Canada"),
	("The Witch", 2015, "USA"),
	("Mulholland Drive", 2001, "France"),
	("Mulholland Drive", 2001, "USA"),
	("Twin Peaks: Fire Walk with Me", 1992, "France"),
	("Twin Peaks: Fire Walk with Me", 1992, "USA");

-- 8. Twórca_filmu
CREATE TABLE Twórca_filmu(
	tytuł VARCHAR(255) NOT NULL,
	rok_produkcji INT NOT NULL,
   	id_osoba INT NOT NULL,
	stanowisko VARCHAR(100) NOT NULL,
	PRIMARY KEY(tytuł, rok_produkcji, id_osoba, stanowisko) -- jedna osoba przy produkcji jednego filmu moze pracowac na kilku stanowiskach oraz jedno stanowisko moze obsadzac kilka róznych osób
);

INSERT INTO Twórca_filmu VALUES 
	("Asterix & Obelix: Mission Cleopatra", 2002, 15, "Director"),
	("Asterix & Obelix: Mission Cleopatra", 2002, 26, "Actor"),
	("Asterix & Obelix: Mission Cleopatra", 2002, 27, "Actor"),
	("Asterix & Obelix: Mission Cleopatra", 2002, 28, "Actor"),
	("Asterix & Obelix: Mission Cleopatra", 2002, 29, "Actress"),
    ("Call Me by Your Name", 2017, 9, "Director"),
	("Call Me by Your Name", 2017, 9, "Producer"),
	("Call Me by Your Name", 2017, 10, "Writer"),
	("Call Me by Your Name", 2017, 10, "Producer"),
    ("Call Me by Your Name", 2017, 11, "Cinematography"),
    ("Call Me by Your Name", 2017, 12, "Composer"),
	("Call Me by Your Name", 2017, 13, "Composer"),
    ("Call Me by Your Name", 2017, 39, "Actor"),
    ("Call Me by Your Name", 2017, 40, "Actor"),
    ("Eraserhead", 1977, 1, "Director"),
	("Eraserhead", 1977, 1, "Writer"),
    ("Eraserhead", 1977, 1, "Editor"),
	("Eraserhead", 1977, 2, "Sound"),
    ("Eraserhead", 1977, 3, "Actor"),
	("Eraserhead", 1977, 4, "Actress"),
    ("Eraserhead", 1977, 5, "Actor"),
    ("Eraserhead", 1977, 6, "Actress"),
    ("Persona", 1966, 7, "Director"),
	("Persona", 1966, 7, "Producer"),
    ("Persona", 1966, 7, "Writer"),
    ("Persona", 1966, 8, "Production Design"),
    ("Persona", 1966, 22, "Actress"),
    ("Persona", 1966, 23, "Actress"),
    ("Portrait of a Lady on Fire", 2019, 14, "Director"),
	("Portrait of a Lady on Fire", 2019, 14, "Writer"),
    ("Portrait of a Lady on Fire", 2019, 24, "Actress"),
    ("Portrait of a Lady on Fire", 2019, 25, "Actress"),
    ("Everything Everywhere All at Once", 2022, 16, "Director"),
	("Everything Everywhere All at Once", 2022, 17, "Director"),
    ("Everything Everywhere All at Once", 2022, 16, "Writer"),
    ("Everything Everywhere All at Once", 2022, 17, "Writer"),
    ("Everything Everywhere All at Once", 2022, 30, "Actress"),
    ("Everything Everywhere All at Once", 2022, 31, "Actor"),
    ("Midsommar", 2019, 21, "Director"),
	("Midsommar", 2019, 21, "Writer"),
    ("Midsommar", 2019, 37, "Actress"),
    ("Midsommar", 2019, 38, "Actor"),
    ("The Witch", 2015, 18, "Director"),
	("The Witch", 2015, 18, "Writer"),
    ("The Witch", 2015, 32, "Actress"),
    ("The Witch", 2015, 19, "Editor"),
    ("Mulholland Drive", 2001, 1, "Director"),
	("Mulholland Drive", 2001, 1, "Writer"),
    ("Mulholland Drive", 2001, 20, "Composer"),
	("Mulholland Drive", 2001, 35, "Actress"),
    ("Mulholland Drive", 2001, 36, "Actress"),
    ("Twin Peaks: Fire Walk with Me", 1992, 1, "Director"),
	("Twin Peaks: Fire Walk with Me", 1992, 1, "Writer"),
    ("Twin Peaks: Fire Walk with Me", 1992, 20, "Composer"),
    ("Twin Peaks: Fire Walk with Me", 1992, 33, "Actress"),
    ("Twin Peaks: Fire Walk with Me", 1992, 34, "Actor");

-- 9. Ocena
CREATE TABLE Ocena(
	tytuł VARCHAR(255) NOT NULL,
	rok_produkcji INT NOT NULL,
	login VARCHAR(20) NOT NULL,
	ocena ENUM("1","2","3","4","5"),
   	komentarz TEXT(5000),
	data DATE,
	PRIMARY KEY(tytuł, rok_produkcji, login) -- jeden film moze miec jedna ocene od konkretnego uzytkownika
);

INSERT INTO Ocena VALUES 
	("Persona", 1966, "MagdaKaczmarek555", "5", "so this is how men feel after watching fight club", '2023-05-19'),
	("Asterix & Obelix: Mission Cleopatra", 2002, "PiotrSzymański2022", "4", "alain chabat really said let me make an impact on french cinema real quick", '2023-04-05'),
	("Call My by Your Name", 2017, "KamilLewandowski77", "5", "my mum: wait is he gay", '2023-01-21'),
	("Midsommar", 2019, "OlaWiśniewska1990", "4", "i am SO glad ari aster clearly never went to therapy", '2022-05-19'),
	("Eraserhead", 1977, "AnnaKowalska87", "3", "the baby looks like an airpod", '2023-02-01');

-- 10. Lista
CREATE TABLE Lista(
	id_listy INT AUTO_INCREMENT NOT NULL UNIQUE,
    login VARCHAR(20) NOT NULL,
    nazwa_listy VARCHAR(32),
    opis TEXT(2000),
    PRIMARY KEY (id_listy) -- kazda lista ma inny identyfikator, a ich nazwy mogą się powtarzać, a jedna osoba moze miec kilka list
);

INSERT INTO Lista (login,nazwa_listy, opis) VALUES 
    ("AdrianKubiak1234", "Do obejrzenia", null),
    ("AdrianKubiak1234", "Obejrzane", null),
    ("AdrianKubiak1234", "Na profilu", null),
    ("AdrianKubiak1234", "Ulubione", null),

    ("AnnaKowalska87", "Do obejrzenia", null),
    ("AnnaKowalska87", "Obejrzane", null),
    ("AnnaKowalska87", "Na profilu", null),
    ("AnnaKowalska87", "Ulubione", null),
    
    ("DamianJankowski22", "Do obejrzenia", null),
    ("DamianJankowski22", "Obejrzane", null),
    ("DamianJankowski22", "Na profilu", null),
    ("DamianJankowski22", "Ulubione", null),
    ("DamianJankowski22", "klasyki lyncha", "najlepsze filmy davida lyncha"),

    ("JanNowak123", "Do obejrzenia", null),
    ("JanNowak123", "Obejrzane", null),
    ("JanNowak123", "Na profilu", null),
    ("JanNowak123", "Ulubione", null),
    
    ("KamilLewandowski77", "Do obejrzenia", null),
    ("KamilLewandowski77", "Obejrzane", null),
    ("KamilLewandowski77", "Na profilu", null),
    ("KamilLewandowski77", "Ulubione", null),

    ("KarolinaWójcik19", "Do obejrzenia", null),
    ("KarolinaWójcik19", "Obejrzane", null),
    ("KarolinaWójcik19", "Na profilu", null),
    ("KarolinaWójcik19", "Ulubione", null),

    ("MagdaKaczmarek555", "Do obejrzenia", null),
    ("MagdaKaczmarek555", "Obejrzane", null),
    ("MagdaKaczmarek555", "Na profilu", null),
    ("MagdaKaczmarek555", "Ulubione", null),
    
    ("MartaZielińska2023", "Do obejrzenia", null),
    ("MartaZielińska2023", "Obejrzane", null),
    ("MartaZielińska2023", "Na profilu", null),
    ("MartaZielińska2023", "Ulubione", null),
    ("MartaZielińska2023", "horror new wave", "horrory po 2014 roku, które podchodzą na nowy sposób do wywołania grozy u widza"),

    ("OlaWiśniewska1990", "Do obejrzenia", null),
    ("OlaWiśniewska1990", "Obejrzane", null),
    ("OlaWiśniewska1990", "Na profilu", null),
    ("OlaWiśniewska1990", "Ulubione", null),
    ("OlaWiśniewska1990", "moje ulubione romanse", null),

    ("PiotrSzymański2022", "Do obejrzenia", null),
    ("PiotrSzymański2022", "Obejrzane", null),
    ("PiotrSzymański2022", "Na profilu", null),
    ("PiotrSzymański2022", "Ulubione", null);

-- 11. Dodanie_do_listy
CREATE TABLE Dodanie_do_listy(
    id_listy INT NOT NULL,
    login VARCHAR(20) NOT NULL,
    tytuł VARCHAR(255) NOT NULL,
    rok_produkcji INT NOT NULL,
    PRIMARY KEY (id_listy,tytuł,rok_produkcji, login) -- nie jest to optymalne, ale z racji ze jest to relacja miedzy trzema encjami, to klucz kazdej encji musi byc kluczem tej relacji
);

INSERT INTO Dodanie_do_listy VALUES 
	(10,"DamianJankowski22","Eraserhead", 1977),
	(10,"DamianJankowski22","Twin Peaks: Fire Walk with Me", 1992),
	(10,"DamianJankowski22","Mulholland Drive", 2001),

	(11,"DamianJankowski22","Twin Peaks: Fire Walk with Me", 1992),

	(12,"DamianJankowski22","Eraserhead", 1977),
	(12,"DamianJankowski22","Twin Peaks: Fire Walk with Me", 1992),
	(12,"DamianJankowski22","Mulholland Drive", 2001),

	(13,"DamianJankowski22","Eraserhead", 1977),
	(13,"DamianJankowski22","Twin Peaks: Fire Walk with Me", 1992),
	(13,"DamianJankowski22","Mulholland Drive", 2001),

	(31,"MartaZielińska2023","Midsommar",2019),
    (34,"MartaZielińska2023","Midsommar",2019),
	(31,"MartaZielińska2023","The Witch",2015),
	(34,"MartaZielińska2023","The Witch",2015),

	(36,"OlaWiśniewska1990","Call Me by Your Name",2017),
	(37,"OlaWiśniewska1990","Call Me by Your Name",2017),
	(38,"OlaWiśniewska1990","Call Me by Your Name",2017),
	(39,"OlaWiśniewska1990","Call Me by Your Name",2017),
	(36,"OlaWiśniewska1990","Portrait of a Lady on Fire",2019),
	(37,"OlaWiśniewska1990","Portrait of a Lady on Fire",2019),
	(38,"OlaWiśniewska1990","Portrait of a Lady on Fire",2019),
	(39,"OlaWiśniewska1990","Portrait of a Lady on Fire",2019),
    
	(18,"KamilLewandowski77","Twin Peaks: Fire Walk with Me", 1992);