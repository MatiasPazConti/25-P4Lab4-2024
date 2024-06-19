#ifndef DTPROMOCION
#define DTPROMOCION

#include "./DTFecha.hh"
#include "./DTProductoPromo.hh"

#include <iostream>
#include <set>

class DTPromocion 
{
private:
    std::string nombre;
    std::string descripcion;
    DTFecha fechaVencimiento;
    std::set<DTProductoPromo> productos; //*??

public:
    std::string getNombre();
    std::string getDescripcion();
    DTFecha getFechaVencimiento();
    std::set<DTProductoPromo> getProductos();// cambiar a getSetProductos y agregar un getProducto(id)?
    DTPromocion();
    DTPromocion(std::string, std::string, DTFecha, std::set<DTProductoPromo>);
    ~DTPromocion();
};

#endif