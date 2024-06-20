#ifndef VENDEDOR
#define VENDEDOR

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTVendedor.hh"
#include "./datatypes/DTProducto.hh"
#include "./Usuario.hh"
#include "./Cliente.hh"
#include "./Producto.hh"

#include <set>

class Cliente;

class Vendedor : public Usuario
{
private:
  int codigoRUT;
  std::set<Producto *> productos;
  std::set<IObservador *> suscriptores;

public:
  int getCodigoRUT();
  DTVendedor *getDataVendedor();
  DTProducto *getDataProducto(int);
  void añadirProducto(Producto *);
  void añadirSuscriptor(Cliente *);
  void removerProducto(Producto *);
  void removerSuscriptor(Cliente *);
  // void notificarObservadores();
  std::set<DTProducto *> listarProductos();
  Vendedor(std::string, std::string, DTFecha, int);
  ~Vendedor();
};

#endif