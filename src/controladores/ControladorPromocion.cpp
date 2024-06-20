#include "../../include/controladores/ControladorPromocion.hh"

ControladorPromocion::~ControladorPromocion() {}
ControladorPromocion::ControladorPromocion() {}
ControladorPromocion *ControladorPromocion::instancia = NULL;
ControladorPromocion *ControladorPromocion::getInstancia()
{
  if (instancia == NULL)
  {
    instancia = new ControladorPromocion();
  }
  return instancia;
}