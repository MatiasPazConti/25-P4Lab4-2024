#include "../include/fabrica/Fabrica.hh"
#include "../include/Comentario.hh"

bool Comentario::esRespuesta()
{
  return comentarioRespondido != NULL;
}
int Comentario::getId()
{
  return id;
}
Usuario *Comentario::getRemitente()
{
  return remitente;
}
Producto *Comentario::getProductoComentado()
{
  return productoComentado;
}
Comentario *Comentario::getComentarioRespondido()
{
  return comentarioRespondido;
}
DTComentario *Comentario::getData()
{
  DTFecha *copiaFecha = fecha->copiarFecha();
  DTUsuario *dataRemitente = remitente->getDataUsuario();
  DTComentario *dataComentarioRespondido = NULL;
  DTProducto *dataProductoComentado = NULL;
  std::set<DTComentario *>
      listaRespuestas;
  if (comentarioRespondido != NULL)
  {
    dataComentarioRespondido = comentarioRespondido->getData();
  }
  if (productoComentado != NULL)
  {
    dataProductoComentado = productoComentado->getDataProducto();
  }
  if (!respuestas.empty())
  {
    for (std::set<Comentario *>::iterator it = respuestas.begin(); it != respuestas.end(); it++)
    {
      DTComentario *respuesta = (*it)->getData();
      listaRespuestas.insert(respuesta);
    }
  }
  DTComentario *dataComentario = new DTComentario(id, copiaFecha, comentario, dataRemitente, listaRespuestas, dataComentarioRespondido, dataProductoComentado);
  return dataComentario;
}
void Comentario::agregarRespuesta(Comentario *comentario)
{
  respuestas.insert(comentario);
}
void Comentario::eliminarRespuesta(Comentario *comentario)
{
  respuestas.erase(comentario);
}
Comentario::Comentario(DTFecha *fecha, std::string comentario, Usuario *remitente, Comentario *comentarioRespondido, Producto *productoComentado)
{
  IControladorComentario *controladorComentario = Fabrica::getInterfazComentario();
  this->id = controladorComentario->getNuevoID();
  this->fecha = fecha;
  this->comentario = comentario;
  this->remitente = remitente;
  this->productoComentado = productoComentado;
  this->comentarioRespondido = comentarioRespondido;
  controladorComentario->actualizarNuevoID();
}
Comentario::~Comentario()
{
}