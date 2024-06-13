#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include "../interfaces/IControladorUsuario.hh"

class ControladorUsuario : public IControladorUsuario
{
private:
  std::string nickname;
  std::string contrasenia;
  DTFecha fechaNacimiento;
  std::string ciudadResidencia;
  DTDireccion direccion;
  int codigoRUT;
  static ControladorUsuario *instancia;
  ControladorUsuario();

public:
  void resgitrarDatosUsuario(std::string, std::string, DTFecha);
  void resgitrarDatosCliente(std::string, DTDireccion);
  void resgitrarDatosVendedor(int);
  void altaNuevoUsuario();
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
  static ControladorUsuario *getInstancia();
  virtual ~ControladorUsuario();
};

#endif