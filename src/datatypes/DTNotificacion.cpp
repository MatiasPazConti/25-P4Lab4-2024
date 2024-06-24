#include "../../include/datatypes/DTNotificacion.hh"

DTPromocion *DTNotificacion::getInfoPromocion()
{
  return promocion;
}
DTNotificacion *DTNotificacion::copiarNotificacion()
{
  DTPromocion *copiaInfoPromo = promocion->copiarPromocion();
  DTNotificacion *copiaNotificacion = new DTNotificacion(copiaInfoPromo);
  return copiaNotificacion;
}
DTNotificacion::DTNotificacion(DTPromocion *promocion)
{
  this->promocion = promocion;
}
DTNotificacion::~DTNotificacion()
{
  delete promocion;
}
void DTNotificacion::setPrint(std::ostream &out)
{
  DTPromocion *infoPromo = promocion;
  DTVendedor *infoVendedor = infoPromo->getInfoVendedor();
  std::map<int, DTProductoPromo *> infoProductosPromo = promocion->getProductos();
  out << "Vendedor: " << infoVendedor->getNickname() << "\n";
  out << "Promocion: " << infoPromo->getNombre() << "\n";
  out << "Productos:\n";
  for (std::map<int, DTProductoPromo *>::iterator it = infoProductosPromo.begin(); it != infoProductosPromo.end(); it++)
  {
    out << "- " << it->second->getNombre() << "\n";
  }
}
std::ostream &operator<<(std::ostream &out, DTNotificacion &obj)
{
  obj.setPrint(out);
  return out;
}