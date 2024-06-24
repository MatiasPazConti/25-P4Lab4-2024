#include "../include/Cliente.hh"

DTDireccion *Cliente::getDireccion()
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
std::set<Compra *> Cliente::getComprasPrevias()
{
  return comprasPrevias;
}
DTCliente *Cliente::getDataCliente()
{
  std::set<DTCompra *> listaInfoCompras;
  for (std::set<Compra *>::iterator it = comprasPrevias.begin(); it != comprasPrevias.end(); it++)
  {
    DTCompra *infoCompraPrevia = (*it)->getDatosCompra();
    listaInfoCompras.insert(infoCompraPrevia);
  }
  DTCliente *dataCliente = new DTCliente(getNickname(), getFechaNacimiento()->copiarFecha(), direccion->copiarDireccion(), ciudadDeResidencia, listaInfoCompras);
  return dataCliente;
}
void Cliente::añadirSuscripcion(Vendedor *suscripcion)
{
  suscripciones.insert(suscripcion);
}
void Cliente::añadirCompra(Compra *compra)
{
  comprasPrevias.insert(compra);
}
void Cliente::removerSuscripcion(Vendedor *suscripcion)
{
  suscripciones.erase(suscripcion);
}
void Cliente::removerCompra(Compra *compra)
{
  comprasPrevias.erase(compra);
}
void Cliente::notificar(DTNotificacion *notificacion)
{
  notificaciones.insert(notificacion);
}
void Cliente::eliminarNotificaciones()
{
  while (!notificaciones.empty())
  {
    std::set<DTNotificacion *>::iterator inicio = notificaciones.begin();
    DTNotificacion *aBorrar = *inicio;
    notificaciones.erase(aBorrar);
    delete aBorrar;
  }
}
std::set<DTNotificacion *> Cliente::listarNotificaciones()
{
  return notificaciones;
}
Cliente::Cliente(std::string nickname, std::string password, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadDeResidencia) : Usuario(nickname, password, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}
Cliente::~Cliente()
{
  delete direccion;
  Usuario::~Usuario();
}
