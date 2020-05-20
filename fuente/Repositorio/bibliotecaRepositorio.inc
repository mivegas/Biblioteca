<?php
class biblioteca{

  public function mostrarLibros(){
    $sql = "SELECT titulo, autor, idioma
            from Libro";

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function meterDatos($nombre,$apellidos,$usuario,$contrasena){

    $contra = password_hash($contrasena, PASSWORD_DEFAULT);

    $sql = 'INSERT INTO dbo.Usuarios (nombre, apellidos, usuario, contrasena)
    VALUES(:nombre , :apellidos, :usuario, :contrasena)';

    require_once __DIR__ .'/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->bindValue(":nombre", $nombre);
      $stn->bindValue(":apellidos", $apellidos);
      $stn->bindValue(":usuario", $usuario);
      $stn->bindValue(":contrasena", $contra);
      $stn->execute();
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function comprobarInicioSesion($usuario){

    $sql = 'SELECT usuario, contrasena, id
            FROM Usuarios
            where Usuario = :usuario';

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->bindValue(":usuario",$usuario);
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function busquedaAvanzada($titulo, $autor, $genero, $idioma){
    $consulta ="";

    if ($titulo != null) {
      $consulta .=" and titulo LIKE '%'+:titulo+'%'";
    }

    if ($autor != null) {
      $consulta .=" and autor LIKE '%'+:autor+'%'";
    }

    if ($genero != null) {
      $consulta .=" and Genero.nombre LIKE '%'+:genero+'%'";
    }

    if ($idioma != null) {
      $consulta .=" and idioma LIKE '%'+:idioma+'%'";
    }

    $sql ='SELECT titulo, autor, idioma,Libro.id as "idLibro", Genero.nombre as "genero", count(Ejemplar.id) as "disponibles"
          from Libro, Ejemplar, Genero
          where Libro.id = Ejemplar.idLibro and Genero.id = Libro.idGenero'.$consulta.'AND Ejemplar.idUsuario IS NULL
          Group by titulo, autor, idioma, Genero.nombre, Libro.id';

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      if($titulo != null){
        $stn->bindValue(":titulo", $titulo);
      }
      if($autor != null){
        $stn->bindValue(":autor", $autor);
      }
      if($genero != null){
        $stn->bindValue(":genero", $genero);
      }
      if($idioma != null){
        $stn->bindValue(":idioma", $idioma);
      }
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }

  }

  public function busquedaAvanzadaDevolver($titulo, $autor, $genero, $idioma){
    $consulta ="";

    if ($titulo != null) {
      $consulta .=" and titulo LIKE '%'+:titulo+'%'";
    }

    if ($autor != null) {
      $consulta .=" and autor LIKE '%'+:autor+'%'";
    }

    if ($genero != null) {
      $consulta .=" and Genero.nombre LIKE '%'+:genero+'%'";
    }

    if ($idioma != null) {
      $consulta .=" and idioma LIKE '%'+:idioma+'%'";
    }

    $sql ='SELECT titulo, autor, idioma,Libro.id as "idLibro", Genero.nombre as "genero", count(Ejemplar.id) as "reservados"
          from Libro, Ejemplar, Genero
          where Libro.id = Ejemplar.idLibro and Genero.id = Libro.idGenero'.$consulta.'AND Ejemplar.idUsuario IS NOT NULL
          Group by titulo, autor, idioma, Genero.nombre, Libro.id';

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      if($titulo != null){
        $stn->bindValue(":titulo", $titulo);
      }
      if($autor != null){
        $stn->bindValue(":autor", $autor);
      }
      if($genero != null){
        $stn->bindValue(":genero", $genero);
      }
      if($idioma != null){
        $stn->bindValue(":idioma", $idioma);
      }
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }

  }

  public function reservaDeLibros($idLibro){
    $sql ='SELECT titulo, autor, idioma, Genero.nombre as "genero"
          from Libro, Ejemplar, Genero
          where Libro.id = Ejemplar.idLibro AND Libro.id = :idLibro AND libro.idgenero = Genero.id AND Ejemplar.idUsuario IS NULL
          Group by titulo, autor, idioma, Genero.nombre, Libro.id';

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->bindValue(":idLibro",$idLibro);
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function mostrarUsuarios($nombre, $usuario){
    $consulta ="";

    if ($usuario != null && $nombre != null) {
      $consulta.= " usuario LIKE '%'+:usuario+'%' and nombre LIKE '%'+:nombre+'%' ";
    }else if($nombre != null){
      $consulta .=" nombre LIKE '%'+:nombre+'%'";
    }else if($usuario != null){
      $consulta .=" usuario LIKE '%'+:usuario+'%'";
    }

    $sql ="SELECT nombre, usuario, id from Usuarios WHERE " .$consulta;

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      if($nombre != null){
        $stn->bindValue(":nombre", $nombre);
      }
      if($usuario != null){
        $stn->bindValue(":usuario", $usuario);
      }
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function reservarAlUsuario($idusuario, $idEjemplar){
    $sql ="UPDATE Ejemplar
          SET idUsuario = :idusuario
          WHERE idUsuario is null
          and Ejemplar.id = :idEjemplar";

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->bindValue(":idusuario", $idusuario);
      $stn->bindValue(":idEjemplar", $idEjemplar);
      $stn->execute();
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function mostrarEjemplaresDesdeUnId($idLibro){
    $sql ="SELECT * from ejemplar
            where idLibro = :idLibro and idUsuario is null";

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->bindValue(":idLibro", $idLibro);
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function devolverLibros($idUsuario){
    $sql ='SELECT titulo, autor, idioma, Genero.nombre as "genero", Usuarios.usuario as "usuario", Ejemplar.id as "numeroEjemplar"
            from Libro, Ejemplar, Genero ,Usuarios
            where Libro.id = Ejemplar.idLibro AND Usuarios.id = :idUsuario AND libro.idgenero = Genero.id AND Ejemplar.idUsuario = Usuarios.id
            AND Ejemplar.idUsuario IS NOT NULL';

    require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->bindValue(":idUsuario",$idUsuario);
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }
  }

  public function mostrarReservas($idUsuario){
    $sql = 'SELECT l.titulo, l.autor, g.nombre as "genero", l.idioma as "idioma", u.usuario as "usuario"
            from Genero as g join Libro as l on g.id = l.idGenero
            inner join Ejemplar as e on l.id = e.idLibro
            inner join Usuarios as u on e.idUsuario = u.id
            where u.id=:idUsuario';
            require_once __DIR__ .'/../../core/conexionBd.inc';

    try {
      $con = (new ConexionBd())->getConexion();
      $stn = $con->prepare($sql);
      $stn->bindValue(":idUsuario",$idUsuario);
      $stn->execute();
      return $stn->fetchALL(PDO::FETCH_ASSOC);
    } catch (PDOException $ex) {
      throw $ex;
    }finally{
      $stn = null;
      $con = null;
    }

  }

  public function devolverLibrosfun($array){
    if (!empty($array)) {
      for ($i=0;$i<count($array);$i++){
        $sql = 'UPDATE Ejemplar
                set idUsuario = NULL
                where Ejemplar.id = '. $array[$i];
        try {
          $con = (new ConexionBd())->getConexion();
          $stn = $con->prepare($sql);
          $stn->execute();
        } catch (PDOException $ex) {
          throw $ex;
        }finally{
          $stn = null;
          $con = null;
        }
      }
    }
  }
}

?>
