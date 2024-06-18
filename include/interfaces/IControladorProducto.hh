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
  virtual void registrarDatosProductos(std::string nombre, int precio, int cant, std::string des, TipoProducto tipo, int id) = 0;
  virtual void altaNuevoProducto() = 0;
  virtual void listarProductosDisponibles() = 0; // Usa DTProducto o Producto??? usa DT
  virtual std::set<DTProducto *> obtenerProductosDisponibles() = 0;
};

#endif