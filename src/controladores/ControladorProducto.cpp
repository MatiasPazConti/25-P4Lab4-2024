#include "../../include/controladores/ControladorProducto.hh"

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

Producto *ControladorProducto::getProducto(int id)
{
  for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
  {
    if ((*it)->getId() == id)
    {
      return (*it);
    }
  }
  return NULL;
}

void ControladorProducto::registrarDatosProductos(std::string nombre, float precio, int cantidadEnStock, std::string descripcion, TipoProducto tipo, DTVendedor *vendedor)
{
  int id = lastID + 1;
  Producto *prod = new Producto(id, nombre, descripcion, precio, cantidadEnStock, tipo, vendedor);
  this->productos.insert(prod);
  lastID = id;
}

void ControladorProducto::altaNuevoProducto()
{
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
