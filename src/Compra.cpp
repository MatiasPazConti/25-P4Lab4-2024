#include "../include/Compra.hh"

DTFecha Compra::getFechaCompra()
{
  return fechaCompra;
}
float Compra::getMontoFinal()
{
  return montoFinal;
}
Cliente *Compra::getCliente()
{
  return cliente;
}
void Compra::setFechaCompra(int dia, int mes, int anio)
{
  fechaCompra = DTFecha(dia, mes, anio);
}
void Compra::setMontoFinal(float monto)
{
  montoFinal = monto;
}
void Compra::setCliente(Cliente *c)
{
  cliente = c;
}
DTRegistroProducto *Compra::getRegistroProducto(int id)
{
  if (!registroProductos.empty())
  {
    for (std::set<DTRegistroProducto *>::iterator it = registroProductos.begin(); it != registroProductos.end(); ++it)
    {
      if ((*it)->getId() == id)
      {
        return *it;
      }
    }
  }
  return NULL;
}
void Compra::setRegistroProducto(DTRegistroProducto *reg)
{
  std::cout << "Error 40" << std::endl;
  registroProductos.insert(reg);
  std::cout << "Error 41" << std::endl;
}
DTCompra *Compra::getDataCompra()
{
  DTCompra *compra = new DTCompra(fechaCompra, montoFinal, registroProductos, cliente->getDataCliente());
  return compra;
}
Compra::Compra() {}
Compra::Compra(DTFecha fecha, float monto, Cliente c)
{
  fechaCompra = fecha;
  montoFinal = monto;
  *cliente = c;
}
Compra::~Compra() {}

std::set<DTRegistroProducto *> Compra::getRegistroProductos()
{
  return registroProductos;
}
