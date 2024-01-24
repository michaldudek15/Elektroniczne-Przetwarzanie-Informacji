<?php   
    session_start(); 
    include 'autoryzacja.php';

    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());
 
    if (isset($_POST['haslo1'])) {
        $wszystko_ok = true;

        $login = $_POST['login'];
        if (strlen($login) < 3 || strlen($login) > 20) {
            $wszystko_ok = false;
            $_SESSION['error_login'] = "login musi mieć od 3 do 20 znaków";
        }
    
        if (ctype_alnum($login) == false) {
            $wszystko_ok = false;
            $_SESSION['error_login'] = "login może mieć tylko litery i cyfry (bez polskich znaków)";
        }

        $haslo1 = $_POST['haslo1'];
        $haslo2 = $_POST['haslo2'];

        if (strlen($haslo1) < 4 || strlen($haslo1) > 20) {
            $wszystko_ok = false;
            $_SESSION['error_haslo'] = "hasło musi mieć od 4 do 20 znaków";
        }

        if ($haslo1 != $haslo2) {
            $wszystko_ok = false;
            $_SESSION['error_haslo'] = "podane hasła nie są identyczne";
        }

        $rezultat = $conn->query("SELECT id FROM projekt_użytkownicy where user='$login'");
        $ile_loginow = $rezultat->num_rows;
        
        if ($ile_loginow > 0) {
            $wszystko_ok = false;
            $_SESSION['error_login'] = "login jest już zajęty";
        }

        if ($wszystko_ok == true) {
            $conn->query("INSERT INTO projekt_użytkownicy (user, password) VALUES ('$login', '$haslo1')");
            $_SESSION['udana_rejestracja'] = true;
            header('location: welcome.php');
        }
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
    
    <div id = "rejestracja">
        <form method = "post">
            login: <br> <input type = "text" name = "login" > <br>

            <?php
                if (isset($_SESSION['error_login'])) {
                    echo '<div class = "error">'.$_SESSION['error_login'].'</div>';
                    unset($_SESSION['error_login']);
                }
            ?>
            hasło: <br> <input type = "password" name = "haslo1"><br>

            <?php
                if (isset($_SESSION['error_haslo'])) {
                    echo '<div class = "error">'.$_SESSION['error_haslo'].'</div>';
                    unset($_SESSION['error_haslo']);
                }
            ?>
            powtórz hasło: <br> <input type = "password" name = "haslo2"><br>
            
            <input type = "submit" value = "zarejestruj się">
        </form>
        <a href = "index.php"> powrót </a>
    </div>
</body>
</html>