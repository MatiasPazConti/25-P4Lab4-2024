#ifndef PROMOCION
#define PROMOCION

#include "./datatypes/DTFecha.hh"
#include "./InfoPromoProducto.hh"
#include "Producto.hh"
#include "Vendedor.hh"

#include <iostream>
#include <set>
#include <map>

class Promocion
{
private:
    std::string nombre;
    std::string descripcion;
    DTFecha fechaDeVencimiento;
    Vendedor vendedor; //?
    std::set<Producto *> productos;
    std::map<Producto, InfoPromoProducto> InfoProductos; //?
public:
    std::string getNombre();
    std::string getDescripcion();
    DTFecha getFechaDeVencimiento();
    Vendedor getVendedor();
    std::set<Producto *> getProductos();
    Producto *getProducto(int);
    std::map<Producto, InfoPromoProducto> getInfoProductos();
    InfoPromoProducto *getInfoProducto(Producto *);

    void setNombre(std::string);
    void setDescripcion(std::string);
    void setFechaDeVencimiento(DTFecha);
    void setVendedor(Vendedor);
    void setProductos(std::set<Producto *>);
    void setInfoProductos(std::map<Producto, InfoPromoProducto>);

    void addProducto(Producto, InfoPromoProducto);
    void addProducto(Producto, int cantidadMinima, float porcentajeDescuento);

    Promocion();
    Promocion(std::string, std::string, DTFecha);
    Promocion(std::string, std::string, DTFecha, Vendedor); //?
    Promocion(std::string, std::string, DTFecha, Vendedor, std::set<Producto *>, std::map<Producto, InfoPromoProducto>);
    ~Promocion();
};

#endif