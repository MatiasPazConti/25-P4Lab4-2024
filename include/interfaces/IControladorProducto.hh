#ifndef I_CONTROLADOR_PRODUCTO
#define I_CONTROLADOR_PRODUCTO

class IControladorProducto
{
public:
  virtual void registrarDatosProductos(std::string,int,int,std::string,TipoProducto,int);
  virtual void altaNuevoProducto();
  virtual void listarProductosDisponibles(); // Usa DTProducto o Producto???
};

#endif