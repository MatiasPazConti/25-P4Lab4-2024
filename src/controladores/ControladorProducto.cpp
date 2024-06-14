
#include "../../include/controladores/ControladorProducto.hh"

int ControladorProducto::getId(){
  return id;
}
void ControladorProducto::setId(int i){
  id = i;
}
std::string ControladorProducto::getNombre(){
  return nombre;
}
void ControladorProducto::setNombre(std::string n){
  nombre = n;
}
std::string ControladorProducto::getDescripcion(){
  return descripcion;
}
void ControladorProducto::setDescrpcion(std::string des){
  descripcion = des;
}
float ControladorProducto::getPrecio(){
  return precio;
}
void ControladorProducto::setPrecio(float pr){
  precio = pr;
}
int ControladorProducto::getCantidadEnStock(){
  return cantidadEnStock;
}
void ControladorProducto::setCantidadEnStock(int cant){
  cantidadEnStock = cant;
}
TipoProducto ControladorProducto::getTipoProducto(){
  return tipo;
}
void ControladorProducto::setTipoProducto(TipoProducto t){
  tipo = t;
}
ControladorProducto::ControladorProducto(){}
void ControladorProducto::registrarDatosProductos(std::string n,int p,int cant,std::string des,TipoProducto t,int i){
  id = i;
  nombre = n;
  descripcion = des;
  precio = p;
  cantidadEnStock = cant;
  tipo = t;
}
ControladorProducto::~ControladorProducto(){};

void ControladorProducto::altaNuevoProducto(){
    Producto prod = Producto(this->id,this->nombre,this->descripcion,this->precio,this->cantidadEnStock,this->tipo);
    this->productos.insert(prod);
};

void ControladorProducto::listarProductosDisponibles(){
    std::cout << "Elementos del set: ";

    for (std::set<Producto>::iterator it = productos.begin(); it != productos.end(); ++it) {
        // Falta Imprimir cada elemento.
    }
    std::cout << std::endl;
};

