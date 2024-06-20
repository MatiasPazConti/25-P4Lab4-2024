#include "../../include/controladores/ControladorProducto.hh"

Producto* ControladorProducto::obtenerProductoDisponible(int id)
{
  for (std::set<Producto*>::iterator it = productos.begin(); it != productos.end(); ++it) {
        if((*it)->getId() == id){
            return *it;
        }   
      } 
      return NULL;    
}

ControladorProducto::ControladorProducto() {}
void ControladorProducto::registrarDatosProductos(std::string nombre, int precio, int cantidadEnStock, std::string descripcion, TipoProducto tipo, int id)
{
  Producto* prod = new Producto(id,nombre,descripcion,precio, cantidadEnStock, tipo);
  this->productos.insert(prod);
}

ControladorProducto::~ControladorProducto(){};

void ControladorProducto::listarProductosDisponibles()
{
  std::cout << "Elementos del set: ";

  for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
  {
    std::cout << *it;
  }
  std::cout << std::endl;
};
