<?php
    session_start(); 
    include 'autoryzacja.php';
    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    if (isset($_GET['potwierdz'])){
        mysqli_query($conn, "DELETE FROM projekt_książki WHERE id_książka=".$_GET['potwierdz'].";"); 
        unset($_GET['potwierdz']);
        header('location: ksiazki.php');
    }
?>

<html>
    <head>
        <meta charset = "UTF-8">
        <link rel="stylesheet" href="style3.css">
    </head>
    <body>
        <?php
        $result = mysqli_query($conn, "SELECT * FROM projekt_książki WHERE id_użytkownika=".$_SESSION['id'].";");
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
            echo '<td><a href = "ksiazki_zmien.php?zmien='.$row['id_książka'].'">edytuj</a></td>';
            
            if (isset($_GET['usun']) && $row['id_książka'] == $_GET['usun']) {
                echo '<td><a href = "ksiazki.php?potwierdz='.$row['id_książka'].'">POTWIERDŹ</a></td>';
            }
            else {
                echo '<td><a href = "ksiazki.php?usun='.$row['id_książka'].'">usuń</a></td>';
            }            
            echo '</tr>';
        }
        echo '</table>';
        echo '<br>';
        ?>
        <div class = "sterowanie">
            <a href = "main.php">powrót</a><br>
            <a href = "ksiazki_dodaj.php">dodaj nową książkę</a><br>
            <a href = "ksiazki_szukaj.php">przeszukaj listę</a>
        </div>
    </body>
</html>