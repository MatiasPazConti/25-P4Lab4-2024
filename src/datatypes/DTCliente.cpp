#include "../../include/datatypes/DTCliente.hh"

DTDireccion DTCliente::getDireccion()
{
  return direccion;
}
std::string DTCliente::getCiudadDeResidencia()
{
  return ciudadDeResidencia;
}
DTCliente::DTCliente(std::string nickname, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}
DTCliente::~DTCliente()
{
}
