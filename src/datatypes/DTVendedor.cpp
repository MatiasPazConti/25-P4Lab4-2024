#include "../../include/datatypes/DTVendedor.hh"

std::string DTVendedor::getCodigoRUT()
{
  return codigoRUT;
}
DTVendedor *DTVendedor::copiarInfoVendedor()
{
  DTFecha *copiaFechaNacimiento = getFechaNacimiento()->copiarFecha();
  DTVendedor *copiaInfoVendedor = new DTVendedor(getNickname(), copiaFechaNacimiento, codigoRUT);
  return copiaInfoVendedor;
}
DTVendedor::DTVendedor(std::string nickname, DTFecha *fechaNacimiento, std::string codigoRUT)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}
DTVendedor::~DTVendedor()
{
  DTUsuario::~DTUsuario();
}
