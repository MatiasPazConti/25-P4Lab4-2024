#include "../../include/controladores/ControladorComentario.hh"
int ControladorComentario::getNuevoID()
{
  return nuevoID;
}
void ControladorComentario::actualizarNuevoID()
{
  nuevoID++;
}
void ControladorComentario::comentarProducto(std::string comentario, DTFecha fecha, int idProducto)
{
}
void ControladorComentario::responderComentario(std::string comentario, DTFecha fecha, int idComentario)
{
}
void ControladorComentario::eliminarComentario(int idComentario)
{
  bool encontrado = false;
  for (std::set<Comentario *>::iterator it = comentarios.begin(); (it != comentarios.end()) && !encontrado; it++)
  {
    if ((*it)->getId() == idComentario)
    {
      Comentario *aBorrar = *it;
      comentarios.erase(aBorrar);
      delete aBorrar;
      encontrado = true;
    }
  }
}
ControladorComentario::~ControladorComentario() {}
ControladorComentario::ControladorComentario()
{
  nuevoID = 1;
}
ControladorComentario *ControladorComentario::instancia = NULL;
ControladorComentario *ControladorComentario::getInstancia()
{
  if (instancia == NULL)
  {
    instancia = new ControladorComentario();
  }
  return instancia;
}