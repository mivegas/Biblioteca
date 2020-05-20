<?php
// Ejemplo de controlador para página home de la aplicación
class DefaultController
{ public function inicio()
  {
    $_SESSION['inicioSesion'] = true;
    $_SESSION['cerrarSesion'] = false;

    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    $mostrarLibros = (new biblioteca())->mostrarLibros();


        if(isset($_POST['entrar'])){
          $nombre = $_POST['usuario'];
          $contrasena = $_POST['pass'];

          $usersPass = (new biblioteca())->comprobarInicioSesion($nombre);

          $_SESSION['id'] = $usersPass[0]['id'];
          $_SESSION['usuario'] = $usersPass[0]['usuario'];

          foreach ($usersPass as $value) {
            $p = $value['contrasena'];
            $u = $value['usuario'];
          }

            $contra = password_verify($contrasena, $p);
          if ($nombre == $u && $contra) {
            header('location:index.php?ctl=panelDeControl');
          }
        }

    require __DIR__ . '/../../app/plantillas/inicio.php';
  }

  public function cerrarSesion(){
    if ($_SESSION['cerrarSesion'] = true) {
      $_SESSION['inicioSesion'] = NULL;
      $_SESSION['cerrarSesion'] = NULL;
      $_SESSION['id'] = NULL;
      $_SESSION['usuario'] = NULL;
      session_destroy();
      header('location:index.php?ctl=inicio');
    }
  }

  public function registro(){

    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    if(isset($_POST['registrarse'])){
      $registrar = (new biblioteca())->meterDatos(
        $_POST['nombre'],$_POST['apellidos'], $_POST['usuario'], $_POST['pass1']);
    }

    require __DIR__.'/../../app/plantillas/registro.php';

  }

  public function panelReserva(){
    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    if(isset($_POST['buscar'])){
      $buscar = (new biblioteca())->busquedaAvanzada(
        $_POST['titulo'],$_POST['autor'], $_POST['genero'], $_POST['idioma']);
    }

    require __DIR__ . '/../../app/plantillas/panelReserva.php';
  }

  public function panelDevolver(){
    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    if(isset($_POST['buscar'])){
      $usuarios = (new biblioteca())->mostrarUsuarios($_POST['nombre'],$_POST['usuario']);

      $_SESSION['id'] = $usuarios[0]['id'];
      $_SESSION['usuario'] = $usuarios[0]['usuario'];
    }
    if (isset($_POST['mostrarReservados'])) {
      header('location:index.php?ctl=devolver&usuario='.$_SESSION['id']);
    }

    require __DIR__ . '/../../app/plantillas/panelDevolver.php';
  }

  public function busquedaUsuariosReserva(){
    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    $reserva = (new biblioteca())->reservaDeLibros($_GET["idLibro"]);

    if (isset($_POST['buscar'])) {
      $usuarios = (new biblioteca())->mostrarUsuarios($_POST['nombre'], $_POST['usuario']);

      $_SESSION['id'] = $usuarios[0]['id'];
    }
    if (isset($_POST['reservar'])) {
      $ejemplares = (new biblioteca())->mostrarEjemplaresDesdeUnId($_GET["idLibro"]);
      $idEjemplar = array_column($ejemplares,'id');

      $reservaUSuarios = (new biblioteca())->reservarAlUsuario($_SESSION['id'],$idEjemplar[0]);
    }

    require __DIR__ . '/../../app/plantillas/reserva.php';
  }

  public function busquedaUsuariosDevolver(){
    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    if (isset($_POST['buscar'])) {
      $usuarios = (new biblioteca())->mostrarUsuarios($_POST['nombre'], $_POST['usuario']);
    }

    require __DIR__ . '/../../app/plantillas/panelDevolver.php';
  }

  public function panelDeControl(){
    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';
    $_SESSION['inicioSesion'] = false;
    $_SESSION['cerrarSesion'] = true;
    if (isset($_POST['reservar'])) {
      header('location:index.php?ctl=panelReserva');
    }

    if (isset($_POST['devolver'])) {
      header('location:index.php?ctl=panelDevolver');
    }

    if (isset($_POST['añadirLibro'])) {

    }

    if (isset($_POST['verReservas'])) {
      header('location:index.php?ctl=verReservas');
    }

    require __DIR__ . '/../../app/plantillas/panelDeControl.php';
  }

  public function devolver(){
    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    $librosReservados = (new biblioteca())->devolverLibros($_GET['usuario']);

    if (isset($_POST['devolver'])) {

      $checked = $_POST["checkboxes"];

      $devolverLibrosfun = (new biblioteca())->devolverLibrosfun($checked);
      $librosReservados = (new biblioteca())->devolverLibros($_GET['usuario']);
    }

    require __DIR__ . '/../../app/plantillas/devolver.php';
  }

  public function verReservasFun(){
    include_once __DIR__ .'/../Repositorio/bibliotecaRepositorio.inc';

    $verReserva = (new biblioteca())-> mostrarReservas($_SESSION['id']);

    require __DIR__ . '/../../app/plantillas/verReservas.php';
  }
}
