#ifndef I_CONTROLADOR_COMENTARIO
#define I_CONTROLADOR_COMENTARIO

#include "../Comentario.hh"

class IControladorComentario
{
public:
  virtual int getNuevoID() = 0;
  virtual void actualizarNuevoID() = 0;
  virtual void comentarProducto(std::string, DTFecha, int) = 0;
  virtual void responderComentario(std::string, DTFecha, int) = 0;
  virtual void eliminarComentario(int) = 0;
};

#endif