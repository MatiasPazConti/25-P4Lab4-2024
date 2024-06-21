#ifndef I_CONTROLADOR_PROMOCION
#define I_CONTROLADOR_PROMOCION

#include <iostream>
#include "../datatypes/DTFecha.hh"

class IControladorPromocion
{
public:
  virtual void registrarDatosPromo(std::string nombre, std::string descripcion, DTFecha fehcaVencimiento) = 0;
  virtual void agregarAPromo(int id, int cantidadMin, float porcentajeDescuento) = 0;
  virtual void altaNuevaPromo() = 0;
};

#endif