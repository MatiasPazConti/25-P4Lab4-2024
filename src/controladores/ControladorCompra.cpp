#include "../../include/controladores/ControladorCompra.hh"


void ControladorCompra::crearCompra(std::string nickname,int dia,int mes, int anio){
    Compra compra = Compra();
    compra.setFechaCompra(dia,mes,anio);
    Cliente* cliente = Fabrica::getInstance()->getInterfazUsuario()->obtenerCliente(nickname);
    compra.setCliente(cliente);
    this->compraActual = &compra;
};
void ControladorCompra::agregarProductoACompra(int id,int cantidad){
    Producto* producto = Fabrica::getInstance()->getInterfazProducto()->obtenerProductoDisponible(id); 
    DTRegistroProducto registro = DTRegistroProducto(id, producto->getNombre(), cantidad, producto->getPrecio());
    compraActual->setRegistroProducto(registro);
    compraActual->setMontoFinal(compraActual->getMontoFinal() + producto->getPrecio()*cantidad);                
};
void ControladorCompra::obtenerDatosCompra(){};
void ControladorCompra::registrarCompraExitosa(){};