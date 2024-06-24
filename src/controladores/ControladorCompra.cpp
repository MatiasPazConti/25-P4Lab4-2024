#include "../../include/controladores/ControladorCompra.hh"
#include "../../include/fabrica/Fabrica.hh"

DTCompra *ControladorCompra::obtenerDatosCompra()
{
	DTCliente *datacliente = compraActual->getCliente()->getDataCliente();

	DTCompra *datacompra = new DTCompra(compraActual->getFechaCompra(), compraActual->getMontoFinal(), compraActual->getRegistroProductos(), datacliente);
	return datacompra;
}
bool ControladorCompra::estaEnCompra(int id)
{
	if (compraActual->getRegistroProducto(id) == NULL)
	{
		return false;
	}
	return true;
};
void ControladorCompra::crearCompra(std::string nickname, int dia, int mes, int anio)
{
	DTFecha *fechaCompra = new DTFecha(dia, mes, anio);
	float precioInicial = 0;
	Cliente *cliente = Fabrica::getInterfazUsuario()->getCliente(nickname);
	Compra *nuevaCompra = new Compra(fechaCompra, precioInicial, cliente);
	this->compraActual = nuevaCompra;
};
void ControladorCompra::agregarProductoACompra(int id, int cantidad)
{
	DTProducto *producto = Fabrica::getInterfazProducto()->obtenerProductoDisponible(id);
	DTRegistroProducto *registro = new DTRegistroProducto(id, producto->getNombre(), cantidad, producto->getPrecio(), producto->getPromocion());
	compraActual->addRegistroProducto(registro);
	std::cout << "Error4" << std::endl;
	compraActual->setMontoFinal(compraActual->getMontoFinal() + producto->getPrecio() * cantidad);
	std::cout << "Error5" << std::endl;
};
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
void ControladorCompra::calcularDescuentos()
{
	std::set<DTRegistroProducto *> productos = compraActual->getRegistroProductos();
	for (std::set<DTRegistroProducto *>::iterator it = productos.begin(); it != productos.end(); ++it)
	{
		if ((*it)->getPromo() != NULL)
		{
			std::map<int, InfoPromoProducto> productosPromo = (*it)->getPromo()->getInfoProductos();
			std::set<DTRegistroProducto *> auxiliar;
			for (std::set<DTRegistroProducto *>::iterator it = productos.begin(); it != productos.end(); ++it)
			{
				if (productosPromo[(*it)->getId()].getCantidadMinima() <= (*it)->getCantidad())
				{
					auxiliar.insert(*it);
				}
			}
			if (auxiliar.size() == productosPromo.size())
			{
				compraActual->setMontoFinal(compraActual->getMontoFinal() - compraActual->getMontoFinal() * (*it)->getPromo()->getPorcentajeDescuento());
				break;
			}
		}
	};
}
ControladorCompra::ControladorCompra() {}
ControladorCompra::~ControladorCompra()
{
	delete compraActual;
	while (!comprasExitosas.empty())
	{
		std::set<Compra *>::iterator inicio = comprasExitosas.begin();
		Compra *aBorrar = *inicio;
		comprasExitosas.erase(inicio);
		delete aBorrar;
	}
}
ControladorCompra *ControladorCompra::instancia = NULL;
ControladorCompra *ControladorCompra::getInstancia()
{
	if (instancia == NULL)
	{
		instancia = new ControladorCompra();
	}
	return instancia;
}
