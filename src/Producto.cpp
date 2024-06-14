#include "../include/Producto.hh"

int Producto::getId(){
  return id;
}
void Producto::setId(int i){
  id = i;
}
std::string Producto::getNombre(){
  return nombre;
}
void Producto::setNombre(std::string n){
  nombre = n;
}
std::string Producto::getDescripcion(){
  return descripcion;
}
void Producto::setDescrpcion(std::string des){
  descripcion = des;
}
float Producto::getPrecio(){
  return precio;
}
void Producto::setPrecio(float pr){
  precio = pr;
}
int Producto::getCantidadEnStock(){
  return cantidadEnStock;
}
void Producto::setCantidadEnStock(int cant){
  cantidadEnStock = cant;
}
TipoProducto Producto::getTipoProducto(){
  return tipo;
}
void Producto::setTipoProducto(TipoProducto t){
  tipo = t;
}
Producto::Producto(){}
Producto::Producto(int i, std::string n, std::string d,float p, int cant,TipoProducto t){
  id = i;
  nombre = n;
  descripcion = d;
  precio = p;
  cantidadEnStock = cant;
  tipo = t;
}
Producto::~Producto(){};

