#ifndef DTNOTIFICACION
#define DTNOTIFICACION
#include <string>

class DTNotificacion
{
private:
  std::string nombrePromocion;
  std::string nicknameVendedor;

public:
  std::string getNombrePromocion();
  std::string getNicknameVendedor();
  DTNotificacion(std::string, std::string);
  ~DTNotificacion();
};

class DTNotificacion
{
private:
  std::string aviso;

public:
  std::string getAviso();
  DTNotificacion(std::string);
  ~DTNotificacion();
};

#endif