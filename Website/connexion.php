<?php
session_start();
function Redirect($url){
  header('Location: ' . $url);
  exit();
}
 ?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <title>Generateur de phrases</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <link href="https://mdbootstrap.com/previews/docs/latest/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="text-center">
  <div class="col-xl-3 col-lg-3 col-md-3 col-sm-12 col-xs-12">
    <form class="form-signin" method="post">
      <a href="generateur.php"><h1 class="h1 font-weight-bold">Phrasonator</h1></a>
        <h1 class="h1 font-weight-bold"></h1>
        <h2 class="h3 mb-3 font-weight-normal">Connexion</h2>
        <label for="inputPseudo" class="sr-only">Pseudo</label>
        <input type="text" id="inputPseudo" name="inputPseudo" class="form-control" placeholder="Nom d'utilisateur" required autofocus>
        <label for="inputPassword" class="sr-only">Password</label>
        <input type="password" id="inputPassword" name="inputPassword" class="form-control" placeholder="Password" required>
        <button class="btn btn-lg btn-primary btn-block" name="submit" type="submit">Connexion</button>
        <a class="dropdown-item" href="inscription.php">Nouveau? Inscrivez-vous</a>
      </form>
  </div>
  <?php
  if(isset($_POST["submit"])){
    $hostname='localhost';
    $username='root';
    $password='';
    try {
      $dbh = new PDO("mysql:host=$hostname;dbname=generateur",$username,$password);
      $requete="SELECT count(*) from utilisateur where Utilisateur='".$_POST['inputPseudo']."' and Motdepasse='".$_POST['inputPassword']."';";
      $sql="SELECT * from utilisateur where Utilisateur='".$_POST['inputPseudo']."' and Motdepasse='".$_POST['inputPassword']."';";
      $result=$dbh->query($requete);
      if ($result->fetch()[0]>0) {

        foreach($dbh->query($sql) as $row){
          $_SESSION['idUtilisateur']=$row['idUtilisateur'];
          $_SESSION['Utilisateur']=$row['Utilisateur'];
          $_SESSION['Nom']=$row['Nom'];
          $_SESSION['Prenom']=$row['Prenom'];
          $_SESSION['Age']=$row['Age'];
        }
        $url="generateur1.php";
        Redirect($url);
      }
      else{
        echo "<script type= 'text/javascript'>alert('Connexion echoué.');</script>";
      }

      $dbh = null;
    }
    catch(PDOException $e)
    {
      echo $e->getMessage();
    }
  }
  ?>
</body>
</html>
