#include "../include/Compra.hh"

DTFecha Compra::getFechaCompra()
{
  return fechaCompra;
}
float Compra::getMontoFinal()
{
  return montoFinal;
}
Cliente Compra::getCliente()
{
  return *cliente;
}
void Compra::setFechaCompra(int dia,int mes,int anio)
{
  fechaCompra = DTFecha(dia,mes,anio);
}
void Compra::setMontoFinal(float monto)
{
  montoFinal = monto;
}
void Compra::setCliente(Cliente c)
{
  *cliente = c;
}
Compra::Compra(){}
Compra::Compra(DTFecha fecha, float monto, Cliente c)
{
  fechaCompra = fecha;
  montoFinal = monto;
  *cliente = c;
}
Compra::~Compra(){}
float Compra::calcularMontoFinal(){} // PENDIENTE
