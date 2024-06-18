#include "../include/Usuario.hh"

Usuario::Usuario(std::string nickname, std::string password, DTFecha fechaNacimiento)
{
  this->nickname = nickname;
  this->password = password;
  this->fechaNacimiento = fechaNacimiento;
}

Usuario::~Usuario()
{
}

std::string Usuario::GetNickname()
{
  return nickname;
}

std::string Usuario::GetPassword()
{
  return password;
}