#ifndef VENDEDOR
#define VENDEDOR

#include "../interfaces/IObservador.hh"
#include "../datatypes/DTProducto.hh"
#include "./Usuario.hh"
#include "./Producto.hh"

class Vendedor : public Usuario
{
private:
  int codigoRUT;
  std::set<Producto *> productos;
  std::set<IObservador *> suscriptores;

public:
  DTUsuario getDataUsuario();
  // std::set<DTProducto *> listarProductos();
  void notificarObservadores();
  Vendedor(std::string, std::string, DTFecha, int);
  ~Vendedor();
};

#endif