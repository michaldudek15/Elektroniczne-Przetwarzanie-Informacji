<?php
    session_start(); 

    include 'autoryzacja.php';
    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    # robię to w ten sposób, bo po kliknięciu sumbit na tej stronie tracę zmienną $_GET['zmien'], w której trzymam ID tego, co chcę edytować
    if (isset($_GET['zmien'])) {
        $_SESSION['zmien'] = $_GET['zmien'];
    }

    if (isset($_POST['tytul']) && !empty($_POST['tytul'])) {
        mysqli_query($conn, "UPDATE projekt_książki SET tytuł = '".$_POST['tytul']."' WHERE id_książka = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['rok_wydania']) && !empty($_POST['rok_wydania'])) {
        mysqli_query($conn, "UPDATE projekt_książki SET rok_wydania = ".$_POST['rok_wydania']." WHERE id_książka = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['autor']) && !empty($_POST['autor'])) {
        mysqli_query($conn, "UPDATE projekt_książki SET autor = '".$_POST['autor']."' WHERE id_książka = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['ocena']) && !empty($_POST['ocena'])) {
        mysqli_query($conn, "UPDATE projekt_książki SET ocena = ".$_POST['ocena']." WHERE id_książka = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['data']) && !empty($_POST['data'])) {
        mysqli_query($conn, "UPDATE projekt_książki SET data = '".$_POST['data']."' WHERE id_książka = '".$_SESSION['zmien']."'");
    }

    if (!isset($_GET['zmien'])) {
        unset($_SESSION['zmien']);
        header('location: ksiazki.php');
    }
?>

<html>
	<head>
		<meta charset="UTF-8">  
        <link rel="stylesheet" href="style.css">
	</head>

	<body>
        <div>
            <form action="ksiazki_zmien.php" method="post">
                podaj tytuł: <input type="text" name="tytul"><br>
                podaj rok wydania: <input type="number" max="3000" min="1500" name="rok_wydania"><br>
                podaj autora: <input type="text" name="autor"><br>
                jak oceniasz tę książkę? <input type="number" max="10" min="1" name="ocena"><br>
                kiedy ją przeczytałeś? <input type="date" max='3000-01-01' name="data"><br>
                <input type="submit" value="edytuj">
                <input type="reset" value="wyczyść">
            </form>
            <a href = "ksiazki.php">wróć do listy</a>
        </div>
	</body>
</html>
