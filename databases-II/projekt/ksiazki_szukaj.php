<?php
    session_start(); 

    include 'autoryzacja.php';
    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    if (isset($_POST['tytul']) ) {
        $result = mysqli_query($conn, "SELECT * FROM projekt_książki WHERE tytuł LIKE '".$_POST['tytul']."' AND id_użytkownika = '".$_SESSION['id']."';");

        echo '<table border = 1>';
        echo '<tr>';
        echo '<th>tytuł</th>';
        echo '<th>rok_wydania</th>';
        echo '<th>autor</th>';
        echo '<th>ocena</th>';
        echo '<th>data</th>';
        echo '</tr>';

        while ($row = mysqli_fetch_array($result)) {
            echo '<tr>';
            echo '<td>'.$row['tytuł'].'</td>';
            echo '<td>'.$row['rok_wydania'].'</td>';
            echo '<td>'.$row['autor'].'</td>';
            echo '<td>'.$row['ocena'].'</td>';
            echo '<td>'.$row['data'].'</td>';
            echo '<td><a href = "ksiazki_zmien.php?zmien='.$row['id_książka'].'">zmień</a></td>';
            echo '<td><a href = "ksiazki.php?usun='.$row['id_książka'].'">usuń</a></td>';
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
            <form action="ksiazki_szukaj.php" method="post">
                    podaj tytuł: <input type="text" name="tytul" required><br>
                    <input type="submit" value="szukaj">
                    <input type="reset" value="wyczyść">
            </form>
            <a href = "ksiazki.php">wróć do listy</a>
        </div>
	</body>
</html>
