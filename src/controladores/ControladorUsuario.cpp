#include "../../include/controladores/ControladorUsuario.hh"

void ControladorUsuario::resgitrarDatosCliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia)
{
  new Cliente(nickname, password, fechaNacimiento, direccion, ciudadDeResidencia);
}

void ControladorUsuario::resgitrarDatosVendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT)
{
  new Vendedor(nickname, password, fechaNacimiento, codigoRUT);
}

std::set<DTUsuario> ControladorUsuario::listarUsuarios()
{
  return std::set<DTUsuario>();
}

std::set<DTCliente *> ControladorUsuario::listarClientes()
{
  return std::set<DTCliente *>();
}

std::set<DTVendedor> ControladorUsuario::listarVendedores()
{
  return std::set<DTVendedor>();
}

std::set<DTVendedor> ControladorUsuario::listarVendedoresNoSuscritos(std::string)
{
  return std::set<DTVendedor>();
}

std::set<DTNotificacion> ControladorUsuario::listarNotificaciones(std::string)
{
  return std::set<DTNotificacion>();
}

std::set<DTVendedor> ControladorUsuario::listarSuscripciones(std::string)
{
  return std::set<DTVendedor>();
}

void ControladorUsuario::realizarSuscripciones(std::string, std::set<std::string>)
{
}

void ControladorUsuario::eliminarSuscripciones(std::string, std::set<std::string>)
{
}

std::set<DTComentario> ControladorUsuario::listarComentariosUsuario(std::string)
{
  return std::set<DTComentario>();
}

ControladorUsuario *ControladorUsuario::getInstancia()
{
  return nullptr;
}

ControladorUsuario::ControladorUsuario()
{
}

ControladorUsuario::~ControladorUsuario()
{
}
