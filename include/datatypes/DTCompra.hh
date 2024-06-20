#ifndef DTCOMPRA
#define DTCOMPRA
#include "DTFecha.hh"
#include "DTCliente.hh"
#include "DTRegistroProducto.hh"

#include <iostream>
#include <set>

class DTCompra
{
private:
  DTFecha fechaDeCompra;
  std::set<DTRegistroProducto *> registroProductos;
  float montoFinal;
  DTCliente *cliente;
public:
  DTFecha getFechaDeCompra();
  DTRegistroProducto* getRegistroProducto(int); // queremos un solo producto o todo el set?? 
  float getMontoFinal();
  DTCliente getCliente();
  void setCliente(DTCliente*);
  DTCompra();
  DTCompra(DTFecha, float);
  ~DTCompra();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTCompra &obj); // cout DTInfoEstudian

#endif