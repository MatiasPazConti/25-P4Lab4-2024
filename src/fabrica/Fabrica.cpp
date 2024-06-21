#include "../../include/fabrica/Fabrica.hh"
#include "../../include/controladores/ControladorUsuario.hh"
#include "../../include/controladores/ControladorCompra.hh"
#include "../../include/controladores/ControladorProducto.hh"
#include "../../include/controladores/ControladorPromocion.hh"
#include "../../include/controladores/ControladorNotificacion.hh"

IControladorUsuario *Fabrica::getInterfazUsuario()
{
  return ControladorUsuario::getInstancia();
}
IControladorCompra *Fabrica::getInterfazCompra()
{
  return ControladorCompra::getInstancia();
}
IControladorProducto *Fabrica::getInterfazProducto()
{
  return ControladorProducto::getInstancia();
}
IControladorPromocion *Fabrica::getInterfazPromocion()
{
  return ControladorPromocion::getInstancia();
}
IControladorNotificacion *Fabrica::getInterfazNotificacion()
{
  return ControladorNotificacion::getInstancia();
}
