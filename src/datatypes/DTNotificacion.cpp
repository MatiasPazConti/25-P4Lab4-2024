#include "../../include/datatypes/DTNotificacion.hh"

int DTNotificacion::getIdNotificacion()
{
  return idNotificacion;
}
std::string DTNotificacion::getNombrePromocion()
{
  return nombrePromocion;
}
std::string DTNotificacion::getNicknameVendedor()
{
  return nicknameVendedor;
}
DTNotificacion::DTNotificacion(int idNotificacion, std::string nombrePromocion, std::string nicknameVendedor)
{
  this->idNotificacion = idNotificacion;
  this->nombrePromocion = nombrePromocion;
  this->nicknameVendedor = nicknameVendedor;
}
DTNotificacion::~DTNotificacion() {}