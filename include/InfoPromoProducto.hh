#ifndef INFO_PROMO_PRODUCTO
#define INFO_PROMO_PRODUCTO

#include<iostream>

class InfoPromoProducto
{
private:
    int cantidadMinima;
    float porcentajeDescuento;
public:
    int getCantidadMinima();
    float getPorcentajeDescuento();
    void setCantidadMinima(int);
    void setPorcentajeDescuento(float);
    InfoPromoProducto();
    InfoPromoProducto(int, float);
    ~InfoPromoProducto();
};




#endif