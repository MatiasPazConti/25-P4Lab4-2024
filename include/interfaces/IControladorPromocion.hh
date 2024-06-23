#ifndef I_CONTROLADOR_PROMOCION
#define I_CONTROLADOR_PROMOCION

#include "../Promocion.hh"
#include <iostream>
#include "../datatypes/DTFecha.hh"

class IControladorPromocion
{
public:
  virtual std::map<std::string, Promocion *> obtenerPromocionesVigentes() = 0;
  virtual void registrarDatosPromo(std::string nombre, std::string descripcion, DTFecha fehcaVencimiento, float porcentaje) = 0;
  virtual void agregarAPromo(int id, int cantidadMin) = 0;
  virtual void altaNuevaPromo() = 0;
};

#endif