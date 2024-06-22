#include "../include/Compra.hh"

DTFecha Compra::getFechaCompra()
{
  return fechaCompra;
}
float Compra::getMontoFinal()
{
  return montoFinal;
}
Cliente* Compra::getCliente()
{
  return cliente;
}
void Compra::setFechaCompra(int dia,int mes,int anio)
{
  fechaCompra = DTFecha(dia,mes,anio);
}
void Compra::setMontoFinal(float monto)
{
  montoFinal = monto;
}
void Compra::setCliente(Cliente* c)
{
  cliente = c;
}
DTRegistroProducto *Compra::getRegistroProducto(int id)
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
void Compra::setRegistroProducto(DTRegistroProducto reg)
{
  registroProductos.insert(&reg);
}
Compra::Compra(){}
Compra::Compra(DTFecha fecha, float monto, Cliente c)
{
  fechaCompra = fecha;
  montoFinal = monto;
  *cliente = c;
}
Compra::~Compra(){}

std::set<DTRegistroProducto*>Compra::getRegistroProductos(){
  return registroProductos;
}
