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
  DTFecha *fechaCompra;
  float montoFinal;
  Cliente *cliente;
  std::set<DTRegistroProducto *> registroProductos;

public:
  DTFecha *getFechaCompra();
  float getMontoFinal();
  Cliente *getCliente();
  DTRegistroProducto *getRegistroProducto(int);
  std::set<DTRegistroProducto *> getRegistroProductos();
  void setFechaCompra(int, int, int);
  void setMontoFinal(float);
  void setCliente(Cliente *);
  void addRegistroProducto(DTRegistroProducto *);
  Compra(DTFecha *, float, Cliente *);
  ~Compra();
};

#endif