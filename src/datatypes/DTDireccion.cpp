#include "../../include/datatypes/DTDireccion.hh"

DTDireccion::DTDireccion(std::string nombreCalle, int nroPuerta)
{
  this->nombreCalle = nombreCalle;
  this->nroPuerta = nroPuerta;
}

DTDireccion::DTDireccion() {}

DTDireccion::~DTDireccion()
{
}

std::string DTDireccion::getNombreCalle()
{
  return nombreCalle;
}

int DTDireccion::getNroPuerta()
{
  return nroPuerta;
}
