#ifndef CONTROLADOR_COMENTARIO
#define CONTROLADOR_COMENTARIO

#include "../interfaces/IControladorComentario.hh"
#include <set>

class ControladorComentario : public IControladorComentario
{
private:
  std::set<Comentario *> comentarios;
  int nuevoID;
  static ControladorComentario *instancia;
  ControladorComentario();

public:
  int getNuevoID();
  void actualizarNuevoID();
  void comentarProducto(std::string, DTFecha, int);
  void responderComentario(std::string, DTFecha, int);
  void eliminarComentario(int);
  static ControladorComentario *getInstancia();
  ~ControladorComentario();
};

#endif