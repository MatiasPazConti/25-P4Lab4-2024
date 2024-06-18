#ifndef DTUSUARIO
#define DTUSUARIO

#include "./DTFecha.hh"

class DTUsuario
{
private:
  std::string nickname;
  std::string password;
  DTFecha fechaNacimiento;

public:
  DTUsuario(std::string nickname, std::string password, DTFecha fechaNacimiento);
  ~DTUsuario();
  std::string GetNickname();
};

#endif