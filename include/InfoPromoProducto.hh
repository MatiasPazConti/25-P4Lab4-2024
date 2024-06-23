#ifndef INFO_PROMO_PRODUCTO
#define INFO_PROMO_PRODUCTO

#include<iostream>

class InfoPromoProducto
{
private:
    int cantidadMinima;
public:
    int getCantidadMinima();
    void setCantidadMinima(int);
    InfoPromoProducto();
    InfoPromoProducto(int);
    ~InfoPromoProducto();
};




#endif