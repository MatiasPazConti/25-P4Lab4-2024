#ifndef CLIENTE
#define CLIENTE

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTCliente.hh"
#include "./datatypes/DTDireccion.hh"
#include "./Compra.hh"
#include "./Usuario.hh"
#include "./Vendedor.hh"

#include <set>

class Compra;
class Vendedor;

class Cliente : public Usuario, public IObservador
{
private:
  DTDireccion *direccion;
  std::string ciudadDeResidencia;
  std::set<Vendedor *> suscripciones;
  std::set<Compra *> comprasPrevias;
  std::set<DTNotificacion *> notificaciones;

public:
  DTDireccion *getDireccion();
  std::string getCiudadDeResidencia();
  std::set<Vendedor *> getSuscripciones();
  std::set<Compra *> getComprasPrevias();
  DTCliente *getDataCliente();
  void añadirSuscripcion(Vendedor *);
  void añadirCompra(Compra *);
  void removerSuscripcion(Vendedor *);
  void removerCompra(Compra *);
  void notificar(DTNotificacion *);
  void eliminarNotificaciones();
  std::set<DTNotificacion *> listarNotificaciones();
  Cliente(std::string nickname, std::string password, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadDeResidencia);
  ~Cliente();
};

#endif