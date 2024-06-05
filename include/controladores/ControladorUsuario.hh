#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include "../interfaces/IControladorUsuario.hh"

class ControladorUsuario : public IControladorUsuario
{
private:
  static ControladorUsuario *instancia;
  ControladorUsuario();

public:
  static ControladorUsuario *getInstancia();
  virtual ~ControladorUsuario();
};

#endif