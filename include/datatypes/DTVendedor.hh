#ifndef DTVENDEDOR
#define DTVENDEDOR

#include "./DTUsuario.hh"
#include "./DTProducto.hh"

class DTVendedor : public DTUsuario
{
private:
  int codigoRUT;

public:
  int getCodigoRUT();
  DTVendedor(std::string, DTFecha, int);
  ~DTVendedor();
};

#endif