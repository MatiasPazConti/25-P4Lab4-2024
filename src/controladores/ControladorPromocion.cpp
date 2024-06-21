#include "../../include/controladores/ControladorPromocion.hh"

ControladorPromocion::~ControladorPromocion()
{
}
ControladorPromocion::ControladorPromocion() {}

ControladorPromocion *ControladorPromocion::instancia = nullptr;
ControladorPromocion *ControladorPromocion::getInstancia()
{
  if (instancia == nullptr)
  {
    instancia = new ControladorPromocion();
  }
  return instancia;
}