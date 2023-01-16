const map = L.map('map').setView([50.0507,19.9451], 15);

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);

const losGorditos = L.marker([50.0487609, 19.9421862]).addTo(map);
losGorditos.bindPopup("<b>Los Gorditos</b><br>restauracja z kuchnią tex-mex <a href='opisy.html'>WIĘCEJ</a>").openPopup();

const skalka = L.marker([50.04821,19.93763]).addTo(map);
skalka.bindPopup("<b>Bazylika św. Michała Archanioła i św. Stanisława w Krakowie</b><br>XI-wieczny kościół oraz klasztor paulinów, nazywany często kościołem Na Skałce <a href='opisy.html'>WIĘCEJ</a>").openPopup();

const ulicaSzeroka = L.marker([50.05315,19.94736]).addTo(map);
ulicaSzeroka.bindPopup("<b>ulica Szeroka</b><br>główna ulica Żydowskiego Kazimierza, przy której znajduje się najstarsza krakowska synagoga <a href='opisy.html'>WIĘCEJ</a>").openPopup();

const staraSynagoga = L.marker([50.05140,19.94858]).addTo(map);
staraSynagoga.bindPopup("<b>Stara Synagoga</b><br>najstarsza krakowska synagoga, muzeum dziejów i kultury Żydów <a href='opisy.html'>WIĘCEJ</a>").openPopup();

const okraglak = L.marker([50.05169,19.94494]).addTo(map);
okraglak.bindPopup("<b>Okrąglak</b><br>centrum Placu Nowego, w ciągu dnia miejsce targowisk, wieczorem punkt sprzedaży popularnych zapiekanek <a href='opisy.html'>WIĘCEJ</a>").openPopup();

const rannyPtaszek = L.marker([50.05034,19.94102]).addTo(map);
rannyPtaszek.bindPopup("<b>Ranny Ptaszek</b><br>popularny lokal serwujący śniadania <a href='opisy.html'>WIĘCEJ</a>").openPopup();

const muzeum = L.marker([50.04951,19.94730]).addTo(map);
muzeum.bindPopup("<b>Muzeum Inżynierii i Techniki</b><br>muzeum w budynku dawnej zajezdni, gromadzi eksponaty związane z rozwojem komunikacji miejskiej, elektrowni, gazownictwa, gospodarki komunalnej oraz zabytki historii techniki <a href='opisy.html" +
    "'>WIĘCEJ</a>").openPopup();

const cytat = L.marker([50.05271,19.94493]).addTo(map);
cytat.bindPopup("<b>Cytat Café</b><br>kawiarnia zapełniona książkami <a href='opisy.html'>WIĘCEJ</a>").openPopup();


const popup = L.popup()
    .setLatLng([50.05052, 19.94399])
    .setContent("aby uzyskać więcej informacji kliknij na jednej z pinezek")
    .openOn(map);

const element = document.querySelector('#lewyPanel');

losGorditos.addEventListener('click', () => {
    element.innerHTML = '<h2> Los Gorditos </h2>' +
        'restauracja z kuchnią tex-mex';
});