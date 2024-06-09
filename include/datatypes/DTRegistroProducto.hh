#ifndef DTREGISTRO_PRODUCTO
#define DTREGISTRO_PRODUCTO
#include <iostream>

class DTRegistroProducto
{
private:
  int id;
  std::string nombre;
  int cantidad;
  float precio;
  bool enviadoCorrectamente;

public:
  int getId();
  std::string getNombre();
  int getCantidad();
  float getPrecio();
  bool getEnviadoCorrectamente();
  DTRegistroProducto();
  DTRegistroProducto(int,std::string,int,float,bool);
  ~DTRegistroProducto();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTRegistroProducto &obj); // cout DTRegistroProducto

#endif