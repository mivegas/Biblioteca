<?php ob_start() ?>


<form class="registro" action="" method="post">
  <fieldset>
    <legend>Busqueda avanzada de usuarios</legend>
    Nombre: <input type="text" name="nombre" value="" placeholder="nombre"><br><br>
    Usuario: <input type="text" name="usuario" value="" placeholder="usuario"><br><br>

    <input type="hidden" name="usuarioReserva" value="<?= isset($value['usuario'])?$value['usuario']:"" ?>">
    <input type="hidden" name="libroReserva" value="<?= isset($_GET['idLibro'])?$_GET['idLibro']:"" ?>">

    <input type="submit" name="buscar" value="Buscar">
  </fieldset>
</form>

<table>
<?php

  if (isset($_GET['idLibro'])) {
    echo "<tr>";
      echo "<th>" . 'Titulo' . "</th>";
      echo "<th>" . 'Autor' . "</th>";
      echo "<th>" . 'Genero' . "</th>";
      echo "<th>" . 'Idioma' . "</th>";

    echo "</tr>";

    foreach ($reserva as $value) {
      echo "<tr>";
          echo "<td>". $value['titulo']. "</td>";
          echo "<td>". $value['autor']. "</td>";
          echo "<td>". $value['genero']. "</td>";
          echo "<td>". $value['idioma']. "</td>";
      echo "</tr>";
    }
  }
 ?>
</table>

<table>
<?php
  if (isset($_POST['buscar'])) {
    echo "<tr>";
      echo "<th>" . 'Nombre' . "</th>";
      echo "<th>" . 'Usuario' . "</th>";
    echo "</tr>";

    foreach ($usuarios as $value) {
      echo "<tr>";
          echo "<td>". $value['nombre']. "</td>";
          echo "<td>". $value['usuario']. "</td>";
      echo "</tr>";
    }
    echo "<form method='post'>";
    echo "<input type='submit' id='botonReserva' value='Reservar' name='reservar'>";
    echo "</form>";
  }
 ?>

</table>
<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>
