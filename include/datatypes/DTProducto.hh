#ifndef DTPRODUCTO
#define DTPRODUCTO

#include <iostream>
#include "../TipoProducto.hh"

class Promocion;
class DTVendedor;
class DTProducto
{
private:
  int id;
  std::string nombre;
  std::string descripcion;
  float precio;
  int cantidadEnStock;
  TipoProducto tipo;
  DTVendedor *vendedor;
  Promocion *promo;
public:
  int getId();
  std::string getNombre();
  std::string getDescripcion();
  float getPrecio();
  int getCantidadEnStock();
  TipoProducto getTipoProducto();
  DTVendedor *getVendedor();
  Promocion *getPromocion();
  DTProducto();
  DTProducto(int, std::string, std::string, float, int, TipoProducto, DTVendedor *);
  ~DTProducto();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};
std::ostream &operator<<(std::ostream &out, DTProducto &obj); // cout Producto

#endif