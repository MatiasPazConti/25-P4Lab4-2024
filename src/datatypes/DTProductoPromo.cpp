#include "../../include/datatypes/DTProductoPromo.hh"

int DTProductoPromo::getId()
{
    return id;
}
std::string DTProductoPromo::getNombre()
{
    return nombre;
}
int DTProductoPromo::getCantidadMinima()
{
    return cantidadMinima;
}
float DTProductoPromo::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}
DTProductoPromo *DTProductoPromo::copiarInfoProductoPromo()
{
    DTProductoPromo *copiaInfoProductoPromo = new DTProductoPromo(id, nombre, cantidadMinima, porcentajeDescuento);
    return copiaInfoProductoPromo;
}
DTProductoPromo::DTProductoPromo(int i, std::string n, int c, float d)
{
    id = i;
    nombre = n;
    cantidadMinima = c;
    porcentajeDescuento = d;
}
DTProductoPromo::~DTProductoPromo() {}