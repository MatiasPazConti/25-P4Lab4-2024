#include "../../include/controladores/ControladorPromocion.hh"

std::string ControladorPromocion::getNombre()
{
  return nombre;
}

std::string ControladorPromocion::getDescripcion()
{
  return descripcion;
}

DTFecha ControladorPromocion::getFechaVencimiento()
{
  return fechaVencimiento;
}

void ControladorPromocion::setNombre(std::string n)
{
  nombre = n;
}

void ControladorPromocion::setDecripcion(std::string d)
{
  descripcion = d;
}

void ControladorPromocion::setFechaVencimiento(DTFecha f)
{
  fechaVencimiento = f;
}

void ControladorPromocion::registrarDatosPromo(std::string n, std::string d, DTFecha f) // ver si ya hay promo con ese nombre
{
  nombre = n;
  descripcion = d;
  fechaVencimiento = f;
}

void ControladorPromocion::asignarVendedor(std::string nickname) // copia de asignar cliente
{
  std::set<DTVendedor *> vendedores = Fabrica::getInterfazUsuario()->listarVendedores();
  for (std::set<DTVendedor *>::iterator it = vendedores.begin(); it != vendedores.end(); ++it)
  {
    if ((*it)->GetNickname() == nickname)
    {
      // hago algo (necesito una promo actual o un vendedor en controladorPromocion?)
      break;
    }
  }
}

void ControladorPromocion::asignarAPromo() // revisar que hace exactamente la funcion
{
}

void ControladorPromocion::altaNuevaPromo()
{
  Promocion promo = Promocion(nombre, descripcion, fechaVencimiento, vendedor, productos, infoProductos);
  DTPromocion dataprom = DTPromocion(nombre, descripcion, fechaVencimiento, dtProductosPromo);
}
