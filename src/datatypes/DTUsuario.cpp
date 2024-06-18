#include "../../include/datatypes/DTUsuario.hh"

DTUsuario::DTUsuario(std::string nickname, std::string password, DTFecha fechaNacimiento)
{
  this->nickname = nickname;
  this->password = password;
  this->fechaNacimiento = fechaNacimiento;
}
DTUsuario::~DTUsuario()
{
}

std::string DTUsuario::GetNickname()
{
  return nickname;
}
