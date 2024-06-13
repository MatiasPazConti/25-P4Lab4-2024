#ifndef COMPRA
#define COMPRA
#include "DTFecha.hh"
#include "Cliente.hh"
#include <iostream>


class Compra
{
private:
  DTFecha fechaCompra;
  float montoFinal;
  Cliente *cliente;
public:
  DTFecha getFechaCompra();
  void setFechaCompra(int,int,int);
  float getMontoFinal();
  void setMontoFinal(float);
  Cliente getCliente();
  void setCliente(Cliente);
  Compra();
  Compra(DTFecha, float,Cliente);
  ~Compra();
  float Compra::calcularMontoFinal(); // PENDIENTE
};

#endif