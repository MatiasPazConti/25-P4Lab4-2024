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
void Cliente::notificar(std::string nombrePromocion, std::string nicknameVendedor)
{
  DTNotificacion *notificacion = new DTNotificacion(nombrePromocion, nicknameVendedor);
  notificaciones.insert(notificacion);
}
void Cliente::eliminarNotificaciones()
{
  for (std::set<DTNotificacion *>::iterator it = notificaciones.begin(); it != notificaciones.end; it++)
  {
    DTNotificacion *aBorrar = *it;
    notificaciones.erase(aBorrar);
    delete aBorrar;
  }
}
std::set<DTNotificacion *> Cliente::listarNotificaciones()
{
  return notificaciones;
}
Cliente::Cliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia) : Usuario(nickname, password, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}
Cliente::~Cliente() {}
