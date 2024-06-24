#ifndef VENDEDOR
#define VENDEDOR

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTVendedor.hh"
#include "./datatypes/DTProducto.hh"
#include "./Usuario.hh"
#include "./Cliente.hh"
#include "./Producto.hh"

#include <set>

class IObservador;
class Cliente;
class Producto;
class Promocion;

class Vendedor : public Usuario
{
private:
  std::string codigoRUT;
  std::set<Producto *> productos;
  std::set<Promocion *> promociones;
  std::set<IObservador *> suscriptores;

public:
  std::string getCodigoRUT();
  std::set<Promocion *> getPromociones();
  DTVendedor *getDataVendedor();
  DTProducto *getDataProducto(int);
  bool tieneSuscriptores();
  void añadirPromocion(Promocion *);
  void añadirProducto(Producto *);
  void añadirSuscriptor(Cliente *);
  void removerPromocion(Promocion *);
  void removerProducto(Producto *);
  void removerSuscriptor(Cliente *);
  void notificarObservadores(DTPromocion *);
  std::set<DTProducto *> listarProductos();
  Vendedor(std::string, std::string, DTFecha *, std::string);
  ~Vendedor();
};

#endif