<?php ob_start() ?>

<a href="index.php?ctl=panelDeControl">Panel de control</a> |
<h1>BUSQUEDA DE USUARIOS (DEVOLVER)</h1>

<form class="registro" action="" method="post">
  <fieldset>
    <legend>Busqueda avanzada de usuarios (DEVOLVER)</legend>
    Nombre: <input type="text" name="nombre" value="" placeholder="nombre"><br><br>
    Usuario: <input type="text" name="usuario" value="" placeholder="usuario"><br><br>

    <input type="hidden" name="usuarioReserva" value="<?= isset($value['usuario'])?$value['usuario']:"" ?>">
    <input type="hidden" name="libroReserva" value="<?= isset($_GET['idLibro'])?$_GET['idLibro']:"" ?>">

    <input type="submit" name="buscar" value="Buscar">
  </fieldset>
</form>

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
    echo "<input type='submit' id='botonReserva' value='Mostrar Reservados' name='mostrarReservados'>";
    echo "</form>";
  }
 ?>

</table>

<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>
