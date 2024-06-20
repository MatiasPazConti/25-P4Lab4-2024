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
}