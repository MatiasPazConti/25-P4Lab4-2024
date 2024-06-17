#ifndef DTVENDEDOR
#define DTVENDEDOR

#include "./DTUsuario.hh"

class DTVendedor
{
private:
  int codigoRUT;

public:
  int getCodigoRUT();
  DTVendedor(std::string, DTFecha, int);
  ~DTVendedor();
};

#endif