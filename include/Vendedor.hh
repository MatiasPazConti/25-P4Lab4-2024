#ifndef VENDEDOR
#define VENDEDOR

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTVendedor.hh"
#include "./datatypes/DTProducto.hh"
#include "./Usuario.hh"
#include "./Cliente.hh"
#include "./Producto.hh"

#include <set>

class Producto;
class Promocion;
class Cliente;

class Vendedor : public Usuario
{
private:
  std::string codigoRUT;
  std::set<Producto *> productos;
  std::set<IObservador *> suscriptores;

public:
  std::string getCodigoRUT();
  DTVendedor *getDataVendedor();
  DTProducto *getDataProducto(int);
  bool tieneSuscriptores();
  void añadirProducto(Producto *);
  void añadirSuscriptor(Cliente *);
  void removerProducto(Producto *);
  void removerSuscriptor(Cliente *);
  void notificarObservadores(DTPromocion *);
  std::set<DTProducto *> listarProductos();
  Vendedor(std::string, std::string, DTFecha *, std::string);
  ~Vendedor();
};

#endif