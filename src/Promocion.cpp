#include "../include/Promocion.hh"

std::string Promocion::getNombre()
{
    return nombre;
}

std::string Promocion::getDescripcion()
{
    return descripcion;
}

DTFecha Promocion::getFechaDeVencimiento()
{
    return fechaDeVencimiento;
}

Vendedor *Promocion::getVendedor()
{
    return vendedor;
}

std::set<Producto *> Promocion::getProductos()
{
    return productos;
}

Producto *Promocion::getProducto(int id)
{
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            return *it;
        }
    }
    return NULL;
}

std::map<int, InfoPromoProducto> Promocion::getInfoProductos()
{
    return infoProductos;
}

InfoPromoProducto *Promocion::getInfoProducto(int id)
{
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            return &infoProductos.at(id);
        }
    }
    return NULL;
}

float Promocion::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}

void Promocion::setNombre(std::string n)
{
    nombre = n;
}

void Promocion::setDescripcion(std::string d)
{
    descripcion = d;
}

void Promocion::setFechaDeVencimiento(DTFecha f)
{
    fechaDeVencimiento = f;
}

void Promocion::setVendedor(Vendedor *v)
{
    vendedor = v;
}

void Promocion::setProductos(std::set<Producto *> p)
{
    productos = p;
}

void Promocion::setInfoProductos(std::map<int, InfoPromoProducto> pi)
{
    infoProductos = pi;
}

DTPromocion *Promocion::getDataPromocion() // revisar
{
    std::map<int, DTProductoPromo> dataProductosPromo;
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        int cantMin = infoProductos[(*it)->getId()].getCantidadMinima();
        float porcentajeDesc = getPorcentajeDescuento();
        dataProductosPromo.insert({(*it)->getId(), DTProductoPromo((*it)->getId(), (*it)->getNombre(), cantMin, porcentajeDesc)});
    }
    DTPromocion *dataPromocion = new DTPromocion(nombre, descripcion, fechaDeVencimiento, dataProductosPromo);
    return dataPromocion;
}

Promocion::Promocion()
{
}

Promocion::Promocion(std::string n, std::string d, DTFecha f)
{
    nombre = n;
    descripcion = d;
    fechaDeVencimiento = f;
}

Promocion::Promocion(std::string n, std::string d, DTFecha f, Vendedor *v)
{
    nombre = n;
    descripcion = d;
    fechaDeVencimiento = f;
    vendedor = v;
}

Promocion::Promocion(std::string n, std::string d, DTFecha f, Vendedor *v, std::set<Producto *> p, std::map<int, InfoPromoProducto> pi)
{
    nombre = n;
    descripcion = d;
    fechaDeVencimiento = f;
    vendedor = v;
    productos = p;
    infoProductos = pi;
}

Promocion::~Promocion() {}