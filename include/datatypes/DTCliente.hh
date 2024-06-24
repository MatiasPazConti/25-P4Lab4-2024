#ifndef DTCLIENTE
#define DTCLIENTE

#include "./DTUsuario.hh"
#include "./DTCompra.hh"
#include "./DTDireccion.hh"

#include <iostream>
#include <set>

class DTCompra;

class DTCliente : public DTUsuario
{
private:
  DTDireccion *direccion;
  std::string ciudadDeResidencia;
  std::set<DTCompra *> comprasPrevias;

public:
  DTDireccion *getDireccion();
  std::string getCiudadDeResidencia();
  std::set<DTCompra *> getComprasPrevias();
  DTCliente(std::string, DTFecha *, DTDireccion *, std::string, std::set<DTCompra *>);
  ~DTCliente();
};

#endif