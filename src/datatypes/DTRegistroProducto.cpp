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
bool DTRegistroProducto::getEnviadoCorrectamente(){
    return enviadoCorrectamente;
}
DTRegistroProducto::DTRegistroProducto(){}

DTRegistroProducto::DTRegistroProducto(int i, std::string n, int cant,float p,bool e)
{
  id = i;
  nombre = n;
  cantidad = cant;
  precio = p;
  enviadoCorrectamente = e;
}
DTRegistroProducto::~DTRegistroProducto() {}
// Sobrecarga de operador '<<'
void DTRegistroProducto::setPrint(std::ostream &out)
{
  out << id << ", " << nombre << ", " << cantidad << ", " << precio << ", " << enviadoCorrectamente;
}

std::ostream &operator<<(std::ostream &out, DTRegistroProducto &obj)
{
  obj.setPrint(out);
  return out;
}