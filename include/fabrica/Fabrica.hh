#ifndef FABRICA
#define FABRICA

#include "../interfaces/IControladorUsuario.hh"
#include "../interfaces/IControladorCompra.hh"
#include "../interfaces/IControladorProducto.hh"
#include "../interfaces/IControladorPromocion.hh"
#include "../interfaces/IControladorNotificacion.hh"

class Fabrica
{
public:
  static IControladorUsuario *getInterfazUsuario();
  // static IControladorCompra *getInterfazCompra();
  // static IControladorProducto *getInterfazProducto();
  // static IControladorPromocion *getInterfazPromocion();
  // static IControladorNotificacion *getInterfazNotificacion();
};

#endif