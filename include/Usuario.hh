#ifndef USUARIO
#define USUARIO

#include "./datatypes/DTFecha.hh"
#include "./datatypes/DTUsuario.hh"

class Usuario
{
private:
  std::string nickname;
  std::string password;
  DTFecha *fechaNacimiento;

public:
  std::string getNickname();
  std::string getPassword();
  DTFecha *getFechaNacimiento();
  virtual DTUsuario *getDataUsuario() = 0;
  Usuario(std::string nickname, std::string password, DTFecha *fechaNacimiento);
  virtual ~Usuario();
};

#endif