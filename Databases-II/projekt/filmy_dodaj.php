<?php
    session_start(); 

    include 'autoryzacja.php';
    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    if (isset($_POST['data'])) {
        mysqli_query($conn, "INSERT INTO projekt_filmy (tytuł, rok_produkcji, reżyseria, ocena, data, id_użytkownika) VALUES ('".$_POST['tytul']."', ".$_POST['rok_produkcji'].", '".$_POST['rezyseria']."', ".$_POST['ocena'].", '".$_POST['data']."', ".$_SESSION['id'].");");
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
            <form action="filmy_dodaj.php" method="post">
                    podaj tytuł: <input type="text" name="tytul" required><br>
                    podaj rok produkcji: <input type="number" max="3000" min="1500" name="rok_produkcji" required><br>
                    podaj reżysera: <input type="text" name="rezyseria" required><br>
                    jak oceniasz ten film? <input type="number" max="10" min="1" name="ocena" required><br>
                    kiedy go obejrzałeś? <input type="date" max='3000-01-01' name="data" required><br>
                    <input type="submit" value="dodaj">
                    <input type="reset" value="wyczyść">
            </form>
            <a href = "filmy.php">wróć do listy</a>
        </div>
	</body>
</html>
