#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

#include "../datatypes/DTFecha.hh"

#include <iostream>

class IControladorUsuario
{
public:
  virtual void registrarDatosUsuario(std::string, std::string, DTFecha) = 0;
};

#endif