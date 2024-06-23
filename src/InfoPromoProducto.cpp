#include "../include/InfoPromoProducto.hh"

int InfoPromoProducto::getCantidadMinima() 
{
    return cantidadMinima;
}

void InfoPromoProducto::setCantidadMinima(int nuevaCantidadMinima)
{
    cantidadMinima = nuevaCantidadMinima;
}
int InfoPromoProducto::getId() 
{
    return id;
}

void InfoPromoProducto::setId(int i)
{
    id = i;
}
InfoPromoProducto::InfoPromoProducto(){}

InfoPromoProducto::InfoPromoProducto(int c, int i)
{
    cantidadMinima = c;
    id = i;
}
InfoPromoProducto::~InfoPromoProducto(){}