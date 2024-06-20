#ifndef I_OBSERVADOR
#define I_OBSERVADOR

#include "../datatypes/DTNotificacion.hh"

class IObservador
{
public:
  virtual void notificar() = 0;
};

#endif