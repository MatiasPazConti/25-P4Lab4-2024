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
	DTRegistroProducto registro = DTRegistroProducto(id, producto->getNombre(), cantidad, producto->getPrecio());
	compraActual->setRegistroProducto(registro);
	compraActual->setMontoFinal(compraActual->getMontoFinal() + producto->getPrecio() * cantidad);
};

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