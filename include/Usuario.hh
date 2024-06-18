#ifndef USUARIO
#define USUARIO

#include "./datatypes/DTFecha.hh"
#include "./datatypes/DTUsuario.hh"

class Usuario
{
private:
  std::string nickname;
  std::string password;
  DTFecha fechaNacimiento;

public:
  // virtual DTUsuario getDataUsuario() = 0;
  Usuario(std::string nickname, std::string password, DTFecha fechaNacimiento);
  ~Usuario();
  std::string GetNickname();
  std::string GetPassword();
};

#endif