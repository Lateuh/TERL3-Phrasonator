<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <title>Generateur de phrases</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <link href="https://mdbootstrap.com/previews/docs/latest/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://mdbootstrap.com/previews/docs/latest/css/mdb.min.css" rel="stylesheet">
    <link href="style1.css" rel="stylesheet">
</head>
<body>
<header>
</header>
    <!-- <div class="view hm-white-light jarallax" data-jarallax='{"speed": 0.2}' data-jarallax-video="https://www.youtube.com/watch?v=syBR4xiikcQ"> -->
    <div class="view hm-black-light">
      <img src="Dark-wallpaper-desktop-background-64-1200x675.jpg" class="img-fluid" alt="Responsive image">
            <div class="full-bg-img">
                <div class="container flex-center">
                    <div class="row">
                        <div class="col-md-12 wow fadeIn">
                            <div class="text-center text-white">
                                <h1 class="display-2 mb-2 wow fadeInDown" data-wow-delay="0.3s">Generateur de phrases</h1>
                                <!-- <h5 class="font-up mb-3 mt-1 font-bold wow fadeInDown" style="font-weight:bold; text-shadow: 0 0 8px #FFF, 0 -2px 12px #222, 0 -5px 15px #666;" data-wow-delay="0.4s">SNI<a href="https://goo.gl/nsVK7W">https://goo.gl/nsVK7W</a><br> -->
                                <a class="btn btn-danger btn-lg wow fadeInDown" data-wow-delay="0.4s" href="connection.html"><i class="fa fa-lock" href="connection.html"></i> se Connecter</a>
                                <a class="btn btn-primary btn-lg wow fadeInDown" data-wow-delay="0.4s"><i class="fa fa-registered"></i> s'Enregistrer</a>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
<div class="py-2"></div>
<div class="container-fluid">
    <div class="row">
        <div class="col-xl-3 col-lg-3 col-md-3 col-sm-12 col-xs-12">
            <ul class="list-group">
                <li class="list-group-item active">Qu'est-ce qu'un generateur de phrases ?</li>
                <li class="list-group-item">Comme son nom l'indique, un generateur de phrases genere de façon aléatoire une phrase respectant les règles syntaxique de la langue française.</li>
            </ul>
        </div>
        <div class="col-xl-3 col-lg-3 col-md-3 col-sm-12 col-xs-12">
            <ul class="list-group">
                <li class="list-group-item active">Les Différentes Formulations</li>
                <li class="list-group-item">Ce generateur a été pensé de façon a inclure les notions de quantificateurs universel et existentiel pour ce faire en laisse le choix au utilisateur deux formulations qui sont chaque et certain. Ce choix est fait via les reponses a un quizz accessible apres l'inscription.</li>
            </ul>
        </div>
        <div class="col-xl-3 col-lg-3 col-md-3 col-sm-12 col-xs-12">
            <ul class="list-group">
                <li class="list-group-item active">Les Différents Domaines</li>
                <li class="list-group-item">Ce generateur renvoye des phrases comprises dans les domaines suivant: le sport, les mathematiques niveau college/lycee et reglement interieur d'un ecole.</li>
            </ul>
        </div>
    </div>
</div>
<?php
$maphrase = exec("C:/Programmes/swipl/bin/swipl.exe -f C:/Users/Hamza/Documents/GitHub/Phrasonator/projet8.pl -g consult,s");
echo '<pre>'.$maphrase.'<\pre>';
 ?>
 <div class="w3-padding w3-light-grey">
   <p class="w3-large" style="margin-bottom:30px;">1.Quel type de phrase vous convient le mieux ?</p>
   <form role="form" class="quizform" action="#" method="post">
     <div class="radio">
       <label>
         <input id="1" type="radio" name="quizz" value="1">
         ma phrase.
       </label>
     </div>
     <div class="radio">
       <label>
         <input id="1" type="radio" name="quizz" value="1">
         ma phrase.
       </label>
     </div>
     <div class="radio">
       <label>
         <input id="1" type="radio" name="quizz" value="1">
         ma phrase.
       </label>
     </div>
     <div class="radio">
       <label>
         <input id="1" type="radio" name="quizz" value="1">
         ma phrase.
       </label>
     </div>
     <div class="radio">
       <label>
         <input id="1" type="radio" name="quizz" value="1">
         ma phrase.
       </label>
     </div>
     <div class="radio">
       <label>
         <input id="1" type="radio" name="quizz" value="1">
         ma phrase.
       </label>
     </div>
   </form>
 </div>
<hr>
    <script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
    <script type="text/javascript" src="js/popper.min.js"></script>
    <script src="https://mdbootstrap.com/previews/docs/latest/js/bootstrap.min.js"></script>
    <script src="https://mdbootstrap.com/previews/docs/latest/js/mdb.min.js"></script>
    <script>
        new WOW().init();
    </script>
</body>
</html>
