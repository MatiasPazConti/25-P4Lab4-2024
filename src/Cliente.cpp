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
