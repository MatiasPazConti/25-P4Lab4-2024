#include "../include/Cliente.hh"

DTDireccion Cliente::getDireccion()
{
  return direccion;
}
std::string Cliente::getCiudadDeResidencia()
{
  return ciudadDeResidencia;
}
std::set<Vendedor *> Cliente::getSuscripciones()
{
  return suscripciones;
}
DTCliente *Cliente::getDataCliente()
{
  DTCliente *dataCliente = new DTCliente(getNickname(), getFechaNacimiento(), direccion, ciudadDeResidencia);
  return dataCliente;
}
void Cliente::añadirSuscripcion(Vendedor *suscripcion)
{
  suscripciones.insert(suscripcion);
}
void Cliente::removerSuscripcion(Vendedor *suscripcion)
{
  suscripciones.erase(suscripcion);
}
Cliente::Cliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia) : Usuario(nickname, password, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}
Cliente::~Cliente() {}
