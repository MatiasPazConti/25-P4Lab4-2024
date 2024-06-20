#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

#include "../datatypes/DTFecha.hh"
#include "../datatypes/DTDireccion.hh"
#include "../datatypes/DTCliente.hh"
#include "../datatypes/DTVendedor.hh"
#include "../datatypes/DTNotificacion.hh"
#include "../datatypes/DTProducto.hh"
#include "../datatypes/DTComentario.hh"
#include "../Cliente.hh"

#include <iostream>
#include <set>

class IControladorUsuario
{
public:
  virtual Cliente *getCliente(std::string) = 0;
  virtual Vendedor *getVendedor(std::string) = 0;
  virtual void registrarDatosUsuario(std::string, std::string, DTFecha, TipoUsuario) = 0;
  virtual void registrarDatosCliente(DTDireccion, std::string) = 0;
  virtual void registrarDatosVendedor(int) = 0;
  virtual void altaNuevoUsuario() = 0;
  virtual void realizarSuscripciones(std::string, std::set<std::string>) = 0;
  virtual void eliminarSuscripciones(std::string, std::set<std::string>) = 0;
  virtual std::set<DTUsuario *> listarUsuarios() = 0;
  virtual std::set<DTCliente *> listarClientes() = 0;
  virtual std::set<DTVendedor *> listarVendedores() = 0;
  virtual std::set<DTVendedor *> listarVendedoresNoSuscritos(std::string) = 0;
  virtual std::set<DTProducto *> listarProductosVendedor(std::string) = 0;
  virtual std::set<DTNotificacion *> listarNotificaciones(std::string) = 0;
  virtual std::set<DTVendedor *> listarSuscripciones(std::string) = 0;
  virtual std::set<DTComentario *> listarComentariosUsuario(std::string) = 0;
};

#endif