#ifndef VENDEDOR
#define VENDEDOR

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTProducto.hh"
#include "./Usuario.hh"
#include "./Producto.hh"
#include <set>

class Vendedor : public Usuario
{
private:
  std::string codigoRUT;
  std::set<Producto *> productos;
  std::set<IObservador *> suscriptores;

public:
  Vendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, std::string codigoRUT);
  ~Vendedor();
  void addProducto(Producto *producto);

  DTUsuario getDataUsuario();
  std::set<DTProducto *> listarProductos();
  DTProducto getProducto(int);
  void removeProducto(Producto *producto);
  void notificarObservadores();
};

#endif