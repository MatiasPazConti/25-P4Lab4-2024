#ifndef I_CONTROLADOR_PRODUCTO
#define I_CONTROLADOR_PRODUCTO

#include "../datatypes/DTFecha.hh"
#include "../datatypes/DTDireccion.hh"
#include "../datatypes/DTCliente.hh"
#include "../datatypes/DTVendedor.hh"
#include "../datatypes/DTNotificacion.hh"
#include "../datatypes/DTProducto.hh"
#include "../datatypes/DTComentario.hh"

#include <iostream>
#include <set>

class IControladorProducto
{
public:
  virtual void registrarDatosProductos(std::string nombre, int precio, int cant, std::string des, TipoProducto tipo ,DTVendedor* vendedor) = 0;
  virtual void altaNuevoProducto() = 0;
  virtual DTProducto *obtenerProductoDisponible(int) = 0;
  virtual Producto *getProducto(int) = 0;
  virtual std::set<DTProducto *> obtenerProductosDisponibles() = 0;
};

#endif