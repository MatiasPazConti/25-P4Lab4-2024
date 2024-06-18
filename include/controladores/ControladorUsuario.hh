#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include "../interfaces/IControladorUsuario.hh"
#include "../Cliente.hh"
#include "../Vendedor.hh"

#include <map>

class ControladorUsuario : public IControladorUsuario
{
private:
  std::map<std::string, Cliente> clientes;
  std::map<std::string, Vendedor> vendedores;
  std::string nickname;
  std::string contrasenia;
  DTFecha fechaNacimiento;
  std::string ciudadDeResidencia;
  DTDireccion direccion;
  int codigoRUT;
  static ControladorUsuario *instancia;

public:
  ControladorUsuario();
  ~ControladorUsuario();
  void resgitrarDatosCliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia);
  void resgitrarDatosVendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT);

  std::set<DTUsuario> listarUsuarios();
  std::set<DTCliente *> listarClientes();
  std::set<DTVendedor> listarVendedores();
  std::set<DTVendedor> listarVendedoresNoSuscritos(std::string);
  // std::set<DTProducto> listarProductosVendedor(std::string);
  std::set<DTNotificacion> listarNotificaciones(std::string);
  std::set<DTVendedor> listarSuscripciones(std::string);
  void realizarSuscripciones(std::string, std::set<std::string>);
  void eliminarSuscripciones(std::string, std::set<std::string>);
  std::set<DTComentario> listarComentariosUsuario(std::string);
  static ControladorUsuario *getInstancia();

  // void resgitrarDatosUsuario(std::string, std::string, DTFecha); no va, no exiten usuarios solos, el cliente/vendedor llama al usuario
  // void altaNuevoUsuario(); ya lo hace el sistema, inecesario hacerlo.
};

#endif