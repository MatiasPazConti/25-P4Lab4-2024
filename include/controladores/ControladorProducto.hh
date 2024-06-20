#ifndef CONTROLADOR_PRODUCTO
#define CONTROLADOR_PRODUCTO

#include "../interfaces/IControladorProducto.hh"
#include <iostream>
#include <set>
#include "../TipoProducto.hh"
#include "../Producto.hh"
#include "../datatypes/DTProducto.hh"

class ControladorProducto : public IControladorProducto
{
private:
  std::set<Producto *> productos;
public:
  void registrarDatosProductos(std::string nombre, int precio, int cant, std::string des, TipoProducto tipo, int id){
    
  };
  void listarProductosDisponibles(); // Usa DTProducto o Producto???
  Producto* obtenerProductoDisponible(int);
  ControladorProducto();
  // ControladorProducto(int, std::string, std::string, float, int, TipoProducto);
  ~ControladorProducto();
};

#endif