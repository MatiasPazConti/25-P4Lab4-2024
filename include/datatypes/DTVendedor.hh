#ifndef DTVENDEDOR
#define DTVENDEDOR

#include "./DTUsuario.hh"
#include "./DTProducto.hh"

class DTVendedor : public DTUsuario
{
private:
  std::string codigoRUT;

public:
  int getCodigoRUT();
  DTVendedor(std::string, DTFecha, std::string);
  ~DTVendedor();
};

#endif