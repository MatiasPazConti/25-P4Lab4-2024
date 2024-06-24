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

DTFecha Usuario::getFechaNacimiento()
{
  return fechaNacimiento;
}

std::string Usuario::getNickname()
{
  return nickname;
}

std::string Usuario::getPassword()
{
  return password;
}