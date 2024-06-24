#ifndef COMENTARIO
#define COMENTARIO
#include "./Producto.hh"
#include "./Usuario.hh"
#include "./datatypes/DTFecha.hh"
#include "./datatypes/DTComentario.hh"

#include <set>

class Comentario
{
private:
  int id;
  DTFecha *fecha;
  std::string comentario;
  Usuario *remitente;
  std::set<Comentario *> respuestas;
  Comentario *comentarioRespondido;
  Producto *productoComentado;

public:
  bool esRespuesta();
  int getId();
  Usuario *getRemitente();
  Producto *getProductoComentado();
  Comentario *getComentarioRespondido();
  DTComentario *getData();
  void agregarRespuesta(Comentario *);
  void eliminarRespuesta(Comentario *);
  Comentario(DTFecha *, std::string, Usuario *, Comentario *, Producto *);
  ~Comentario();
};

#endif