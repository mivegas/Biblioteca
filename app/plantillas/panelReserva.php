<?php ob_start() ?>

<a href="index.php?ctl=panelDeControl">Panel de control</a> |
<h1>BUSQUEDA DE LIBROS (RESERVA)</h1>

<form class="registro" action="" method="post">
  <fieldset>
    <legend>Busqueda avanzada de libros (RESERVA)</legend>
    Titulo: <input type="text" name="titulo" value="" placeholder="titulo"><br><br>
    Autor: <input type="text" name="autor" value="" placeholder="autor"><br><br>
    Genero: <input type="text" name="genero" value="" placeholder="genero"><br><br>
    Idioma: <input type="text" name="idioma" value="" placeholder="idioma"><br>
    <input type="submit" name="buscar" value="Buscar">
  </fieldset>
</form>

<table>
  <?php
      if (isset($_POST['buscar'])) {
        echo "<tr>";
          echo "<th>" . 'Titulo' . "</th>";
          echo "<th>" . 'Autor' . "</th>";
          echo "<th>" . 'Genero' . "</th>";
          echo "<th>" . 'Idioma' . "</th>";
          echo "<th>" . 'Disponible(s)' . "</th>";
        echo "</tr>";

          foreach ($buscar as $value) {
            echo "<tr>";
            echo "<td>"."<a href='index.php?ctl=reserva&idLibro=".$value['idLibro']."'>".$value['titulo']."</a>"."</td>";
            echo "<td>". $value['autor']. "</td>";
            echo "<td>". $value['genero']. "</td>";
            echo "<td>". $value['idioma']. "</td>";
            echo "<td>". $value['disponibles']. "</td>";
            echo "</tr>";
          }
      }
   ?>
</table>

<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>
