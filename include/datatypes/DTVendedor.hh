#ifndef DTVENDEDOR
#define DTVENDEDOR

#include "./DTUsuario.hh"
#include "./DTProducto.hh"

class DTVendedor : public DTUsuario
{
private:
  std::string codigoRUT;

public:
  std::string getCodigoRUT();
  DTVendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT);
  ~DTVendedor();
};

#endif