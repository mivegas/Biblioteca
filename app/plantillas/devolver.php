<?php ob_start() ?>
<h1> LIBROS RESERVADOS POR EL USUARIO: <br><br><?= $_SESSION['usuario'] ?></h1>
<table>
  <form class="" action="#" method="post">
    <tr>
      <th>Titulo</th>
      <th>Autor</th>
      <th>Idioma</th>
      <th>Genero</th>
      <th>Ejemplar nº:</th>
      <th>DEVOLVER</th>
    </tr>
    <?php foreach ($librosReservados as $value): ?>
      <tr>
          <td><?=$value['titulo']?></td>
          <td><?=$value['autor']?></td>
          <td><?=$value['idioma']?></td>
          <td><?=$value['genero']?></td>
          <td><?=$value['numeroEjemplar']?></td>
          <td><input type="checkbox" name="checkboxes[]" value="<?=$value['numeroEjemplar']?>"></td>
      </tr>
    <?php endforeach; ?>

 <input type="submit" id="devolver" name="devolver" value="DEVOLVER">
</form>
</table>
<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>
