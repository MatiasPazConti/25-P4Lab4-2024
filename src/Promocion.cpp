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
float Promocion::getPorcentajeDescuento()
{
    return porcentajeDescuento;
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

std::map<int, InfoPromoProducto *> Promocion::getInfoProductos()
{
    return infoProductos;
}

InfoPromoProducto *Promocion::getInfoProducto(int id)
{
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            return infoProductos.at(id);
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
void Promocion::setPorcentajeDescuento(float pd)
{
    porcentajeDescuento = pd;
}
void Promocion::setVendedor(Vendedor *v)
{
    vendedor = v;
}

void Promocion::setProductos(std::set<Producto *> p)
{
    productos = p;
}

void Promocion::setInfoProductos(std::map<int, InfoPromoProducto *> pi)
{
    infoProductos = pi;
}

DTPromocion *Promocion::getDataPromocion()
{
    std::map<int, DTProductoPromo *> dataProductosPromo;
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        int cantMin = (infoProductos[(*it)->getId()])->getCantidadMinima();
        DTProductoPromo *prodPromo = new DTProductoPromo((*it)->getId(), (*it)->getNombre(), cantMin);
        dataProductosPromo.insert({(*it)->getId(), prodPromo});
    };
    DTPromocion *dataPromocion = new DTPromocion(nombre, descripcion, fechaDeVencimiento, porcentajeDescuento, vendedor->getDataVendedor(), dataProductosPromo);
    return dataPromocion;
}

Promocion::Promocion()
{
}

Promocion::Promocion(std::string n, std::string d, DTFecha f, float pd)
{
    nombre = n;
    descripcion = d;
    fechaDeVencimiento = f;
    porcentajeDescuento = pd;
}

Promocion::Promocion(std::string n, std::string d, DTFecha f, float pd, Vendedor *v)
{
    nombre = n;
    descripcion = d;
    fechaDeVencimiento = f;
    porcentajeDescuento = pd;
    vendedor = v;
}

Promocion::Promocion(std::string n, std::string d, DTFecha f, float pd, Vendedor *v, std::set<Producto *> p, std::map<int, InfoPromoProducto *> pi)
{
    nombre = n;
    descripcion = d;
    fechaDeVencimiento = f;
    porcentajeDescuento = pd;
    vendedor = v;
    productos = p;
    infoProductos = pi;
}

Promocion::~Promocion() {}