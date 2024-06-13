#ifndef DTFECHA
#define DTFECHA

class DTFecha
{
private:
  int dia;
  int mes;
  int anio;

public:
  int getDia();
  int getMes();
  int getAnio();
  DTFecha(int, int, int);
  ~DTFecha();
};

#endif