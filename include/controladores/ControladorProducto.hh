#ifndef CONTROLADOR_PRODUCTO
#define CONTROLADOR_PRODUCTO

#include "../datatypes/DTProducto.hh"
#include "../interfaces/IControladorProducto.hh"
#include "../TipoProducto.hh"
#include "../Producto.hh"
#include <iostream>
#include <set>

class ControladorProducto : public IControladorProducto
{
private:
  std::set<Producto *> productos;
  static ControladorProducto *instancia;
  int lastID;
  ControladorProducto();

public:
  static ControladorProducto *getInstancia();
  void registrarDatosProductos(std::string, float, int, std::string, TipoProducto, std::string);
  DTProducto *obtenerProductoDisponible(int);
  std::set<DTProducto *> obtenerProductosDisponibles(); // falta hacerla en el cpp // agregado PD chequearlo.
  ~ControladorProducto();
};

#endif