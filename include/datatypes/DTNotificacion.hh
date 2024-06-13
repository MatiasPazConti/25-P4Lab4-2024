#ifndef DTNOTIFICACION
#define DTNOTIFICACION

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