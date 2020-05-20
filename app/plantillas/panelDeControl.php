<?php ob_start() ?>

<?php $_SESSION['cerrarSesion'];?>

<a href="index.php?ctl=panelDeControl">Panel de control</a> |
<h1>Selecciona la acción que quieres hacer a continuación <?= $_SESSION['usuario']?></h1>

<form class="registro" action="" method="post">
  <fieldset>
    <legend>Selecciona una:</legend>
    
<?php if ($_SESSION['usuario'] == "Admin"):?>
      <input type="submit" name="reservar" value="Reservar">
      <input type="submit" name="devolver" value="Devolver">
      <input type="submit" name="añadirLibro" value="Añadir Libro">
<?php else: ?>
      <input type="submit" name="reservar" value="Reservar">
      <input type="submit" name="verReservas" value="Ver reservas">
<?php endif ?>

</fieldset>
</form>

<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>
