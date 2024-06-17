#include "../../include/controladores/ControladorCompra.hh"

void ControladorCompra::crearCompra(int dia,int mes, int anio){
    Compra compra = Compra();
    compra.setFechaCompra(dia,mes,anio);
    this->compraActual = &compra;
};
void ControladorCompra::asignarCliente(std::string nickname){
    //NECESITAMOS CONTROLADOR USUARIO
};
void ControladorCompra::agregarProductoACompra(int,int){
    //NECESITAMOS CONTROLADOR PRODUCTO 
};
void ControladorCompra::obtenerDatosCompra(){};
void ControladorCompra::registrarCompraExitosa(){};