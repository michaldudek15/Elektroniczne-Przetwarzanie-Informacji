<?php
    session_start(); 

    include 'autoryzacja.php';
    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    if (isset($_POST['data'])) {
        mysqli_query($conn, "INSERT INTO projekt_gry (tytuł, rok_wydania, platforma, ocena, data, id_użytkownika) VALUES ('".$_POST['tytul']."', ".$_POST['rok_wydania'].", '".$_POST['platforma']."', ".$_POST['ocena'].", '".$_POST['data']."', ".$_SESSION['id'].");");
        echo "udało ci się dodać ".$_POST['tytul']." do swojej listy";
    }
?>

<html>
	<head>
		<meta charset="UTF-8">   
        <link rel="stylesheet" href="style.css">
	</head>

	<body>
		<div>
        <form action="gry_dodaj.php" method="post">
                podaj tytuł: <input type="text" name="tytul" required><br>
                podaj rok wydania: <input type="number" max="3000" name="rok_wydania" required><br>
                na jakiej platformie grałeś? <input type="text" name="platforma" required><br>
                jak oceniasz tę grę? <input type="number" max="10" min="1" name="ocena" required><br>
                kiedy ją skończyłeś? <input type="date" max='3000-01-01' name="data" required><br>
                <input type="submit" value="dodaj">
                <input type="reset" value="wyczyść">
        </form>
        <a href = "gry.php">wróć do listy</a>
    </div>
	</body>
</html>
