#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

#include "../datatypes/DTFecha.hh"
#include "../datatypes/DTDireccion.hh"

#include <iostream>

class IControladorUsuario
{
public:
  virtual void resgitrarDatosUsuario(std::string, std::string, DTFecha) = 0;
  virtual void resgitrarDatosCliente(std::string, DTDireccion) = 0;
  virtual void resgitrarDatosVendedor() = 0;
};

#endif