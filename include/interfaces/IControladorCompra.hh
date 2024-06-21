#ifndef I_CONTROLADOR_COMPRA
#define I_CONTROLADOR_COMPRA

#include "../datatypes/DTFecha.hh"
#include "../datatypes/DTDireccion.hh"
#include "../datatypes/DTCliente.hh"
#include "../datatypes/DTVendedor.hh"
#include "../datatypes/DTNotificacion.hh"
#include "../datatypes/DTProducto.hh"
#include "../datatypes/DTComentario.hh"

// #include "../fabrica/Fabrica.hh"

class IControladorCompra
{
public:
  virtual void crearCompra(std::string, int, int, int) = 0; // dia/mes/anio de hoy
  virtual void asignarCliente(std::string) = 0;
  virtual void agregarProductoACompra(int, int) = 0;
  virtual void obtenerDatosCompra() = 0;
  virtual void registrarCompraExitosa() = 0;
};

#endif