<?php ob_start() ?>
<h1>Usted tiene estos libros reservados:</h1>
<table>
<?php
  if (!empty($verReserva)) {
    echo "<tr>";
      echo "<th>" . 'Titulo' . "</th>";
      echo "<th>" . 'Autor' . "</th>";
      echo "<th>" . 'Genero' . "</th>";
      echo "<th>" . 'Idioma' . "</th>";
      echo "<th>" . 'Usuario' . "</th>";
    echo "</tr>";

    foreach ($verReserva as $value) {
      echo "<tr>";
          echo "<td>". $value['titulo']. "</td>";
          echo "<td>". $value['autor']. "</td>";
          echo "<td>". $value['genero']. "</td>";
          echo "<td>". $value['idioma']. "</td>";
          echo "<td>". $value['usuario']. "</td>";
      echo "</tr>";
    }
  }else{
    echo "<div class='tenor-gif-embed' data-postid='14036966' data-share-method='host' data-width='100%' data-aspect-ratio='1.7785714285714287'><a href='https://tenor.com/view/es-todo-ya-esta-no-hay-nada-vacio-solo-gif-14036966'>Es Todo Ya Esta GIF</a> from <a href='https://tenor.com/search/estodo-gifs'>Estodo GIFs</a></div><script type='text/javascript' async src='https://tenor.com/embed.js'></script>";
  }
 ?>
</table>

<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>
