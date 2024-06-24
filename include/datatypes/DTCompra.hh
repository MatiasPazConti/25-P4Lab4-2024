#ifndef DTCOMPRA
#define DTCOMPRA
#include "./DTFecha.hh"
#include "./DTCliente.hh"
#include "./DTRegistroProducto.hh"

#include <iostream>
#include <set>

class DTCliente;

class DTCompra
{
private:
  DTFecha *fechaDeCompra;
  float montoFinal;
  DTCliente *cliente;
  std::set<DTRegistroProducto *> registroProductos;

public:
  DTFecha *getFechaDeCompra();
  DTRegistroProducto *getRegistroProducto(int);
  std::set<DTRegistroProducto *> getRegistroProductos();
  float getMontoFinal();
  DTCliente *getCliente();
  DTCompra(DTFecha *, float, DTCliente *, std::set<DTRegistroProducto *>);
  ~DTCompra();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTCompra &obj); // cout

#endif