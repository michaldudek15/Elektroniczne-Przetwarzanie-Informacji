const map = L.map('map').setView([50.0507,19.9451], 15);

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);

const rannyPtaszek = L.marker([50.05034,19.94102]).addTo(map);
rannyPtaszek.bindPopup(
    "<b>Ranny Ptaszek</b><br>Augustiańska 5<br><a id='link2a' href='#rannyPtaszek'>WIĘCEJ</a>"
).openPopup();

const skalka = L.marker([50.04821,19.93763]).addTo(map);
skalka.bindPopup(
    "<b>Bazylika św. Michała Archanioła i św. Stanisława w Krakowie</b><br>Skałeczna 15<br><a id='link3a'href='#bazylikaNaSkalce'>WIĘCEJ</a>"
).openPopup();

const balon = L.marker([50.04595,19.93599]).addTo(map);
balon.bindPopup(
    "<b>balon widokowy </b><br>Marii Konopnickiej, Bulwar Wołyński 28<br><a id='link4a' href='#balonWidokowy'>WIĘCEJ</a>"
).openPopup();

const losGorditos = L.marker([50.0487609, 19.9421862]).addTo(map);
losGorditos.bindPopup(
    "<b>Los Gorditos</b><br>Augustiańska 24/LU2<br><a id='link5a' href='#losGorditos'>WIĘCEJ</a>"
).openPopup();

const kosciol = L.marker([50.04977,19.94498]).addTo(map);
kosciol.bindPopup(
    "<b>Kosciół Bożego Ciała</b><br>Bożego Ciała 26<br><a id='link6a' href='#kosciolBozegoCiala'>WIĘCEJ</a>"
).openPopup();

const muzeum = L.marker([50.04951,19.94730]).addTo(map);
muzeum.bindPopup(
    "<b>Muzeum Inżynierii i Techniki</b><br>Świętego Wawrzyńca 15<br><a id='link7a' href='#muzeum'>WIĘCEJ</a>"
).openPopup();

const cytat = L.marker([50.05271,19.94493]).addTo(map);
cytat.bindPopup(
    "<b>Cytat Café</b><br>Miodowa 23<br><a id='link8a' href='#cytatCafe'>WIĘCEJ</a>"
).openPopup();

const ulicaSzeroka = L.marker([50.05315,19.94736]).addTo(map);
ulicaSzeroka.bindPopup(
    "<b>ulica Szeroka</b><br><a id='link9a' href='#ulicaSzeroka'>WIĘCEJ</a>"
).openPopup();

const staraSynagoga = L.marker([50.05140,19.94858]).addTo(map);
staraSynagoga.bindPopup(
    "<b>Stara Synagoga</b><br>Szeroka 24<br><a id='link10a' href='#staraSynagoga'>WIĘCEJ</a>"
).openPopup();

const okraglak = L.marker([50.05169,19.94494]).addTo(map);
okraglak.bindPopup(
    "<b>Okrąglak</b><br>Estery 46<br><a id='link11a' href='#okraglak'>WIĘCEJ</a>"
).openPopup();

const kolorki = L.marker([50.05196,19.94537]).addTo(map);
kolorki.bindPopup(
    "<b>Les Couleurs</b><br>Estery 10<br><a id='link12a' href='#lesCouleurs'>WIĘCEJ</a>"
).openPopup();

const popup = L.popup()
    .setLatLng([50.05052, 19.94399])
    .setContent("aby uzyskać więcej informacji wybierz jedną z pinezek")
    .openOn(map);
