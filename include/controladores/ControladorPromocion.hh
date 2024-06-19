#ifndef CONTROLADOR_PROMOCION
#define CONTROLADOR_PROMOCION

#include <iostream>
#include <map>

#include "../interfaces/IControladorPromocion.hh"
#include "../fabrica/Fabrica.hh"
#include "../Promocion.hh"
#include "../datatypes/DTPromocion.hh"
#include "../datatypes/DTVendedor.hh"

class ControladorPromocion
{
private:
  std::string nombre;
  std::string descripcion;
  DTFecha fechaVencimiento;
  std::map<std::string, Promocion *> promos; // promociones identificadas por nombre

public:
  std::string getNombre();
  std::string getDescripcion();
  DTFecha getFechaVencimiento();
  void setNombre(std::string);
  void setDecripcion(std::string);
  void setFechaVencimiento(DTFecha);

  void registrarDatosPromo(std::string, std::string, DTFecha);
  void asignarVendedor(std::string); // le paso el nick?
  void asignarAPromo();
  // void agregarAPromo(int, int)
  void altaNuevaPromo();
};

#endif