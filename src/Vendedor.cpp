#include "../include/Vendedor.hh"

int Vendedor::getCodigoRUT()
{
  return codigoRUT;
}
DTUsuario *Vendedor::getDataUsuario()
{
  DTUsuario *dataUsuario = new DTVendedor(getNickname(), getFechaNacimiento(), codigoRUT);
  return dataUsuario;
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
void Vendedor::añadirProducto(Producto *producto)
{
  productos.insert(producto);
}
void Vendedor::removerProducto(Producto *producto)
{
  productos.erase(producto);
}
Vendedor::Vendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, int codigoRUT) : Usuario(nickname, password, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}
Vendedor::~Vendedor() {}