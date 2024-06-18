#include "../../include/controladores/ControladorCompra.hh"


void ControladorCompra::crearCompra(int dia,int mes, int anio){
    Compra compra = Compra();
    compra.setFechaCompra(dia,mes,anio);
    this->compraActual = &compra;
};
void ControladorCompra::asignarCliente(std::string nickname){
    std::set<DTCliente*> clientes = Fabrica::getInterfazUsuario()->listarClientes();
    for (std::set<DTCliente*>::iterator it = clientes.begin(); it != clientes.end(); ++it) {
        if((*it)->GetNickname() == nickname){
            compraActual->setCliente(*it);
            break;
        }        
    }
};
void ControladorCompra::agregarProductoACompra(int id,int cantidad){
    std::set<DTProducto*> productos = Fabrica::getInterfazProducto()->obtenerProductosDisponibles();
    for (std::set<DTProducto*>::iterator it = productos.begin(); it != productos.end(); ++it) {
        if((*it)->getId() == id){
            DTRegistroProducto registro = DTRegistroProducto(id, (*it)->getNombre(), cantidad, (*it)->getPrecio());
            compraActual->setRegistroProducto(registro);
            break;
        }        
    }
};
void ControladorCompra::obtenerDatosCompra(){};
void ControladorCompra::registrarCompraExitosa(){};