#ifndef FABRICA
#define FABRICA

#include "../interfaces/IControladorUsuario.hh"
#include "../interfaces/IControladorCompra.hh"
#include "../interfaces/IControladorProducto.hh"

class Fabrica
{
public:
  static IControladorUsuario *getInterfazUsuario();
  static IControladorUsuario *getInterfazProducto();
  static IControladorUsuario *getInterfazCompra();
};

#endif