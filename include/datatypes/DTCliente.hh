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
  DTCliente(std::string, DTFecha, DTDireccion, std::string);
  ~DTCliente();
};

#endif