#ifndef DTUSUARIO
#define DTUSUARIO

#include "./DTFecha.hh"

class DTUsuario
{
private:
  std::string nickname;
  DTFecha fechaNacimiento;

public:
  DTUsuario(std::string, DTFecha);
  ~DTUsuario();
};

#endif