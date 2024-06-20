#include "../include/Vendedor.hh"

Vendedor::Vendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT) : Usuario(nickname, password, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}

Vendedor::~Vendedor() {}

void Vendedor::addProducto(Producto *producto)
{
  productos.insert(producto);
}

std::string Vendedor::getCodigoRUT()
{
  return codigoRUT;
}

DTUsuario Vendedor::getDataUsuario()
{
  DTUsuario dataUsuario = DTVendedor(getNickname(), getFechaNacimiento(), codigoRUT);
}