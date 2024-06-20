#include "../../include/datatypes/DTVendedor.hh"

int DTVendedor::getCodigoRUT()
{
  return codigoRUT;
}
DTVendedor::DTVendedor(std::string nickname, DTFecha fechaNacimiento, std::string codigoRUT)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}
DTVendedor::~DTVendedor()
{
}
