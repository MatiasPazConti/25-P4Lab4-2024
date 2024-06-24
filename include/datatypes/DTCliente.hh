#ifndef DTCLIENTE
#define DTCLIENTE

#include "./DTUsuario.hh"
#include "./DTDireccion.hh"
#include "./DTCompra.hh"

#include <iostream>
#include <set>

class DTCliente : public DTUsuario
{
private:
  DTDireccion direccion;
  std::string ciudadDeResidencia;
  std::set<DTCompra *> comprasPasadas;

public:
  DTDireccion getDireccion();
  std::string getCiudadDeResidencia();
  std::set<DTCompra *> getComprasPasadas();
  DTCliente(std::string nickname, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia);
  ~DTCliente();
};

#endif