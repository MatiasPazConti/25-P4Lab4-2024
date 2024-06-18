#ifndef CLIENTE
#define CLIENTE

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTDireccion.hh"
#include "./datatypes/DTNotificacion.hh"
#include "./Usuario.hh"
#include "./Vendedor.hh"
#include "./Notificacion.hh"

class Cliente : public Usuario, public IObservador
{
private:
  DTDireccion direccion;
  std::string ciudadDeResidencia;
  std::set<Vendedor *> suscripciones;
  std::set<Notificacion *> notificaciones;

public:
  Cliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia);
  ~Cliente();
  DTUsuario getDataUsuario();
  std::set<DTNotificacion *> listarNotificaciones();
  void eliminarNotificaciones();
  std::string getCiudadDeResidencia();
};

#endif