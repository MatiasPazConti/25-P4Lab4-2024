#include "../include/Compra.hh"

DTFecha *Compra::getFechaCompra()
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
std::set<DTRegistroProducto *> Compra::getRegistroProductos()
{
  return registroProductos;
}
DTCompra *Compra::getDatosCompra()
{
  DTCliente *infoCliente = cliente->getDataCliente();
  std::set<DTRegistroProducto *> copiaResgitroProductos;
  for (std::set<DTRegistroProducto *>::iterator it = registroProductos.begin(); it != registroProductos.end(); it++)
  {
    DTRegistroProducto *copiaRegistro = (*it)->copiarRegistroProducto();
    copiaResgitroProductos.insert(copiaRegistro);
  }
  DTCompra *dataCompra = new DTCompra(fechaCompra, montoFinal, infoCliente, registroProductos);
  return dataCompra;
}
void Compra::setFechaCompra(int dia, int mes, int anio)
{
  DTFecha *nuevaFecha = new DTFecha(dia, mes, anio);
  fechaCompra = nuevaFecha;
}
void Compra::setMontoFinal(float monto)
{
  montoFinal = monto;
}
void Compra::setCliente(Cliente *c)
{
  cliente = c;
}
void Compra::addRegistroProducto(DTRegistroProducto *reg)
{
  registroProductos.insert(reg);
}
Compra::Compra(DTFecha *fechaCompra, float montoFinal, Cliente *cliente)
{
  this->fechaCompra = fechaCompra;
  this->montoFinal = montoFinal;
  this->cliente = cliente;
}
Compra::~Compra()
{
  while (!registroProductos.empty())
  {
    std::set<DTRegistroProducto *>::iterator inicio = registroProductos.begin();
    DTRegistroProducto *aBorrar = *inicio;
    registroProductos.erase(inicio);
    delete aBorrar;
  }
  cliente = NULL;
  delete fechaCompra;
}