#ifndef COMPRA
#define COMPRA

#include "./datatypes/DTFecha.hh"
#include "./datatypes/DTRegistroProducto.hh"
#include "Cliente.hh"
#include <iostream>
#include <set>

class Cliente;

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
  DTCompra *getDatosCompra();
  void setFechaCompra(int, int, int);
  void setMontoFinal(float);
  void setCliente(Cliente *);
  void addRegistroProducto(DTRegistroProducto *);
  Compra(DTFecha *, float, Cliente *);
  ~Compra();
};

#endif