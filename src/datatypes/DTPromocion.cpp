#include "../../include/datatypes/DTPromocion.hh"

std::string DTPromocion::getNombre()
{
    return nombre;
}

std::string DTPromocion::getDescripcion()
{
    return descripcion;
}

DTFecha DTPromocion::getFechaVencimiento()
{
    return fechaVencimiento;
}

std::set<DTProductoPromo> DTPromocion::getProductos()
{
    return productos;
}

DTPromocion::DTPromocion(){}

DTPromocion::DTPromocion(std::string n, std::string d, DTFecha f, std::set<DTProductoPromo> p)
{
    nombre = n;
    descripcion = d;
    fechaVencimiento = f;
    productos = p;
}

DTPromocion::~DTPromocion(){}