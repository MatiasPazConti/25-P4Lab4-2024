#ifndef CLIENTE
#define CLIENTE

#include "../interfaces/IObservador.hh"
#include "./datatypes/DTDireccion.hh"
#include "./datatypes/DTNotificacion.hh"
#include "./Usuario.hh"
#include "./Vendedor.hh"
#include "./Notificacion.hh"

class Usuario;
class Vendedor;

class Cliente : public Usuario, public IObservador
{
private:
  DTDireccion direccion;
  std::string ciudadResidencia;
  std::set<Vendedor *> suscripciones;
  std::set<Notificacion *> notificaciones;

public:
  DTUsuario getDataUsuario();
  std::set<DTNotificacion *> listarNotificaciones();
  void eliminarNotificaciones();
  Cliente(std::string, std::string, DTFecha, DTDireccion, std::string);
  ~Cliente();
};

#endif