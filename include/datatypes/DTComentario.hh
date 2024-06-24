#ifndef DTCOMENTARIO
#define DTCOMENTARIO
#include <iostream>
#include "DTFecha.hh"

class DTComentario
{
private:
  int id;
  DTFecha fecha;
  std::string texto;

public:
  int getId();
  DTFecha getFecha();
  std::string getTexto();
  DTComentario();
  DTComentario(int, DTFecha, std::string);
  ~DTComentario();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTComentario &obj); // cout DTComentario

#endif