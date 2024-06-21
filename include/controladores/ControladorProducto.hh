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
  static ControladorProducto *instancia;
  int lastID;
  ControladorProducto();

public:
  static ControladorProducto *getInstancia();
  void registrarDatosProductos(std::string nombre, int precio, int cant, std::string des, TipoProducto tipo);
  void altaNuevoProducto();
  DTProducto *obtenerProductoDisponible(int);
  std::set<DTProducto *> obtenerProductosDisponibles(); // falta hacerla en el cpp
  ~ControladorProducto();
};

#endif