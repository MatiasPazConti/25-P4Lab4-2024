#include "../include/Cliente.hh"

Cliente::Cliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia)
    : Usuario(nickname, password, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}

Cliente::~Cliente()
{
}

DTDireccion Cliente::getDireccion()
{
  return direccion;
}

std::string Cliente::getCiudadDeResidencia()
{
  return ciudadDeResidencia;
}
