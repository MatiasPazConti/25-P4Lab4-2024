#include "../../include/datatypes/DTCliente.hh"

DTCliente::DTCliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia)
    : DTUsuario(nickname, password, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}

DTCliente::~DTCliente()
{
}

DTDireccion DTCliente::getDireccion()
{
  return direccion;
}

std::string DTCliente::getCiudadDeResidencia()
{
  return ciudadDeResidencia;
}
