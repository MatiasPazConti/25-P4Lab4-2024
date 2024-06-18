#include "../include/Vendedor.hh"

Vendedor::Vendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT) : Usuario(nickname, password, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}

Vendedor::~Vendedor()
{
}
