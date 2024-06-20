#ifndef FABRICA
#define FABRICA

#include "../controladores/ControladorUsuario.hh"
#include "../controladores/ControladorCompra.hh"
#include "../controladores/ControladorProducto.hh"
#include "../controladores/ControladorPromocion.hh"
#include "../controladores/ControladorNotificacion.hh"

class Fabrica
{
private:
  static Fabrica *fabrica;
  IControladorUsuario *controladorUsuario = nullptr;
  IControladorCompra *controladorCompra = nullptr;
  IControladorProducto *controladorProducto = nullptr;
  IControladorPromocion *controladorPromocion = nullptr;
  IControladorNotificacion *controladorNotificacion = nullptr;
  Fabrica();

public:
  ~Fabrica();
  static Fabrica *getInstance();
  IControladorUsuario *getInterfazUsuario();
  IControladorCompra *getInterfazCompra();
  IControladorProducto *getInterfazProducto();
  IControladorPromocion *getInterfazPromocion();
  IControladorNotificacion *getInterfazNotificacion();
};

#endif