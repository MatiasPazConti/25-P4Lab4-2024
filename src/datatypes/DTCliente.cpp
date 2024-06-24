#include "../../include/datatypes/DTCliente.hh"

DTDireccion *DTCliente::getDireccion()
{
  return direccion;
}
std::string DTCliente::getCiudadDeResidencia()
{
  return ciudadDeResidencia;
}
std::set<DTCompra *> DTCliente::getComprasPrevias()
{
  return comprasPrevias;
}
DTCliente::DTCliente(std::string nickname, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadDeResidencia, std::set<DTCompra *> comprasPrevias)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
  this->comprasPrevias = comprasPrevias;
}
DTCliente::~DTCliente()
{
  delete direccion;
  while (!comprasPrevias.empty())
  {
    std::set<DTCompra *>::iterator inicio = comprasPrevias.begin();
    DTCompra *aBorrar = *inicio;
    comprasPrevias.erase(inicio);
    delete aBorrar;
  }
  DTUsuario::~DTUsuario();
}
