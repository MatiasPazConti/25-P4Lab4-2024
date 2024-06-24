#ifndef DTNOTIFICACION
#define DTNOTIFICACION
#include "./DTPromocion.hh"

#include <string>

class DTNotificacion
{
private:
  DTPromocion *promocion;
  std::string nicknameVendedor;

public:
  DTPromocion *getInfoPromocion();
  std::string getNicknameVendedor();
  DTNotificacion(DTPromocion *, std::string);
  ~DTNotificacion();
};

#endif