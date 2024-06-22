#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>
#include "./TipoProducto.hh"
#include "./datatypes/DTProducto.hh"

class Producto
{
private:
  int id;
  std::string nombre;
  std::string descripcion;
  float precio;
  int cantidadEnStock;
  TipoProducto tipo;

public:
  void setId(int);
  void setNombre(std::string);
  void setDescrpcion(std::string);
  void setPrecio(float);
  void setCantidadEnStock(int);
  void setTipoProducto(TipoProducto);
  int getId();
  std::string getNombre();
  std::string getDescripcion();
  float getPrecio();
  int getCantidadEnStock();
  TipoProducto getTipoProducto();
  DTProducto *getDataProducto();
  Producto();
  Producto(int, std::string, std::string, float, int, TipoProducto);
  ~Producto();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, Producto &obj); // cout Producto

#endif