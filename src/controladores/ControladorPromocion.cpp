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

void ControladorPromocion::asignarVendedor(std::string nickname)
{
  std::set<DTVendedor *> vendedores = Fabrica::getInterfazUsuario()->listarVendedores();
  for (std::set<DTVendedor *>::iterator it = vendedores.begin(); it != vendedores.end(); ++it)
  {
    if ((*it)->GetNickname() == nickname)
    {
      // hago algo
      break;
    }
  }
}

void ControladorPromocion::asignarAPromo()
{
}

void ControladorPromocion::altaNuevaPromo()
{
  Promocion promo = Promocion(nombre, descripcion, fechaVencimiento, );        //
  DTPromocion dataprom = DTPromocion(nombre, descripcion, fechaVencimiento, ); // que hago con el set de DTProductoPromo
}
