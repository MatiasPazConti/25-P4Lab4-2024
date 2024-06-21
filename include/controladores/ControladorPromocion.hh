#ifndef CONTROLADOR_PROMOCION
#define CONTROLADOR_PROMOCION

#include "../interfaces/IControladorPromocion.hh"
#include <set>

class ControladorPromocion : public IControladorPromocion
{
private:
  std::set<Promocion *> promociones;
  static ControladorPromocion *instancia;
  ControladorPromocion();

public:
  static ControladorPromocion *getInstancia();

  ~ControladorPromocion();
};

#endif