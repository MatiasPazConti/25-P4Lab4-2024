#ifndef DTREGISTRO_PRODUCTO
#define DTREGISTRO_PRODUCTO

#include <iostream>
#include "../Promocion.hh"

class DTRegistroProducto
{
private:
  int id;
  std::string nombre;
  Promocion* promo;
  int cantidad;
  float precio;
  bool enviadoCorrectamente;

public:
  int getId();
  std::string getNombre();
  int getCantidad();
  float getPrecio();
  Promocion* getPromo();
  DTRegistroProducto();
  DTRegistroProducto(int, std::string, int, float, Promocion*); // id,nombre,cantidad,precio,enviadocorrectamente
  ~DTRegistroProducto();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTRegistroProducto &obj); // cout DTRegistroProducto

#endif