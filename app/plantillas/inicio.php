<?php
/* Ejemplo de plantilla que se mostrará dentro de la plantilla principal
  ob_start() activa el almacenamiento en buffer de la página. Mientras se
             almacena en el buffer no se produce salida alguna hacia el
             navegador del cliente
  luego viene el código html y/o php que especifica lo que debe aparecer en
     el cliente web
  ob_get_clean() obtiene el contenido del buffer (que se pasa a la variable
             $contenido) y elimina el contenido del buffer
  Por último se incluye la página que muestra la imagen común de la aplicación
    (en este caso base.php) la cual contiene una referencia a la variable
    $contenido que provocará que se muestre la salida del buffer dentro dicha
    página "base.php"
*/
 ?>
<?php ob_start() ?>

    <form class="inicioSesion" action="" method="post">
      <fieldset>
        <legend>Inicio de Sesion</legend>
        Usuario: <input type="text" name="usuario" value="" placeholder="usuario"><br><br>
        Contraseña: <input type="password" name="pass" value="" placeholder="contraseña"><br>
        <input type="submit" name="entrar" value="Entrar">
        <a href="index.php?ctl=registro">Registrarse</a>
      </fieldset>
    </form>
<table>
  <?php

  echo "<tr>";
    echo "<th>" . 'Titulo' . "</th>";
    echo "<th>" . 'Autor' . "</th>";
    echo "<th>" . 'Idioma' . "</th>";
  echo "</tr>";

  foreach ($mostrarLibros as $value) {
    echo "<tr>";
        echo "<td>". $value['titulo']. "</td>";
        echo "<td>". $value['autor']. "</td>";
        echo "<td>". $value['idioma']. "</td>";
    echo "</tr>";
  }
   ?>
</table>


 <?php $contenido = ob_get_clean() ?>

 <?php include 'base.php' ?>
