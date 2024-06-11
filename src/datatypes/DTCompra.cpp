#include "../../include/datatypes/DTCompra.hh"

DTFecha DTCompra::getFechaDeCompra()
{
  return fechaDeCompra;
}
DTRegistroProducto *DTCompra::getRegistroProducto(int id)
{
  for (std::set<DTRegistroProducto *>::iterator it = registroProductos.begin(); it != registroProductos.end(); ++it)
  {
    if ((*it)->getId() == id)
    {
      return *it;
    }
  }
  return NULL;
}
float DTCompra::getMontoFinal(){
    return montoFinal;
}
DTCompra::DTCompra(){}
DTCompra::DTCompra(DTFecha f, float m)
{
  fechaDeCompra = f;
  montoFinal = m;
}
DTCompra::~DTCompra() {}
// Sobrecarga de operador '<<'
void DTCompra::setPrint(std::ostream &out)
{
  out << fechaDeCompra.toString() << ", " << montoFinal; // Se imprime todo??
}

std::ostream &operator<<(std::ostream &out, DTCompra &obj)
{
  obj.setPrint(out);
  return out;
}