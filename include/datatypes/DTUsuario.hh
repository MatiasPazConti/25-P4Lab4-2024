#ifndef DTUSUARIO
#define DTUSUARIO

#include "./DTFecha.hh"
#include <set>

class DTUsuario
{
private:
  std::string nickname;
  DTFecha *fechaNacimiento;

public:
  std::string getNickname();
  DTFecha *getFechaNacimiento();
  DTUsuario(std::string nickname, DTFecha *fechaNacimiento);
  ~DTUsuario();
};

#endif