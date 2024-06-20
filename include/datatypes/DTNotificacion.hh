#ifndef DTNOTIFICACION
#define DTNOTIFICACION
#include <string>

class DTNotificacion
{
private:
  int idNotificacion;
  std::string nombrePromocion;
  std::string nicknameVendedor;

public:
  int getIdNotificacion();
  std::string getNombrePromocion();
  std::string getNicknameVendedor();
  DTNotificacion(int, std::string, std::string);
  ~DTNotificacion();
};

#endif