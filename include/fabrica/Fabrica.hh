#ifndef FABRICA
#define FABRICA

#include "../interfaces/IControladorUsuario.hh"

class Fabrica
{
public:
  static IControladorUsuario *getInterfazUsuario();
};

#endif