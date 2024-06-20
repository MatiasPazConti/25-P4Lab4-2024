#ifndef DTCLIENTE
#define DTCLIENTE

#include "./DTUsuario.hh"
#include "./DTDireccion.hh"

#include <iostream>

class DTCliente : public DTUsuario
{
private:
  DTDireccion direccion;
  std::string ciudadDeResidencia;

public:
  DTDireccion getDireccion();
  std::string getCiudadDeResidencia();
  DTCliente(std::string nickname, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia);
  ~DTCliente();
};

#endif