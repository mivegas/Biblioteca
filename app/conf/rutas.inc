<?php

// Vector multidimensional con rutas a controlador y método que debe
// atender cada enlace
/* formato:
    Primera dimensaión: nombre del enlace pasado mediante variable GET 'ctl'
     'nombreEnlace' => array() segunda dimesion con información del controlador
                       que atiende esa petición, clave 'controller', y del
                       método concreto que está especializado en su tratamiento,
                       clave 'action'
  Se debe agregar una ruta por cada valor diferente que tome la variable 'ctl'.
  La clave 'inicio' referencia la página home de la aplicación y especifica
    el controlador que debe decidir cuál es la vista que se debe mostrar
*/
$mapeoRutas =
  array('inicio' =>
          array('controller' =>'DefaultController', 'action' =>'inicio'),
        'registro' =>
          array('controller' =>'DefaultController', 'action' =>'registro'),
        'panelDeControl' =>
          array('controller' =>'DefaultController', 'action' =>'panelDeControl'),
        'panelReserva' =>
          array('controller' =>'DefaultController', 'action' =>'panelReserva'),
        'reserva' =>
          array('controller' =>'DefaultController', 'action' =>'busquedaUsuariosReserva'),
        'panelDevolver' =>
          array('controller' =>'DefaultController', 'action' =>'panelDevolver'),
        'devolver' =>
          array('controller' =>'DefaultController', 'action' =>'devolver'),
        'cerrarSesion' =>
          array('controller' =>'DefaultController', 'action' =>'cerrarSesion'),
        'verReservas' =>
          array('controller' =>'DefaultController', 'action' =>'verReservasFun'),

       );
