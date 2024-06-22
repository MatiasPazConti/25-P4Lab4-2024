#ifndef DTPRODUCTO
#define DTPRODUCTO
#include <iostream>
#include "../TipoProducto.hh"
#include "DTVendedor.hh"
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
  DTVendedor* vendedor;

public:
  int getId();
  std::string getNombre();
  std::string getDescripcion();
  float getPrecio();
  int getCantidadEnStock();
  TipoProducto getTipoProducto();
  DTVendedor* getVendedor();
  DTProducto();
  DTProducto(int, std::string, std::string, float, int, TipoProducto, DTVendedor*);
  ~DTProducto();
};

#endif