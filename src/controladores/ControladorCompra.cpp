#include "../../include/controladores/ControladorCompra.hh"
#include "../../include/fabrica/Fabrica.hh"

DTCompra *ControladorCompra::obtenerDatosCompra()
{
	DTCliente *datacliente = compraActual->getCliente()->getDataCliente();

	DTCompra *datacompra = new DTCompra(compraActual->getFechaCompra(), compraActual->getMontoFinal(), datacliente, compraActual->getRegistroProductos());
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
	cliente->añadirCompra(compraActual);
};
void ControladorCompra::agregarProductoACompra(int id, int cantidad)
{
	DTProducto *producto = Fabrica::getInterfazProducto()->obtenerProductoDisponible(id);
	DTRegistroProducto *registro = new DTRegistroProducto(id, producto->getNombre(), cantidad, producto->getPrecio(), producto->getPromocion());
	compraActual->addRegistroProducto(registro);
	compraActual->setMontoFinal(compraActual->getMontoFinal() + producto->getPrecio() * cantidad);
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
		if ((*it)->getInfoPromo() != NULL)
		{
			std::map<int, DTProductoPromo *> productosPromo = (*it)->getInfoPromo()->getProductos();
			std::set<DTRegistroProducto *> auxiliar;
			for (std::set<DTRegistroProducto *>::iterator it = productos.begin(); it != productos.end(); ++it)
			{
				if (productosPromo[(*it)->getId()]->getCantidadMinima() <= (*it)->getCantidad())
				{
					auxiliar.insert(*it);
				}
			}
			if (auxiliar.size() == productosPromo.size())
			{
				std::cout << "Descuento aplicado" << std::endl;
				int monto1 = compraActual->getMontoFinal();
				int monto2 = (*it)->getInfoPromo()->getPorcentajeDescuento();
				int montoF = monto1 - (monto1 * monto2 / 100);
				compraActual->setMontoFinal(montoF);
				break;
			}
			else
			{
				std::cout << "No hay descuentos disponibles" << std::endl;
			};
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
