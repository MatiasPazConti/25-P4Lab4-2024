#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

#include "../datatypes/DTFecha.hh"
#include "../datatypes/DTDireccion.hh"
#include "../datatypes/DTCliente.hh"

#include <iostream>
#include <set>

class IControladorUsuario
{
public:
  virtual void resgitrarDatosUsuario(std::string, std::string, DTFecha) = 0;
  virtual void resgitrarDatosCliente(std::string, DTDireccion) = 0;
  virtual void resgitrarDatosVendedor(int) = 0;
  virtual void altaNuevoUsuario() = 0;
  virtual std::set<DTUsuario> listarUsuarios() = 0;
  virtual std::set<DTCliente> listarClientes() = 0;
};

#endif