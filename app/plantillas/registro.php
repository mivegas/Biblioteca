<?php ob_start() ?>

<form class="registro" action="" method="post">
  <fieldset>
    <legend>Registro</legend>
    Nombre: <input type="text" name="nombre" value="" placeholder="nombre"><br><br>
    Apellidos: <input type="text" name="apellidos" value="" placeholder="apellidos"><br><br>
    Usuario: <input type="text" name="usuario" value="" placeholder="usuario"><br><br>
    Contraseña: <input type="password" name="pass1" value="" placeholder="contraseña"><br>
    Repite la contraseña: <input type="password" name="pass2" value="" placeholder="contraseña"><br>
    <input type="submit" name="registrarse" value="Registrarse">
  </fieldset>
</form>


<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>
