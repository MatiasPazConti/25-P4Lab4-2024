#ifndef I_CONTROLADOR_PROMOCION
#define I_CONTROLADOR_PROMOCION

#include <iostream>
#include "../datatypes/DTFecha.hh"

class IControladorPromocion
{
public:
  virtual void registrarDatosPromo(std::string, std::string, DTFecha) = 0;
  virtual void agregarAPromo() = 0;
  virtual void altaNuevaPromo() = 0;
};

#endif