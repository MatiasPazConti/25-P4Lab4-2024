#include "../../include/controladores/ControladorCompra.hh"
#include "../../include/fabrica/Fabrica.hh"

void ControladorCompra::crearCompra(std::string nickname, int dia, int mes, int anio)
{
	Compra compra = Compra();
	compra.setFechaCompra(dia, mes, anio);
	Cliente *cliente = Fabrica::getInterfazUsuario()->getCliente(nickname);
	compra.setCliente(cliente);
	this->compraActual = &compra;
};

void ControladorCompra::asignarCliente(std::string)
{
}

void ControladorCompra::agregarProductoACompra(int id, int cantidad)
{
	DTProducto *producto = Fabrica::getInterfazProducto()->obtenerProductoDisponible(id);
	DTRegistroProducto registro = DTRegistroProducto(id, producto->getNombre(), cantidad, producto->getPrecio(), producto->getPromocion());
	compraActual->setRegistroProducto(registro);
	compraActual->setMontoFinal(compraActual->getMontoFinal() + producto->getPrecio() * cantidad);
};

void ControladorCompra::calcularDescuentos(){
	std::set<DTRegistroProducto*> productos = compraActual->getRegistroProductos();
	for (std::set<DTRegistroProducto*>::iterator it = productos.begin(); it != productos.end(); ++it){
		if ((*it)->getPromo() != NULL){
			std::map<int, InfoPromoProducto> productosPromo = (*it)->getPromo()->getInfoProductos();
			std::set<DTRegistroProducto*> auxiliar;
			for (std::set<DTRegistroProducto*>::iterator it = productos.begin(); it != productos.end(); ++it){
				if(productosPromo[(*it)->getId()].getCantidadMinima() <= (*it)->getCantidad()){
					auxiliar.insert(*it);
				}
			}
		if(auxiliar.size() == productosPromo.size()){
			compraActual->setMontoFinal(compraActual->getMontoFinal() - compraActual->getMontoFinal()*(*it)->getPromo()->getPorcentajeDescuento());
			break;
		}
		}
    };

}
DTCompra *ControladorCompra::obtenerDatosCompra()
{
	DTCliente *datacliente = compraActual->getCliente()->getDataCliente();
	DTCompra *datacompra = new DTCompra(compraActual->getFechaCompra(), compraActual->getMontoFinal(), compraActual->getRegistroProductos(), datacliente);
	return datacompra;
}

void ControladorCompra::registrarCompraExitosa(bool b)
{
	if (b)
	{
		comprasExitosas.insert(compraActual);
	}
	else
	{
		compraActual->~Compra();
	}
}
ControladorCompra::ControladorCompra() {}
ControladorCompra::~ControladorCompra() {}
ControladorCompra *ControladorCompra::instancia = NULL;
ControladorCompra *ControladorCompra::getInstancia()
{
	if (instancia == NULL)
	{
		instancia = new ControladorCompra();
	}
	return instancia;
}