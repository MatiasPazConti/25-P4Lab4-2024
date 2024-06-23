#include "../include/Producto.hh"

int Producto::getId()
{
  return id;
}
void Producto::setId(int i)
{
  id = i;
}
std::string Producto::getNombre()
{
  return nombre;
}
void Producto::setNombre(std::string n)
{
  nombre = n;
}
std::string Producto::getDescripcion()
{
  return descripcion;
}
void Producto::setDescrpcion(std::string des)
{
  descripcion = des;
}
float Producto::getPrecio()
{
  return precio;
}
void Producto::setPrecio(float pr)
{
  precio = pr;
}
int Producto::getCantidadEnStock()
{
  return cantidadEnStock;
}
void Producto::setCantidadEnStock(int cant)
{
  cantidadEnStock = cant;
}
TipoProducto Producto::getTipoProducto()
{
  return tipo;
}
void Producto::setTipoProducto(TipoProducto t)
{
  tipo = t;
}
DTProducto *Producto::getDataProducto()
{
  DTProducto *dataProducto = new DTProducto(id, nombre, descripcion, precio, cantidadEnStock, tipo, vendedor);
  return dataProducto;
}
DTVendedor* Producto::getVendedor(){
  return vendedor;
}
void Producto::setVendedor(DTVendedor* v){
    vendedor = v;
}
Producto::Producto() {}
Producto::Producto(int i, std::string n, std::string d, float p, int cant, TipoProducto t , DTVendedor* v)
{
  id = i;
  nombre = n;
  descripcion = d;
  precio = p;
  cantidadEnStock = cant;
  tipo = t;
  vendedor = v;
  promo = NULL;
}
Producto::~Producto(){};

// Sobrecarga de operador '<<'
void Producto::setPrint(std::ostream &out)
{
  out << id << ", " << nombre;
}

std::ostream &operator<<(std::ostream &out, Producto &obj)
{
  obj.setPrint(out);
  return out;
}
Promocion* Producto::getPromocion(){
  return promo;
}
void Producto::setPromocion(Promocion* p){
  promo = p;
}