<?php
    session_start(); 

    include 'autoryzacja.php';
    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    if (isset($_GET['potwierdz'])){
        mysqli_query($conn, "DELETE FROM projekt_filmy WHERE id_film=".$_GET['potwierdz'].";"); 
        unset($_GET['potwierdz']);
        header('location: filmy.php');
    }
?>

<html>
    <head>
        <meta charset = "UTF-8">
        <link rel="stylesheet" href="style3.css">        
    </head>
    <body>
        <?php
            $result = mysqli_query($conn, "SELECT * FROM projekt_filmy WHERE id_użytkownika=".$_SESSION['id'].";");

            echo '<table border = 1>';
            echo '<tr>';
            echo '<th>tytuł</th>';
            echo '<th>rok_produkcji</th>';
            echo '<th>reżyseria</th>';
            echo '<th>ocena</th>';
            echo '<th>data</th>';
            echo '</tr>';

            while ($row = mysqli_fetch_array($result)) {
                echo '<tr>';
                echo '<td>'.$row['tytuł'].'</td>';
                echo '<td>'.$row['rok_produkcji'].'</td>';
                echo '<td>'.$row['reżyseria'].'</td>';
                echo '<td>'.$row['ocena'].'</td>';
                echo '<td>'.$row['data'].'</td>';
                echo '<td><a href = "filmy_zmien.php?zmien='.$row['id_film'].'">edytuj</a></td>';
                
                if (isset($_GET['usun']) && $row['id_film'] == $_GET['usun']) {
                    echo '<td><a href = "filmy.php?potwierdz='.$row['id_film'].'">POTWIERDŹ</a></td>';
                }
                else {
                    echo '<td><a href = "filmy.php?usun='.$row['id_film'].'">usuń</a></td>';

                }
                echo '</tr>';
            }
            echo '</table>';
            echo '<br>';
        ?>
    <div class = "sterowanie">
        <a href = "main.php">powrót</a><br>
        <a href = "filmy_dodaj.php">dodaj nowy film</a><br>
        <a href = "filmy_szukaj.php">przeszukaj listę</a>
    </div>
    </body>
</html>