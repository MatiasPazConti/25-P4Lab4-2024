#include "../../include/controladores/ControladorPromocion.hh"

std::set<DTPromocion *> ControladorPromocion::obtenerPromocionesVigentes()
{
  std::set<DTPromocion *> promosVigentes;
  for (auto it = promociones.begin(); it != promociones.end(); ++it)
  {
    DTPromocion *dtpromo = ((*it).second)->getDataPromocion();
    promosVigentes.insert(dtpromo);
  };
  return promosVigentes;
}

DTPromocion *ControladorPromocion::getPromocion(std::string nombre)
{
  DTPromocion *promo = promociones[nombre]->getDataPromocion();
  return promo;
}

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

void ControladorPromocion::agregarAPromo(int id, int cantMin) // ver si prod ya esta en una promo?
{
  productos.insert(Fabrica::getInterfazProducto()->getProducto(id));
  InfoPromoProducto *promoProd = new InfoPromoProducto(id, cantMin);
  infoProductos.insert({id, promoProd});
void ControladorPromocion::agregarAPromo(int id, int cantMin)
{
  //promociones.insert(Fabrica::getInterfazProducto()->getProducto(id));
  infoProductos.insert({id, InfoPromoProducto(id, cantMin)});
  dtProductosPromo.insert({id, DTProductoPromo(id, nombre, cantMin, 0)});
}

void ControladorPromocion::altaNuevaPromo()
{
  Promocion *promo = new Promocion(nombre, descripcion, fechaVencimiento, porcentajeDescuento, vendedor, productos, infoProductos);
  promociones.insert({promo->getNombre(), promo});
  for (auto it = productos.begin(); it != productos.end(); ++it){
    (*it)->setPromocion(promo);
  }
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
