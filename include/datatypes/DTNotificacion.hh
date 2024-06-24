#ifndef DTNOTIFICACION
#define DTNOTIFICACION
#include "./DTPromocion.hh"

#include <string>

class DTNotificacion
{
private:
  DTPromocion *promocion;

public:
  DTPromocion *getInfoPromocion();
  DTNotificacion *copiarNotificacion();
  DTNotificacion(DTPromocion *);
  ~DTNotificacion();
  void setPrint(std::ostream &out);
};

std::ostream &operator<<(std::ostream &out, DTNotificacion &obj);

#endif