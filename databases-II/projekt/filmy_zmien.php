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
        mysqli_query($conn, "UPDATE projekt_filmy SET tytuł = '".$_POST['tytul']."' WHERE id_film = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['rok_produkcji']) && !empty($_POST['rok_produkcji'])) {
        mysqli_query($conn, "UPDATE projekt_filmy SET rok_produkcji = ".$_POST['rok_produkcji']." WHERE id_film = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['rezyseria']) && !empty($_POST['rezyseria'])) {
        mysqli_query($conn, "UPDATE projekt_filmy SET reżyseria = '".$_POST['rezyseria']."' WHERE id_film = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['ocena']) && !empty($_POST['ocena'])) {
        mysqli_query($conn, "UPDATE projekt_filmy SET ocena = ".$_POST['ocena']." WHERE id_film = '".$_SESSION['zmien']."'");
    }

    if (isset($_POST['data']) && !empty($_POST['data'])) {
        mysqli_query($conn, "UPDATE projekt_filmy SET data = '".$_POST['data']."' WHERE id_film = '".$_SESSION['zmien']."'");
    }

    if (!isset($_GET['zmien'])) {
        unset($_SESSION['zmien']);
        header('location: filmy.php');
    }

    

?>

<html>
	<head>
		<meta charset="UTF-8">    	
        <link rel="stylesheet" href="style.css">
	</head>

	<body>
        <div>
		<form action="filmy_zmien.php" method="post">
                podaj tytuł: <input type="text" name="tytul"><br>
                podaj rok produkcji: <input type="number" max="3000" min="1500" name="rok_produkcji"><br>
                podaj reżysera: <input type="text" name="rezyseria"><br>
                jak oceniasz ten film? <input type="number" max="10" min="1" name="ocena"><br>
                kiedy go obejrzałeś? <input type="date" max='3000-01-01' name="data"><br>
                <input type="submit" value="edytuj">
                <input type="reset" value="wyczyść">
        </form>
        <a href = "filmy.php">wróć do listy</a>
    </div>
	</body>
</html>
