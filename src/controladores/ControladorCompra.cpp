#include "../../include/controladores/ControladorCompra.hh"
#include "../../include/fabrica/Fabrica.hh"

void ControladorCompra::crearCompra(std::string nickname, int dia, int mes, int anio)
{
    DTFecha *fechaCompra = new DTFecha(dia, mes, anio);
    Cliente *cliente = Fabrica::getInterfazUsuario()->getCliente(nickname);
	float precioInicial= 0;
    Compra *nuevaCompra = new Compra(fechaCompra, precioInicial, cliente);
    this->compraActual = nuevaCompra;
};

void ControladorCompra::asignarCliente(std::string)
{
}

void ControladorCompra::agregarProductoACompra(int id, int cantidad)
{
	Producto *producto = Fabrica::getInterfazProducto()->getProducto(id);
	DTRegistroProducto* registro = new DTRegistroProducto(id, producto->getNombre(), cantidad, producto->getPrecio(), producto->getPromocion());
	compraActual->setRegistroProducto(registro);
	compraActual->setMontoFinal(compraActual->getMontoFinal() + producto->getPrecio() * cantidad);
};

void ControladorCompra::calcularDescuentos(){
	std::cout <<"Error1"<< std::endl;
	std::set<DTRegistroProducto*> productos = compraActual->getRegistroProductos();
	for (std::set<DTRegistroProducto*>::iterator it = productos.begin(); it != productos.end(); ++it){
		if ((*it)->getPromo() != NULL){
			std::cout <<"Error2"<< std::endl;
			std::map<int, InfoPromoProducto> productosPromo = (*it)->getPromo()->getInfoProductos();
			std::set<DTRegistroProducto*> auxiliar;
			for (std::set<DTRegistroProducto*>::iterator it = productos.begin(); it != productos.end(); ++it){
				if(productosPromo[(*it)->getId()].getCantidadMinima() <= (*it)->getCantidad()){
					auxiliar.insert(*it);
				}
			}
		std::cout <<"Error3"<< std::endl;
		if(auxiliar.size() == productosPromo.size()){
			  std::cout <<"Descuento aplicado"<< std::endl;
			compraActual->setMontoFinal(compraActual->getMontoFinal() - compraActual->getMontoFinal()*(*it)->getPromo()->getPorcentajeDescuento());
			break;
		}
		  std::cout <<"No hay descuentos disponibles"<< std::endl;
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

bool ControladorCompra::estaEnCompra(int id){
	if(compraActual->getRegistroProducto(id) == NULL){
		return false;
	}
	return true;
};