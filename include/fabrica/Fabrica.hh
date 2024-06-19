#ifndef FABRICA
#define FABRICA

#include "../interfaces/IControladorUsuario.hh"
#include "../interfaces/IControladorCompra.hh"
#include "../interfaces/IControladorProducto.hh"
#include "../interfaces/IControladorPromocion.hh"
#include "../interfaces/IControladorNotificacion.hh"

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