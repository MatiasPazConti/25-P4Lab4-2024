#ifndef COMPRA
#define COMPRA

#include "./datatypes/DTFecha.hh"
#include "Cliente.hh"
#include "./datatypes/DTRegistroProducto.hh"
#include <iostream>
#include <set>

class Compra
{
private:
  DTFecha fechaCompra;
  float montoFinal;
  Cliente *cliente;
  std::set<DTRegistroProducto *> registroProductos;

public:
  DTFecha getFechaCompra();
  void setFechaCompra(int, int, int);
  float getMontoFinal();
  void setMontoFinal(float);
  Cliente *getCliente();
  void setCliente(Cliente *);
  DTRegistroProducto *getRegistroProducto(int);
  void setRegistroProducto(DTRegistroProducto);
  Compra();
  Compra(DTFecha, float, Cliente);
  ~Compra();
};

#endif