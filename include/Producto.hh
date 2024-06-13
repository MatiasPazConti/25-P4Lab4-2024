#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>


class Producto
{
public:
enum class TipoProducto {   
    Electrodomesticos,
    Ropa,
    Otros
};
private:
  int id;
  std::string nombre;
  std::string descripcion;
  float precio;
  int cantidadEnStock;
  // ???
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
};

#endif