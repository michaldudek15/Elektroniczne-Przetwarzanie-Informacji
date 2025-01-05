<?php
    session_start(); 

    include 'autoryzacja.php';
    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    if (isset($_POST['tytul']) ) {
        $result = mysqli_query($conn, "SELECT * FROM projekt_gry WHERE tytuł LIKE '".$_POST['tytul']."' AND id_użytkownika = '".$_SESSION['id']."';");
        echo '<table border = 1>';
        echo '<tr>';
        echo '<th>tytuł</th>';
        echo '<th>rok_wydania</th>';
        echo '<th>platforma</th>';
        echo '<th>ocena</th>';
        echo '<th>data</th>';
        echo '</tr>';

        while ($row = mysqli_fetch_array($result)) {
            echo '<tr>';
            echo '<td>'.$row['tytuł'].'</td>';
            echo '<td>'.$row['rok_wydania'].'</td>';
            echo '<td>'.$row['platforma'].'</td>';
            echo '<td>'.$row['ocena'].'</td>';
            echo '<td>'.$row['data'].'</td>';
            echo '<td><a href = "gry_zmien.php?zmien='.$row['id_gra'].'">zmień</a></td>';
            echo '<td><a href = "gry.php?usun='.$row['id_gra'].'">usuń</a></td>';
            echo '</tr>';
        }
        echo '</table>';
        echo '<br>';
    }
?>

<html>
	<head>
		<meta charset="UTF-8">  
        <link rel="stylesheet" href="style.css">
	</head>

	<body>
		<div>
            <form action="gry_szukaj.php" method="post">
                    podaj tytuł: <input type="text" name="tytul" required><br>
                    <input type="submit" value="szukaj">
                    <input type="reset" value="wyczyść">
            </form>
            <a href = "gry.php">wróć do listy</a>
        </div>
	</body>
</html>
