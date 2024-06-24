#include "../../include/datatypes/DTVendedor.hh"

std::string DTVendedor::getCodigoRUT()
{
  return codigoRUT;
}
std::set<DTPromocion *> DTVendedor::getPromociones()
{
  return promociones;
}
DTVendedor *DTVendedor::copiarInfoVendedor()
{
  DTFecha *copiaFechaNacimiento = getFechaNacimiento()->copiarFecha();
  std::set<DTPromocion *> copiaListaPromos;
  for (std::set<DTPromocion *>::iterator it = promociones.begin(); it != promociones.end(); it++)
  {
    DTPromocion *copiaInfoPromo = (*it)->copiarPromocion();
    copiaListaPromos.insert(copiaInfoPromo);
  }
  DTVendedor *copiaInfoVendedor = new DTVendedor(getNickname(), copiaFechaNacimiento, codigoRUT, copiaListaPromos);
  return copiaInfoVendedor;
}
DTVendedor::DTVendedor(std::string nickname, DTFecha *fechaNacimiento, std::string codigoRUT, std::set<DTPromocion *> promociones)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
  this->promociones = promociones;
}
DTVendedor::~DTVendedor()
{
  while (!promociones.empty())
  {
    std::set<DTPromocion *>::iterator inicio = promociones.begin();
    DTPromocion *aBorrar = *inicio;
    promociones.erase(inicio);
    delete aBorrar;
  }
  DTUsuario::~DTUsuario();
}
