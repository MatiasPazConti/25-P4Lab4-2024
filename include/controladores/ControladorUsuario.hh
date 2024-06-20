#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include "../interfaces/IControladorUsuario.hh"
#include "../Cliente.hh"
#include "../Vendedor.hh"

typedef enum
{
  cliente,
  vendedor,
  nulo
} TipoUsuario;

class ControladorUsuario : public IControladorUsuario
{
private:
  std::set<Cliente *> clientes;
  std::set<Vendedor *> vendedores;
  TipoUsuario tipoUsuario;
  std::string nickname;
  std::string password;
  DTFecha fechaNacimiento;
  DTDireccion direccion;
  std::string ciudadResidencia;
  int codigoRUT;
  // static ControladorUsuario *instancia;

public:
  void resgitrarDatosUsuario(std::string, std::string, DTFecha, TipoUsuario); // Implementado
  void resgitrarDatosCliente(DTDireccion, std::string);                       // Implementado
  void resgitrarDatosVendedor(int);                                           // Implementado
  void altaNuevoUsuario();                                                    // Implementado
  std::set<DTUsuario> listarUsuarios();
  std::set<DTCliente> listarClientes();
  std::set<DTVendedor> listarVendedores();
  std::set<DTVendedor> listarVendedoresNoSuscritos(std::string);
  // std::set<DTProducto> listarProductosVendedor(std::string);
  std::set<DTNotificacion> listarNotificaciones(std::string);
  std::set<DTVendedor> listarSuscripciones(std::string);
  void realizarSuscripciones(std::string, std::set<std::string>);
  void eliminarSuscripciones(std::string, std::set<std::string>);
  std::set<DTComentario> listarComentariosUsuario(std::string);
  // static ControladorUsuario *getInstancia();

  Cliente *obtenerCliente(std::string);

  // std::set<DTUsuario> listarUsuarios();
  // std::set<DTCliente *> listarClientes();
  // std::set<DTVendedor> listarVendedores();
  //  void resgitrarDatosUsuario(std::string, std::string, DTFecha); no va, no exiten usuarios solos, el cliente/vendedor llama al usuario
  //  void altaNuevoUsuario(); ya lo hace el sistema, inecesario hacerlo.
};

#endif