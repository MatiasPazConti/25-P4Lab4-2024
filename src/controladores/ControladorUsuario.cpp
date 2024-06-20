#include "../../include/controladores/ControladorUsuario.hh"

void ControladorUsuario::resgitrarDatosUsuario(std::string nick, std::string pass, DTFecha fecha, TipoUsuario tipo)
{
  nickname = nick;
  password = pass;
  fechaNacimiento = fecha;
  tipoUsuario = tipo;
}

void ControladorUsuario::resgitrarDatosCliente(DTDireccion dir, std::string ciudad)
{
  direccion = dir;
  ciudadResidencia = ciudad;
}

void ControladorUsuario::resgitrarDatosVendedor(int rut)
{
  codigoRUT = rut;
}

void ControladorUsuario::altaNuevoUsuario()
{
  if (tipoUsuario == cliente)
  {
    Cliente *nuevoCliente = new Cliente(nickname, password, fechaNacimiento, direccion, ciudadResidencia);
    clientes.insert(nuevoCliente);
  }
  if (tipoUsuario == vendedor)
  {
    Vendedor *nuevoVendedor = new Vendedor(nickname, password, fechaNacimiento, codigoRUT);
    vendedores.insert(nuevoVendedor);
  }
  tipoUsuario = nulo;
  void ControladorUsuario::resgitrarDatosCliente(std::string nickname, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudadDeResidencia)
  {
    Cliente *nuevoCliente = new Cliente(nickname, password, fechaNacimiento, direccion, ciudadDeResidencia);
    clientes.insert(std::pair<std::string, Cliente *>(nickname, nuevoCliente));
  }

  void ControladorUsuario::resgitrarDatosVendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT)
  {
    Vendedor *nuevoVendedor = new Vendedor(nickname, password, fechaNacimiento, codigoRUT);
    vendedores.insert(std::pair<std::string, Vendedor *>(nickname, nuevoVendedor));
  }

  void ControladorUsuario::listarVendedores()
  {
    for (auto it = vendedores.begin(); it != vendedores.end(); it++)
    {
      std::string nick = it->second->getNickname();
      DTFecha fecha = it->second->getFechaNacimiento();
      int dia = fecha.getDia();
      int mes = fecha.getMes();
      int anio = fecha.getAnio();
      std::string rut = it->second->getCodigoRUT();
      std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << ", Codigo RUT: " << rut;
      std::cout << std::endl;
    };
  }

  void ControladorUsuario::listarClientes()
  {
    for (auto it = clientes.begin(); it != clientes.end(); it++)
    {
      std::string nick = it->second->getNickname();
      DTFecha fecha = it->second->getFechaNacimiento();
      int dia = fecha.getDia();
      int mes = fecha.getMes();
      int anio = fecha.getAnio();
      DTDireccion direccion = it->second->getDireccion();
      std::string calle = direccion.getNombreCalle();
      int nroPuerta = direccion.getNroPuerta();
      std::string ciudad = it->second->getCiudadDeResidencia();
      std::cout << "Nickname: " << nick << ", Fecha de naciemiento: " << dia << "/" << mes << "/" << anio << ", Direccion: " << calle << "," << nroPuerta << ", Ciudad: " << ciudad;
      std::cout << std::endl;
    };
  }

  void ControladorUsuario::listarUsuarios()
  {
    this->listarClientes();
    this->listarVendedores();
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

  /*ControladorUsuario *ControladorUsuario::getInstancia()
  {
    return nullptr;
  }*/

  ControladorUsuario::ControladorUsuario()
  {
    vendedores.clear();
    clientes.clear();
  }

  ControladorUsuario::~ControladorUsuario()
  {
  }

  Cliente *ControladorUsuario::obtenerCliente(std::string nickname)
  {
    return clientes[nickname];
  }