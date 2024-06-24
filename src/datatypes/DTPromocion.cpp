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
float DTPromocion::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}
DTVendedor *DTPromocion::getInfoVendedor()
{
    return vendedor;
}
std::map<int, DTProductoPromo *> DTPromocion::getProductos()
{
    return productos;
}
DTProductoPromo *DTPromocion::getProducto(int id)
{
    return productos[id];
}
DTPromocion *DTPromocion::copiarPromocion()
{
    DTFecha *copiaFecha = fechaVencimiento->copiarFecha();
    DTVendedor *copiaVendedor = vendedor->copiarInfoVendedor();
    std::map<int, DTProductoPromo *> copiaInfoProductos;
    for (std::map<int, DTProductoPromo *>::iterator it = productos.begin(); it != productos.end(); it++)
    {
        DTProductoPromo *copiaInfoProductoPromo = (it->second)->copiarInfoProductoPromo();
        copiaInfoProductos.insert(std::pair<int, DTProductoPromo *>(it->first, copiaInfoProductoPromo));
    }
    DTPromocion *copiaInfoPromocion = new DTPromocion(nombre, descripcion, copiaFecha, porcentajeDescuento, copiaVendedor, copiaInfoProductos);
    return copiaInfoPromocion;
}
DTPromocion::DTPromocion(std::string nombre, std::string descripcion, DTFecha *fechaVencimiento, float porcentajeDescuento, DTVendedor *vendedor, std::map<int, DTProductoPromo *> productos)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaVencimiento = fechaVencimiento;
    this->porcentajeDescuento = porcentajeDescuento;
    this->vendedor = vendedor;
    this->productos = productos;
}
DTPromocion::~DTPromocion()
{
    delete fechaVencimiento;
    delete vendedor;
    while (!productos.empty())
    {
        std::map<int, DTProductoPromo *>::iterator inicio = productos.begin();
        DTProductoPromo *aBorrar = inicio->second;
        productos.erase(inicio);
        delete aBorrar;
    }
}