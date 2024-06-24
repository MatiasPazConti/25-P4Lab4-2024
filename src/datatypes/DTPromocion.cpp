#include "../../include/datatypes/DTPromocion.hh"

std::string DTPromocion::getNombre()
{
    return nombre;
}

std::string DTPromocion::getDescripcion()
{
    return descripcion;
}

DTFecha *DTPromocion::getFechaVencimiento()
{
    return fechaVencimiento;
}

std::map<int, DTProductoPromo *> DTPromocion::getProductos()
{
    return productos;
}

DTProductoPromo *DTPromocion::getProducto(int id)
{
    return productos[id];
}

DTPromocion::DTPromocion() {}

DTPromocion::DTPromocion(std::string nombre, std::string descripcion, DTFecha *fechaVencimiento, std::map<int, DTProductoPromo *> productos)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaVencimiento = fechaVencimiento;
    this->productos = productos;
}

DTPromocion::~DTPromocion() {}