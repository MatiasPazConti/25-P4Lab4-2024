#include "../../include/datatypes/DTRegistroProducto.hh"

int DTRegistroProducto::getId()
{
  return id;
}
std::string DTRegistroProducto::getNombre()
{
  return nombre;
}
int DTRegistroProducto::getCantidad()
{
  return cantidad;
}
float DTRegistroProducto::getPrecio(){
    return precio;
}
Promocion* DTRegistroProducto::getPromo(){
    return promo;
}
DTRegistroProducto::DTRegistroProducto(){}

DTRegistroProducto::DTRegistroProducto(int i, std::string n, int cant,float p, Promocion* pro)
{
  id = i;
  nombre = n;
  cantidad = cant;
  precio = p;
  promo = pro;
}
DTRegistroProducto::~DTRegistroProducto() {}
// Sobrecarga de operador '<<'
void DTRegistroProducto::setPrint(std::ostream &out)
{
  out << id << ", " << nombre << ", " << cantidad << ", " << precio;
}

std::ostream &operator<<(std::ostream &out, DTRegistroProducto &obj)
{
  obj.setPrint(out);
  return out;
}