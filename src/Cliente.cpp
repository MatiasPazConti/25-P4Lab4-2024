#include "../include/Cliente.hh"

DTDireccion Cliente::getDireccion()
{
  return direccion;
}
std::string Cliente::getCiudadDeResidencia()
{
  return ciudadDeResidencia;
}
DTUsuario *Cliente::getDataUsuario()
{
  DTUsuario *dataUsuario = new DTCliente(getNickname(), getFechaNacimiento(), direccion, ciudadDeResidencia);
  return dataUsuario;
}
Cliente::Cliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia) : Usuario(nickname, password, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}
Cliente::~Cliente() {}
