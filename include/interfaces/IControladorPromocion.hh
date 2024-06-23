#ifndef I_CONTROLADOR_PROMOCION
#define I_CONTROLADOR_PROMOCION

#include "../Promocion.hh"
#include <iostream>
#include "../datatypes/DTFecha.hh"

class IControladorPromocion
{
public:
  virtual void agregarAPromo(int id, int cantidadMin, float porcentajeDescuento) = 0;
  virtual void altaNuevaPromo() = 0;
  virtual void registrarDatosPromo(std::string, std::string, DTFecha);
};

#endif