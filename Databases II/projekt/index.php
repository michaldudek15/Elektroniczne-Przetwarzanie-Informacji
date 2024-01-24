<?php   
    session_start();

    if (isset($_SESSION['zalogowany']) && ($_SESSION['zalogowany'] == true)) {
        header('location: main.php');
        exit();
    }
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>projekt Michał Dudek</title>
</head>
<body>

    <div id = "logowanie">
        <form action = "zaloguj.php" method = "post">
            login: <br> <input type = "text" name = "login"> <br>
            hasło: <br> <input type = "password" name = "haslo"> <br>
            <input type = "submit" value = "zaloguj">
        </form>
        <a href = "rejestracja.php">zarejestruj się</a><br>
    </div>

    <?php
        if (isset($_SESSION['blad'])) {
            echo $_SESSION['blad'];
        }
    ?>

</body>
</html>