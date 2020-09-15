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
  <div class="col-md-6">
    <form class="px-4 py-3" action="" method="post">
      <a href="generateur.php"><h1 class="h1 font-weight-bold">Phrasonator</h1></a>
      <h2 class="h3 mb-3 font-weight-normal">Inscription</h2>
      <div class="form-group">
        <label for="InputUsers">Nom d'Utilisateur</label>
        <input type="text" class="form-control" required="required" name="inputUsers" id="inputUsers" placeholder="Nom d'utilisateur">
      </div>
      <div class="form-group">
        <label for="InputName">Nom</label>
        <input type="text" class="form-control" required="required" name="inputName" id="inputName" placeholder="Nom">
      </div>
      <div class="form-group">
        <label for="InputFirstname">Prenom</label>
        <input type="text" class="form-control" required="required" name="inputFirstname" id="inputFirstname" placeholder="Prenom">
      </div>
      <div class="form-group">
        <label for="InputPassword">Mot de Passe</label>
        <input type="password" class="form-control" required="required" name="inputPassword" id="inputPassword" placeholder="mot de passe">
      </div>
      <div class="form-group">
        <label for="InputAge">Age</label>
        <input type="number" min="0" max="100" class="form-control" required="required" name="inputAge" id="inputAge" placeholder="Age">
      </div>
      <button name="submit" type="submit" class="btn btn-primary">Inscription</button>
    </form>
    <div class="dropdown-divider"></div>
  </div>
  </div>
  <?php
  if(isset($_POST["submit"])){
    $hostname='localhost';
    $username='root';
    $password='';
    try {
      $dbh = new PDO("mysql:host=$hostname;dbname=generateur",$username,$password);

      $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // <== add this line
      $sql = "INSERT INTO utilisateur (Utilisateur, Nom, Prenom, Motdepasse, Age)
      VALUES ('".$_POST["inputUsers"]."','".$_POST["inputName"]."','".$_POST["inputFirstname"]."','".$_POST["inputPassword"]."','".$_POST["inputAge"]."')";
      if ($dbh->query($sql)) {
        echo "<script type= 'text/javascript'>alert('Nouveau Compte Creer.');</script>";
      }
      else{
        echo "<script type= 'text/javascript'>alert('Impossible de Creer le compte.');</script>";
      }
      $url="generateur.php";
      Redirect($url);
      $dbh = null;
    }
    catch(PDOException $e)
    {
      echo $e->getMessage();
    }
  }
  function Redirect($url){
    header('Location: ' . $url);
    exit();
  }
   ?>
</body>
</html>
