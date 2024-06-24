#include "../include/Vendedor.hh"

std::string Vendedor::getCodigoRUT()
{
  return codigoRUT;
}
DTVendedor *Vendedor::getDataVendedor()
{
  DTVendedor *dataVendedor = new DTVendedor(getNickname(), getFechaNacimiento(), codigoRUT);
  return dataVendedor;
}
DTProducto *Vendedor::getDataProducto(int id)
{
  DTProducto *dataProducto = NULL;
  bool encontrado = false;
  for (std::set<Producto *>::iterator it = productos.begin(); (it != productos.end()) && !encontrado; it++)
  {
    if ((*it)->getId() == id)
    {
      dataProducto = (*it)->getDataProducto();
      encontrado = true;
    }
  }
  return dataProducto;
}
bool Vendedor::tieneSuscriptores()
{
  return !suscriptores.empty();
}
void Vendedor::añadirProducto(Producto *producto)
{
  productos.insert(producto);
}
void Vendedor::añadirSuscriptor(Cliente *suscriptor)
{
  suscriptores.insert(suscriptor);
}
void Vendedor::removerProducto(Producto *producto)
{
  productos.erase(producto);
}
void Vendedor::removerSuscriptor(Cliente *suscriptor)
{
  suscriptores.erase(suscriptor);
}
void Vendedor::notificarObservadores(DTPromocion *infoPromocion)
{
  DTNotificacion *nuevaNotificacion = new DTNotificacion(infoPromocion);
  for (std::set<IObservador *>::iterator it = suscriptores.begin(); it != suscriptores.end(); it++)
  {
    DTNotificacion *copiaNotificacion = nuevaNotificacion->copiarNotificacion();
    (*it)->notificar(copiaNotificacion);
  }
  delete nuevaNotificacion;
}
std::set<DTProducto *> Vendedor::listarProductos()
{
  std::set<DTProducto *> listaProductos;
  for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); it++)
  {
    DTProducto *dataProducto = (*it)->getDataProducto();
    listaProductos.insert(dataProducto);
  }
  return listaProductos;
}
Vendedor::Vendedor(std::string nickname, std::string password, DTFecha *fechaNacimiento, std::string codigoRUT) : Usuario(nickname, password, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}
Vendedor::~Vendedor()
{
  Usuario::~Usuario();
}