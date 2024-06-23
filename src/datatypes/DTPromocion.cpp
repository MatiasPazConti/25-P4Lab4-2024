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

float DTPromocion::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}

std::map<int, DTProductoPromo> DTPromocion::getProductos()
{
    return productos;
}

DTProductoPromo DTPromocion::getProducto(int id)
{
    return productos[id];
}

DTPromocion::DTPromocion() {}

DTPromocion::DTPromocion(std::string n, std::string d, DTFecha f, float pd, std::map<int, DTProductoPromo> p)
{
    nombre = n;
    descripcion = d;
    fechaVencimiento = f;
    porcentajeDescuento = pd;
    productos = p;
}

DTPromocion::~DTPromocion() {}