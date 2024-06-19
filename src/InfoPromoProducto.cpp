#include "../include/InfoPromoProducto.hh"

int InfoPromoProducto::getCantidadMinima() 
{
    return cantidadMinima;
}

float InfoPromoProducto::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}

void InfoPromoProducto::setCantidadMinima(int nuevaCantidadMinima)
{
    cantidadMinima = nuevaCantidadMinima;
}

void InfoPromoProducto::setPorcentajeDescuento(float nuevoPorcentajeDescuento)
{
    porcentajeDescuento = nuevoPorcentajeDescuento;
}

InfoPromoProducto::InfoPromoProducto(){}

InfoPromoProducto::InfoPromoProducto(int c, float d)
{
    cantidadMinima = c;
    porcentajeDescuento = d;
}
InfoPromoProducto::~InfoPromoProducto(){}