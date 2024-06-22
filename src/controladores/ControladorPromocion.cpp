#include "../../include/controladores/ControladorPromocion.hh"

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

void ControladorPromocion::registrarDatosPromo(std::string n, std::string d, DTFecha f)
{
  if (promociones.count(n) == 0) // ver si fecha vencimiento > fecha actual?
  {
    nombre = n;
    descripcion = d;
    fechaVencimiento = f;
  }
}

void ControladorPromocion::asignarVendedor(std::string nickname)
{
  vendedor = Fabrica::getInterfazUsuario()->getVendedor(nickname);
}

void ControladorPromocion::agregarAPromo(int id, int cantMin, float porcentajeDescuento)
{
  // promociones.insert(Fabrica::getInterfazProducto()->getProducto(id));
  infoProductos.insert({id, InfoPromoProducto(id, porcentajeDescuento)});
  dtProductosPromo.insert({id, DTProductoPromo(id, nombre, cantMin, porcentajeDescuento)});
}

void ControladorPromocion::altaNuevaPromo()
{
  DTPromocion *dataprom = new DTPromocion(nombre, descripcion, fechaVencimiento, dtProductosPromo); // necesario?
  Promocion *promo = new Promocion(nombre, descripcion, fechaVencimiento, vendedor, productos, infoProductos);
  promociones.insert({promo->getNombre(), promo});
}
