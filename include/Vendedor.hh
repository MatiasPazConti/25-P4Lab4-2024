#ifndef VENDEDOR
#define VENDEDOR

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTProducto.hh"
#include "./datatypes/DTVendedor.hh"
#include "./Usuario.hh"
#include "./Producto.hh"
#include <set>

class Vendedor : public Usuario
{
private:
  int codigoRUT;
  std::set<Producto *> productos;
  std::set<IObservador *> suscriptores;

public:
  int getCodigoRUT();
  DTUsuario *getDataUsuario();
  DTProducto *getDataProducto(int);
  std::set<DTProducto *> listarProductos();
  void añadirProducto(Producto *producto);
  void removerProducto(Producto *producto);
  // void notificarObservadores();
  Vendedor(std::string nickname, std::string password, DTFecha fechaNacimiento, int codigoRUT);
  ~Vendedor();
};

#endif