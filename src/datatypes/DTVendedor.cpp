#include "../../include/datatypes/DTVendedor.hh"

DTVendedor::DTVendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT) : DTUsuario(nickname, password, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}

DTVendedor::~DTVendedor()
{
}
