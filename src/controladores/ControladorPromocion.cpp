#include "../../include/controladores/ControladorPromocion.hh"
#include "../../include/fabrica/Fabrica.hh"

void ControladorPromocion::registrarDatosPromo(std::string nombre, std::string descripcion, DTFecha *fechaVencimiento, float porcentajeDescuento)
{
  if (promociones.count(nombre) == 0) // ver si fecha vencimiento > fecha actual?
  {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaVencimiento = fechaVencimiento;
    this->porcentajeDescuento = porcentajeDescuento;
  }
}
void ControladorPromocion::asignarVendedor(std::string nickname)
{
  vendedor = Fabrica::getInterfazUsuario()->getVendedor(nickname);
}
void ControladorPromocion::agregarAPromo(int id, int cantMin)
{
  Producto *productoPromo = Fabrica::getInterfazProducto()->getProducto(id);
  productos.insert(productoPromo);
  InfoPromoProducto *infoProductoPromo = new InfoPromoProducto(id, cantMin);
  infoProductos.insert({id, infoProductoPromo});
  dtProductosPromo.insert({id, DTProductoPromo(id, nombre, cantMin, 0)});
}
void ControladorPromocion::altaNuevaPromo()
{
  Promocion *promo = new Promocion(nombre, descripcion, fechaVencimiento, vendedor, productos, infoProductos);
  promociones.insert({promo->getNombre(), promo});
}
ControladorPromocion::ControladorPromocion() {}
ControladorPromocion::~ControladorPromocion() {}
ControladorPromocion *ControladorPromocion::instancia = nullptr;
ControladorPromocion *ControladorPromocion::getInstancia()
{
  if (instancia == nullptr)
  {
    instancia = new ControladorPromocion();
  }
  return instancia;
}