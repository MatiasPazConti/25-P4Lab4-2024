#ifndef DTPROMOCION
#define DTPROMOCION

#include "./DTFecha.hh"
#include "./DTProductoPromo.hh"

#include <iostream>
#include <map>
#include <set>

class DTPromocion
{
private:
    std::string nombre;
    std::string descripcion;
    DTFecha *fechaVencimiento;
    std::map<int, DTProductoPromo *> productos;

public:
    std::string getNombre();
    std::string getDescripcion();
    DTFecha *getFechaVencimiento();
    std::map<int, DTProductoPromo *> getProductos();
    DTProductoPromo *getProducto(int id);
    DTPromocion();
    DTPromocion(std::string, std::string, DTFecha *, std::map<int, DTProductoPromo *>);
    ~DTPromocion();
};

#endif