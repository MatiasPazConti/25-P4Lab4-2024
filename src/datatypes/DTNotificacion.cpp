#include "../../include/datatypes/DTNotificacion.hh"

DTPromocion *DTNotificacion::getInfoPromocion()
{
  return promocion;
}
std::string DTNotificacion::getNicknameVendedor()
{
  return nicknameVendedor;
}
DTNotificacion::DTNotificacion(DTPromocion *promocion, std::string nicknameVendedor)
{
  this->promocion = promocion;
  this->nicknameVendedor = nicknameVendedor;
}
DTNotificacion::~DTNotificacion() {}