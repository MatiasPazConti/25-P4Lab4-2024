#ifndef DTPRODUCTO
#define DTPRODUCTO
#include <iostream>
#include "../TipoProducto.hh"

class DTProducto
{
private:
  int id;
  std::string nombre;
  std::string descripcion;
  float precio;
  int cantidadEnStock;
  TipoProducto tipo;

public:
  int getId();
  std::string getNombre();
  std::string getDescripcion();
  float getPrecio();
  int getCantidadEnStock();
  TipoProducto getTipoProducto();
  DTProducto();
  DTProducto(int, std::string, std::string, float, int, TipoProducto);
  ~DTProducto();
};

#endif