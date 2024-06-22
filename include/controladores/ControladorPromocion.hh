#ifndef CONTROLADOR_PROMOCION
#define CONTROLADOR_PROMOCION

#include <iostream>
#include <set>
#include <map>

#include "../interfaces/IControladorPromocion.hh"
#include "../fabrica/Fabrica.hh"
#include "../Promocion.hh"
#include "../datatypes/DTPromocion.hh"
#include "../datatypes/DTVendedor.hh"
#include <set>

class ControladorPromocion : public IControladorPromocion
{
private:
  static ControladorPromocion *instancia;
  ControladorPromocion();
  std::string nombre;
  std::string descripcion;
  DTFecha fechaVencimiento;
  Vendedor *vendedor;                              // vendedor asigando a la promo
  std::set<Producto *> productos;                  // productos de la promo
  std::map<int, InfoPromoProducto> infoProductos;  // info promo productos identificado por id
  std::map<int, DTProductoPromo> dtProductosPromo; // data producto promo identificado por id
  std::map<std::string, Promocion *> promociones;  // promociones identificadas por nombre

public:
  static ControladorPromocion *getInstancia();
  ~ControladorPromocion();
  void registrarDatosPromo(std::string nombre, std::string descripcion, DTFecha fechaVencimiento);
  void asignarVendedor(std::string nombre);
  void agregarAPromo(int id, int cantMin, float porcentajeDescuento);
  void altaNuevaPromo();
};

#endif