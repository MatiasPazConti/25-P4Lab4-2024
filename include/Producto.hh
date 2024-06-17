#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>
#include "../include/TipoProducto.hh"



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
  int getId();
  void setId(int);
  std::string getNombre();
  void setNombre(std::string);
  std::string getDescripcion();
  void setDescrpcion(std::string);
  float getPrecio();
  void setPrecio(float);
  int getCantidadEnStock();
  void setCantidadEnStock(int);
  TipoProducto getTipoProducto();
  void setTipoProducto(TipoProducto);
  Producto();
  Producto(int, std::string, std::string,float,int,TipoProducto);
  ~Producto();
    void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, Producto &obj); // cout Producto


#endif