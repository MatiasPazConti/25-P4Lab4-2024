#ifndef COMPRA
#define COMPRA
#include "DTFecha.hh"
#include "DTCliente.hh"
#include "DTRegistroProducto.hh"
#include <iostream>
#include <set>

class Compra
{
private:
  DTFecha fechaCompra;
  float montoFinal;
  DTCliente *cliente;
  std::set<DTRegistroProducto *> registroProductos;
public:
  DTFecha getFechaCompra();
  void setFechaCompra(int,int,int);
  float getMontoFinal();
  void setMontoFinal(float);
  DTCliente getCliente();
  void setCliente(DTCliente*);
  DTRegistroProducto* getRegistroProducto(int);
  void setRegistroProducto(DTRegistroProducto);
  Compra();
  Compra(DTFecha, float,DTCliente);
  ~Compra();
  float Compra::calcularMontoFinal(); // PENDIENTE
};

#endif