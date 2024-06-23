#include "../../include/controladores/ControladorPromocion.hh"

void ControladorPromocion::registrarDatosPromo(std::string n, std::string d, DTFecha f, float porcentaje)
{
  if (promociones.count(n) == 0)
  {
    nombre = n;
    descripcion = d;
    fechaVencimiento = f;
    porcentajeDescuento = porcentaje;
  }
}

void ControladorPromocion::asignarVendedor(std::string nickname)
{
  vendedor = Fabrica::getInterfazUsuario()->getVendedor(nickname);
}

void ControladorPromocion::agregarAPromo(int id, int cantMin)
{
  productos.insert(Fabrica::getInterfazProducto()->getProducto(id));
  infoProductos.insert({id, InfoPromoProducto(cantMin)});
}

void ControladorPromocion::altaNuevaPromo()
{
  Promocion *promo = new Promocion(nombre, descripcion, fechaVencimiento, porcentajeDescuento, vendedor, productos, infoProductos);
  promociones.insert({promo->getNombre(), promo});
}

ControladorPromocion::~ControladorPromocion()
{
}
ControladorPromocion::ControladorPromocion() {}

ControladorPromocion *ControladorPromocion::instancia = nullptr;
ControladorPromocion *ControladorPromocion::getInstancia()
{
  if (instancia == nullptr)
  {
    instancia = new ControladorPromocion();
  }
  return instancia;
}
