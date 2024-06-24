#include "../include/Comentario.hh"

bool Comentario::esRespuesta()
{
  return comentarioRespondido != NULL;
}
int Comentario::getId()
{
  return id;
}
std::string Comentario::getNickRemitente()
{
  return nickRemitente;
}
DTProducto *Comentario::getInfoProductoComentado()
{
  return infoProductoComentado;
}
Comentario *Comentario::getComentarioRespondido()
{
  return comentarioRespondido;
}
DTComentario *Comentario::getDataComentario()
{
  /*
  DTFecha *copiaFecha = fecha->copiarFecha();
  DTComentario *dataComentarioRespondido = NULL;
  DTProducto *dataProductoComentado = NULL;
  std::set<DTComentario *>
      listaRespuestas;
  if (comentarioRespondido != NULL)
  {
    dataComentarioRespondido = comentarioRespondido->getDataComentario();
  }
  if (infoProductoComentado != NULL)
  {
    dataProductoComentado = infoProductoComentado->copiarInfoProducto();
  }
  if (!respuestas.empty())
  {
    for (std::set<Comentario *>::iterator it = respuestas.begin(); it != respuestas.end(); it++)
    {
      DTComentario *respuesta = (*it)->getDataComentario();
      listaRespuestas.insert(respuesta);
    }
  }
  DTComentario *dataComentario = new DTComentario(id, copiaFecha, comentario, nickRemitente, listaRespuestas, dataComentarioRespondido, dataProductoComentado);
  return dataComentario;
  */
  return NULL;
}
void Comentario::agregarRespuesta(Comentario *comentario)
{
  respuestas.insert(comentario);
}
void Comentario::eliminarRespuesta(Comentario *comentario)
{
  respuestas.erase(comentario);
}
Comentario::Comentario(int id, DTFecha *fecha, std::string comentario, std::string nickRemitente, Comentario *comentarioRespondido, DTProducto *infoProductoComentado)
{
  this->id = id;
  this->fecha = fecha;
  this->comentario = comentario;
  this->nickRemitente = nickRemitente;
  this->infoProductoComentado = infoProductoComentado;
  this->comentarioRespondido = comentarioRespondido;
}
Comentario::~Comentario()
{
}