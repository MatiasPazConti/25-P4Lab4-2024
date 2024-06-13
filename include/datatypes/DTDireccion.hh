#ifndef DTDIRECCION
#define DTDIRECCION

class DTDireccion
{
private:
  std::string nombreCalle;
  int nroPuerta;

public:
  std::string getNombreCalle();
  int getNroPuerta();
  DTDireccion(std::string, int);
  ~DTDireccion();
};

#endif