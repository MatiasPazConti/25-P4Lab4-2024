#include "../../include/fabrica/Fabrica.hh"
#include "../../include/controladores/ControladorUsuario.hh"
#include "../../include/controladores/ControladorProducto.hh"

Fabrica *Fabrica::fabrica = 0;

Fabrica::Fabrica()
{
}

Fabrica::~Fabrica()
{
}

IControladorUsuario *Fabrica::getInterfazUsuario()
{
  if (!this->controladorUsuario)
  {
    controladorUsuario = new ControladorUsuario();
  }
  return controladorUsuario;
}

IControladorProducto *Fabrica::getInterfazProducto()
{
  if (!this->controladorProducto)
  {
    controladorProducto = new ControladorProducto();
  }
  return controladorProducto;
}

Fabrica *Fabrica::getInstance()
{
  if (fabrica == nullptr)
  {
    fabrica = new Fabrica();
  }
  return fabrica;
}