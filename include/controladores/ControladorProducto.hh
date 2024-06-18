#ifndef CONTROLADOR_PRODUCTO
#define CONTROLADOR_PRODUCTO

#include "../interfaces/IControladorProducto.hh"
#include <iostream>
#include <set>
#include "../include/TipoProducto.hh"
#include "../include/Producto.hh"
#include "../include/datatypes/DTProducto.hh"


class ControladorProducto : public IControladorProducto
{
private:
  int id;
  std::string nombre;
  std::string descripcion;
  float precio;
  int cantidadEnStock;
  TipoProducto tipo;
  std::set<DTProducto*> productos;
public:
  int getId();
  void setId(int);
  std::string getNombre();
  void setNombre(std::string);
  std::string getDescripcion();
  void setDescrpcion(std::string);
  float getPrecio();
  void setPrecio(float);
  int getCantidadEnStock();
  void setCantidadEnStock(int);
  TipoProducto getTipoProducto();
  void setTipoProducto(TipoProducto);

  void registrarDatosProductos(std::string,int,int,std::string,TipoProducto,int);
  void altaNuevoProducto();
  void listarProductosDisponibles(); // Usa DTProducto o Producto???
  std::set<DTProducto*> obtenerProductosDisponibles();
  ControladorProducto();
  ControladorProducto(int, std::string, std::string,float,int,TipoProducto);
  ~ControladorProducto();

};


#endif