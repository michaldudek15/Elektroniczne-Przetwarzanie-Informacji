<?php
    session_start();
    if (!isset($_SESSION['zalogowany'])) {
        header('location: index.php');
        exit();
    }

    include 'autoryzacja.php';

    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    echo "hej, ".$_SESSION['user'];
?>

<html>
    <head>
        <meta charset = "UTF-8">
        <link rel="stylesheet" href="teststyle.css">
    </head>
    <body>

        <div id = "wyloguj">
            <a href = 'wyloguj.php'>wyloguj</a>
        </div>

        <div id = "kategorie">
            <a class = "kategoria" href = "filmy.php">
                <div >
                    FILMY
                </div>
            </a>

            <a class = "kategoria" href = "gry.php">
                <div >
                    GRY
                </div>
            </a>

            <a class = "kategoria" href = "ksiazki.php">
                <div >
                    KSIĄŻKI
                </div>
            </a>
        </div>
    </body>
</html>