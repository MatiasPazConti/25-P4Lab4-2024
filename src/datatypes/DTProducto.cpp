#include "../../include/datatypes/DTProducto.hh"

int DTProducto::getId(){
  return id;
}
std::string DTProducto::getNombre(){
  return nombre;
}
std::string DTProducto::getDescripcion(){
  return descripcion;
}
float DTProducto::getPrecio(){
  return precio;
}
int DTProducto::getCantidadEnStock(){
  return cantidadEnStock;
}
TipoProducto DTProducto::getTipoProducto(){
  return tipo;
}
DTProducto::DTProducto(){}
DTProducto::DTProducto(int i, std::string n, std::string d,float p, int cant,TipoProducto t){
  id = i;
  nombre = n;
  descripcion = d;
  precio = p;
  cantidadEnStock = cant;
  tipo = t;
}
DTProducto::~DTProducto(){};
