<?php
    session_start();

    if (!isset($_POST['login']) || (!isset($_POST['haslo']))) {
        header('location: index.php');
        exit();
    }

    include 'autoryzacja.php';

    $conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname) 
    or die('connection failed: '.mysqli_connect_error());

    $login = $_POST['login'];
    $haslo = $_POST['haslo'];

    # zabezpieczenie przed wykonywaniem js albo tagów html przez użytkowników
    $login = htmlentities($login, ENT_QUOTES, "UTF-8");
    $haslo = htmlentities($haslo, ENT_QUOTES, "UTF-8");
    
    # $conn - identyfikator połączenia
    # $login i $haslo - ciągi znaków, które chcemy zabezpieczyć przed próbą oszukania
    if ($rezultat = $conn->query(
        sprintf("SELECT * FROM projekt_użytkownicy WHERE user = '%s' AND password = '%s'",
        mysqli_real_escape_string($conn, $login),
        mysqli_real_escape_string($conn, $haslo)))) {

        $ilu_userow = $rezultat->num_rows;
        
        if ($ilu_userow > 0) {
            $_SESSION['zalogowany'] = true;
            $wiersz = $rezultat->fetch_assoc(); 
            $_SESSION['id'] = $wiersz['id'];
            $_SESSION['user'] = $wiersz['user'];
            
            unset($_SESSION['blad']);
            header('location: main.php');
        } 
        else {
            $_SESSION['blad'] = '<span style="color:red">nieprawidlowy login lub haslo</span>';
            header('location: index.php');
        }
    }
?>