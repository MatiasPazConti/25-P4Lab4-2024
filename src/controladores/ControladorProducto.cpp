#include "../../include/controladores/ControladorProducto.hh"
#include "../../include/fabrica/Fabrica.hh"

Producto *ControladorProducto::getProducto(int id)
{
  bool encontrado = false;
  for (std::set<Producto *>::iterator it = productos.begin(); (it != productos.end()) && !encontrado; it++)
  {
    if ((*it)->getId() == id)
    {
    }
  }
}
DTProducto *ControladorProducto::obtenerProductoDisponible(int id)
{
  for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
  {
    if ((*it)->getId() == id)
    {
      DTProducto *dataProducto = (*it)->getDataProducto();
      return dataProducto;
    }
  }
  return NULL;
}
void ControladorProducto::registrarDatosProductos(std::string nombre, float precio, int cantidadEnStock, std::string descripcion, TipoProducto tipo, std::string nickVendedor)
{
  lastID++;
  Vendedor *vendedor = Fabrica::getInterfazUsuario()->getVendedor(nickVendedor);
  Producto *prod = new Producto(lastID, nombre, descripcion, precio, cantidadEnStock, tipo, vendedor);
  this->productos.insert(prod);
}
ControladorProducto::ControladorProducto() {}
ControladorProducto::~ControladorProducto(){};
ControladorProducto *ControladorProducto::instancia = NULL;
ControladorProducto *ControladorProducto::getInstancia()
{
  if (instancia == NULL)
  {
    instancia = new ControladorProducto();
    instancia->lastID = 0;
  }
  return instancia;
}

std::set<DTProducto *> ControladorProducto::obtenerProductosDisponibles()
{
  std::set<DTProducto *> dataProducto;
  for (auto it = productos.begin(); it != productos.end(); ++it)
  {
    DTProducto *agregar = (*it)->getDataProducto();
    dataProducto.insert(agregar);
  }
  return dataProducto;
}
