#include "./include/fabrica/Fabrica.hh"
#include "./include/datatypes/DTFecha.hh"
#include "./include/Vendedor.hh"
#include "./include/Cliente.hh"
#include <string>
#include <iostream>

IControladorUsuario *controladorUsuario = Fabrica::getInterfazUsuario();
IControladorProducto *controladorProducto = Fabrica::getInterfazProducto();
IControladorPromocion *controladorPromocion = Fabrica::getInterfazPromocion();
IControladorCompra *controladorCompra = Fabrica::getInterfazCompra();

// Funciones Auxiliares;
void ListarNickVendedores(std::set<DTVendedor *> vendedores) // funcion auxiliar
{
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    std::cout << "Nickname: " << nick;
    std::cout << std::endl;
  }
}

void ListarNickClientes() // funcion auxiliar
{
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    std::cout << "Nickname: " << nick;
    std::cout << std::endl;
  }
}

void ListarProductosDeVendedor(std::string nickname) // funcion auxiliar
{
  std::set<DTProducto *> productos = controladorUsuario->listarProductosVendedor(nickname);
  for (auto it = productos.begin(); it != productos.end(); it++)
  {
    int idProducto = (*it)->getId();
    std::string nombreProducto = (*it)->getNombre();
    std::cout << "Codigo: " << idProducto << ", Nombre: " << nombreProducto;
    std::cout << std::endl;
  }
}

bool ExisteVendedor(std::string nickname, std::set<DTVendedor *> vendedores) // funcion auxiliar
{
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return true;
    }
  }
  return false;
}

bool ExisteCliente(std::string nickname, std::set<DTCliente *> clientes) // funcion auxiliar
{
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return true;
    }
  }
  return false;
}

DTVendedor *datoVendedor(std::string nickname) // funcion auxiliar
{
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return (*it);
    }
  }
  return nullptr;
}

DTCliente *datoCliente(std::string nickname) // funcion auxiliar
{
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return (*it);
    }
  }
  return nullptr;
}

bool ExisteUsuario(std::string nickname) // funcion auxiliar
{
  std::set<DTUsuario *> usuarios = controladorUsuario->listarUsuarios();
  for (auto it = usuarios.begin(); it != usuarios.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return true;
    }
  }
  return false;
}

bool EstaEnPromo(int idProducto) // funcion auxiliar // falta implementar
{
  return false;
}

// Carga de datos iniciales:
void CargarDatos()
{
  // US1 - Usuario Uno - Vendedor
  std::string nickUS1 = "ana23";
  std::string passUS1 = "qwer1234";
  DTFecha fechaUS1 = DTFecha(15, 5, 1988);
  std::string rutUS1 = "212345678001";
  controladorUsuario->altaNuevoVendedor(nickUS1, passUS1, fechaUS1, rutUS1);

  // US2 - Usuario Dos - Vendedor
  std::string nickUS2 = "carlos78";
  std::string passUS2 = "asdfghj";
  DTFecha fechaUS2 = DTFecha(18, 6, 1986);
  std::string rutUS2 = "356789012345";
  controladorUsuario->altaNuevoVendedor(nickUS2, passUS2, fechaUS2, rutUS2);

  // US3 - Usuario Tres - Vendedor
  std::string nickUS3 = "diegom";
  std::string passUS3 = "zxcvbn";
  DTFecha fechaUS3 = DTFecha(28, 7, 1993);
  std::string rutUS3 = "190123456789";
  controladorUsuario->altaNuevoVendedor(nickUS3, passUS3, fechaUS3, rutUS3);

  // US4 - Usuario Cuatro - Cliente
  std::string nickUS4 = "juan87";
  std::string passUS4 = "1qaz2wsx";
  DTFecha fechaUS4 = DTFecha(20, 10, 1992);
  DTDireccion adressUS4 = DTDireccion("Av. 18 de Julio", 456);
  std::string cityUS4 = "Melo";
  controladorUsuario->altaNuevoCliente(nickUS4, passUS4, fechaUS4, adressUS4, cityUS4);

  // US5 - Usuario Cinco - Cliente
  std::string nickUS5 = "laura";
  std::string passUS5 = "3edc4rfv";
  DTFecha fechaUS5 = DTFecha(22, 9, 1979);
  DTDireccion adressUS5 = DTDireccion("Rondeau", 1617);
  std::string cityUS5 = "Montevideo";
  controladorUsuario->altaNuevoCliente(nickUS5, passUS5, fechaUS5, adressUS5, cityUS5);

  // US6 - Usuario Seis - Vendedor
  std::string nickUS6 = "maria01";
  std::string passUS6 = "5tgb6yhn";
  DTFecha fechaUS6 = DTFecha(25, 3, 1985);
  std::string rutUS6 = "321098765432";
  controladorUsuario->altaNuevoVendedor(nickUS6, passUS6, fechaUS6, rutUS6);

  // US7 - Usuario Siete - Cliente
  std::string nickUS7 = "natalia";
  std::string passUS7 = "poiuyt";
  DTFecha fechaUS7 = DTFecha(14, 4, 1982);
  DTDireccion adressUS7 = DTDireccion("Paysandu", 2021);
  std::string cityUS7 = "Salto";
  controladorUsuario->altaNuevoCliente(nickUS7, passUS7, fechaUS7, adressUS7, cityUS7);

  // US8 - Usuario Ocho - Cliente
  std::string nickUS8 = "pablo10";
  std::string passUS8 = "lkjhgv";
  DTFecha fechaUS8 = DTFecha(30, 11, 1995);
  DTDireccion adressUS8 = DTDireccion("Av. Rivera", 1819);
  std::string cityUS8 = "Mercedes";
  controladorUsuario->altaNuevoCliente(nickUS8, passUS8, fechaUS8, adressUS8, cityUS8);

  // US9 - Usuario Nueve - Cliente
  std::string nickUS9 = "roberto";
  std::string passUS9 = "mnbvcx";
  DTFecha fechaUS9 = DTFecha(12, 8, 1990);
  DTDireccion adressUS9 = DTDireccion("Av. Brasil", 1011);
  std::string cityUS9 = "Montevideo";
  controladorUsuario->altaNuevoCliente(nickUS9, passUS9, fechaUS9, adressUS9, cityUS9);

  // US10 - Usuario Diez - Vendedor
  std::string nickUS10 = "sofia25";
  std::string passUS10 = "1234asdf";
  DTFecha fechaUS10 = DTFecha(7, 12, 1983);
  std::string rutUS10 = "445678901234";
  controladorUsuario->altaNuevoVendedor(nickUS10, passUS10, fechaUS10, rutUS10);

  /*// PR1 - Producto 1 - US2
  int idPR1 = 1;
  std::string nombrePR1 = "Camiseta Azul";
  std::string descripcionPR1 = "Camiseta de poliester, color azul";
  float precioPR1 = 1400;
  int stockPR1 = 50;
  TipoProducto tipoPR1 = TipoProducto::Ropa;
  Producto *PR1 = new Producto(idPR1, nombrePR1, descripcionPR1, precioPR1, stockPR1, tipoPR1);
  US2->addProducto(PR1);

  // PR2 - Producto 2 - US1
  int idPR2 = 2;
  std::string nombrePR2 = "Televisor LED";
  std::string descripcionPR2 = "Televisor LED 55 pulgadas";
  float precioPR2 = 40500;
  int stockPR2 = 30;
  TipoProducto tipoPR2 = TipoProducto::Electrodomesticos;
  Producto *PR2 = new Producto(idPR2, nombrePR2, descripcionPR2, precioPR2, stockPR2, tipoPR2);
  US1->addProducto(PR2);

  // PR3 - Producto 3 - US2
  int idPR3 = 3;
  std::string nombrePR3 = "Chaqueta de Cuero";
  std::string descripcionPR3 = "Chaqueta de cuero, color negro";
  float precioPR3 = 699.99;
  int stockPR3 = 20;
  TipoProducto tipoPR3 = TipoProducto::Ropa;
  Producto *PR3 = new Producto(idPR3, nombrePR3, descripcionPR3, precioPR3, stockPR3, tipoPR3);
  US2->addProducto(PR3);

  // PR4 - Producto 4 - US1
  int idPR4 = 4;
  std::string nombrePR4 = "Microondas Digital";
  std::string descripcionPR4 = "Microondas digital, 30L";
  float precioPR4 = 1199.99;
  int stockPR4 = 15;
  TipoProducto tipoPR4 = TipoProducto::Electrodomesticos;
  Producto *PR4 = new Producto(idPR4, nombrePR4, descripcionPR4, precioPR4, stockPR4, tipoPR4);
  US1->addProducto(PR4);

  // PR5 - Producto 5 - US3
  int idPR5 = 5;
  std::string nombrePR5 = "Luz LED";
  std::string descripcionPR5 = "Luz Bluetooth LED";
  float precioPR5 = 599.99;
  int stockPR5 = 40;
  TipoProducto tipoPR5 = TipoProducto::Otros;
  Producto *PR5 = new Producto(idPR5, nombrePR5, descripcionPR5, precioPR5, stockPR5, tipoPR5);
  US3->addProducto(PR5);

  // PR6 - Producto 6 - US2
  int idPR6 = 6;
  std::string nombrePR6 = "Pantalones Vaqueros";
  std::string descripcionPR6 = "Pantalones vaqueros, talla 32";
  float precioPR6 = 60;
  int stockPR6 = 25;
  TipoProducto tipoPR6 = TipoProducto::Ropa;
  Producto *PR6 = new Producto(idPR6, nombrePR6, descripcionPR6, precioPR6, stockPR6, tipoPR6);
  US2->addProducto(PR6);

  // PR7 - Producto 7 - US3
  int idPR7 = 7;
  std::string nombrePR7 = "Auriculares Bluetooth";
  std::string descripcionPR7 = "Auriculares bluethooth para celular";
  float precioPR7 = 199.99;
  int stockPR7 = 35;
  TipoProducto tipoPR7 = TipoProducto::Otros;
  Producto *PR7 = new Producto(idPR7, nombrePR7, descripcionPR7, precioPR7, stockPR7, tipoPR7);
  US3->addProducto(PR7);

  // PR8 - Producto 8 - US1
  int idPR8 = 8;
  std::string nombrePR8 = "Refrigerador";
  std::string descripcionPR8 = "Refrigerador de doble puerta";
  float precioPR8 = 15499;
  int stockPR8 = 10;
  TipoProducto tipoPR8 = TipoProducto::Electrodomesticos;
  Producto *PR8 = new Producto(idPR8, nombrePR8, descripcionPR8, precioPR8, stockPR8, tipoPR8);
  US1->addProducto(PR8);

  // PR9 - Producto 9 - US1
  int idPR9 = 9;
  std::string nombrePR9 = "Cafetera";
  std::string descripcionPR9 = "Cafetera de goteo programable";
  float precioPR9 = 23000;
  int stockPR9 = 50;
  TipoProducto tipoPR9 = TipoProducto::Electrodomesticos;
  Producto *PR9 = new Producto(idPR9, nombrePR9, descripcionPR9, precioPR9, stockPR9, tipoPR9);
  US1->addProducto(PR9);

  // PR10 - Producto 10 - US2
  int idPR10 = 10;
  std::string nombrePR10 = "Zapatillas Deportivas";
  std::string descripcionPR10 = "Zapatillas para correr, talla 42";
  float precioPR10 = 5500;
  int stockPR10 = 20;
  TipoProducto tipoPR10 = TipoProducto::Ropa;
  Producto *PR10 = new Producto(idPR10, nombrePR10, descripcionPR10, precioPR10, stockPR10, tipoPR10);
  US2->addProducto(PR10);

  // PR11 - Producto 11 - US2
  int idPR11 = 11;
  std::string nombrePR11 = "Mochila";
  std::string descripcionPR11 = "Mochila de viaje, 40L";
  float precioPR11 = 9000;
  int stockPR11 = 30;
  TipoProducto tipoPR11 = TipoProducto::Otros;
  Producto *PR11 = new Producto(idPR11, nombrePR11, descripcionPR11, precioPR11, stockPR11, tipoPR11);
  US2->addProducto(PR11);

  // PR12 - Producto 12 - US3
  int idPR12 = 12;
  std::string nombrePR12 = "Plancha de Ropa";
  std::string descripcionPR12 = "2 Plancha a vapor, 1500W";
  float precioPR12 = 2534;
  int stockPR12 = 25;
  TipoProducto tipoPR12 = TipoProducto::Electrodomesticos;
  Producto *PR12 = new Producto(idPR12, nombrePR12, descripcionPR12, precioPR12, stockPR12, tipoPR12);
  US3->addProducto(PR12);

  // PR13 - Producto 13 - US10
  int idPR13 = 13;
  std::string nombrePR13 = "Gorra";
  std::string descripcionPR13 = "Gorra para deportes, color rojo";
  float precioPR13 = 200;
  int stockPR13 = 50;
  TipoProducto tipoPR13 = TipoProducto::Ropa;
  Producto *PR13 = new Producto(idPR13, nombrePR13, descripcionPR13, precioPR13, stockPR13, tipoPR13);
  US10->addProducto(PR13);

  // PR14 - Producto 14 - US3
  int idPR14 = 14;
  std::string nombrePR14 = "Tablet";
  std::string descripcionPR14 = "Tablet Android de 10 pulgadas";
  float precioPR14 = 15000;
  int stockPR14 = 15;
  TipoProducto tipoPR14 = TipoProducto::Electrodomesticos;
  Producto *PR14 = new Producto(idPR14, nombrePR14, descripcionPR14, precioPR14, stockPR14, tipoPR14);
  US3->addProducto(PR14);

  // PR15 - Producto 15 - US10
  int idPR15 = 15;
  std::string nombrePR15 = "Reloj de Pared";
  std::string descripcionPR15 = "Reloj de pared vintage";
  float precioPR15 = 150.50;
  int stockPR15 = 20;
  TipoProducto tipoPR15 = TipoProducto::Otros;
  Producto *PR15 = new Producto(idPR15, nombrePR15, descripcionPR15, precioPR15, stockPR15, tipoPR15);
  US10->addProducto(PR15);*/

  /////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////
  /////////// DTPromocion ¿? /////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////
  /*
         // PM1 - Promocion 1
         std::string nombrePM1 = "Casa nueva";
         std::string descrpcionPM1 = "Para que puedas ahorrar en la casa nueva";
         float porsentajeDescuentoPM1 = 30;
         DTFecha vencimientoPM1 = DTFecha(21, 10, 2024);
         // Productos relacionados Promocion 1
         // PP1: producto: PR2, Min: 1
         // PP2: producto: PR4, Min: 1
         // PP3: producto: PR8, Min: 1

         // PM2 - Promocion 2
         std::string nombrePM2 = "Fiesta";
         std::string descrpcionPM2 = "Para que no te quedes sin ropa para las fiestas";
         float porsentajeDescuentoPM2 = 20;
         DTFecha vencimientoPM2 = DTFecha(26, 10, 2024);
         // Productos relacionados Promocion 2
         // PP4: producto: PR3, Min: 2
         // PP5: producto: PR6, Min: 3

         // PM3 - Promocion 3
         std::string nombrePM3 = "Domotica";
         std::string descrpcionPM3 = "Para modernizar tu casa";
         float porsentajeDescuentoPM3 = 10;
         DTFecha vencimientoPM3 = DTFecha(26, 10, 2024);
         // Productos relacionados Promocion 3
         // PP6: producto: PR5, Min: 2

         // PM4 - Promocion 4
         std::string nombrePM3 = "Liquidacion";
         std::string descrpcionPM3 = "Hasta agotar stock";
         float porsentajeDescuentoPM3 = 10;
         DTFecha vencimientoPM3 = DTFecha(26, 03, 2024);
         // Productos relacionados Promocion 3
         // PP7: producto: PR14, Min: 1

         ////////////////////////////////////////////////////////////////////////////
         ////////  DTCompra(DTFecha, float) decha,montofinal ----------  Cliente? producto???
         ////////    DTRegistroProducto(int,std::string,int,float,bool); //id,nombre,cantidad,precio,enviadocorrectamente
         ////////////////////////////////////////////////////////////////////////////

         // CO1 - Compra 1
         DTCliente clienteCO1 = US4;
         DTFecha fechaCO1 = DTFecha(01, 05, 2024);
         float montoCO1 = 57581.993;
         DTPromocion promoCO1 = PM1;
         // Productos relacionados Compra 1
         // CP1 - Producto: PR2 - Cantidad: 2 - Enviado: Si
         DTRegistroPrducto *primerRegistroCO1 = new DTRegistroPrducto(idPR2, nombrePR2, 2, precioPR2, true);
         // CP2 - Producto: PR4 - Cantidad: 1 - Enviado: No
         DTRegistroPrducto *segundoRegistroCO1 = new DTRegistroPrducto(idPR4, nombrePR4, 1, precioPR4, false);
         // CP3 - Producto: PR8 - Cantidad: 1 - Enviado: No
         DTRegistroPrducto *tercerRegistroCO1 = new DTRegistroPrducto(idPR8, nombrePR8, 1, precioPR8, false);

         // CO2 - Compra 2
         DTCliente clienteCO2 = US4;
         DTFecha fechaCO2 = DTFecha(01, 05, 2024);
         float montoCO2 = 599.99;
         DTPromocion promoCO2 = NULL;
         // Productos relacionados Compra 2
         // CP4 - Producto: PR5 - Cantidad: 1 - Enviado: Si
         DTRegistroPrducto *primerRegistroCO2 = new DTRegistroPrducto(idPR5, nombrePR5, 1, precioPR5, true);

         // CO2 - Compra 3
         DTCliente clienteCO3 = US5;
         DTFecha fechaCO3 = DTFecha(15, 05, 2024);
         float montoCO3 = 150000;
         DTPromocion promoCO3 = NULL;
         // Productos relacionados Compra 3
         // CP5 - Producto: PR14 - Cantidad: 10 - Enviado: Si
         DTRegistroPrducto *primerRegistroCO3 = new DTRegistroPrducto(idPR14, nombrePR14, 10, precioPR14, true);

         // CO4 - Compra 4
         DTCliente clienteCO4 = US7;
         DTFecha fechaCO4 = DTFecha(25, 04, 2024);
         float montoCO4 = 11734;
         DTPromocion promoCO4 = NULL;
         // Productos relacionados Compra 4
         // CP6 - Producto: PR11 - Cantidad: 1 - Enviado: Si
         DTRegistroPrducto *primerRegistroCO4 = new DTRegistroPrducto(idPR11, nombrePR11, 1, precioPR11, true);
         // CP7 - Producto: PR12 - Cantidad: 1 - Enviado: Si
         DTRegistroPrducto *segundoRegistroCO4 = new DTRegistroPrducto(idPR12, nombrePR12, 1, precioPR12, true);
         // CP8 - Producto: PR13 - Cantidad: 1 - Enviado: Si
         DTRegistroPrducto *tercerRegistroCO4 = new DTRegistroPrducto(idPR13, nombrePR13, 1, precioPR13, true);

         // CO5 - Compra 5
         DTCliente clienteCO5 = US4;
         DTFecha fechaCO5 = DTFecha(20, 05, 2024);
         float montoCO5 = 1263.984;
         DTPromocion promoCO5 = PM2;
         // Productos relacionados Compra 5
         // CP8 - Producto: PR3 - Cantidad: 2 - Enviado: No
         DTRegistroPrducto *primerRegistroCO5 = new DTRegistroPrducto(idPR3, nombrePR3, 2, precioPR3, false);
         // CP8 - Producto: PR6 - Cantidad: 3 - Enviado: Si
         DTRegistroPrducto *segundoRegistroCO5 = new DTRegistroPrducto(idPR6, nombrePR6, 3, precioPR6, true);

         // CO6 - Compra 6
         DTCliente clienteCO6 = US5;
         DTFecha fechaCO6 = DTFecha(12, 05, 2024);
         float montoCO6 = 2800;
         DTPromocion promoCO6 = NULL;
         // Productos relacionados Compra 6
         // CP9 - Producto: PR1 - Cantidad: 2 - Enviado: No
         DTRegistroPrducto *primerRegistroCO6 = new DTRegistroPrducto(idPR1, nombrePR1, 2, precioPR1, false);

         // CO7 - Compra 7
         DTCliente clienteCO7 = US7;
         DTFecha fechaCO7 = DTFecha(12, 05, 2024);
         float montoCO7 = 4200;
         DTPromocion promoCO7 = NULL;
         // Productos relacionados Compra 7
         // CP10 - Producto: PR1 - Cantidad: 3 - Enviado: Si
         DTRegistroPrducto *primerRegistroCO7 = new DTRegistroPrducto(idPR1, nombrePR1, 3, precioPR1, true);

         // CO8 - Compra 8
         DTCliente clienteCO8 = US8;
         DTFecha fechaCO8 = DTFecha(14, 05, 2024);
         float montoCO8 = 5600;
         DTPromocion promoCO8 = NULL;
         // Productos relacionados Compra 8
         // CP11 - Producto: PR1 - Cantidad: 4 - Enviado: No
         DTRegistroPrducto *primerRegistroCO8 = new DTRegistroPrducto(idPR1, nombrePR1, 4, precioPR1, false);

         // CO9 - Compra 9
         DTCliente clienteCO9 = US9;
         DTFecha fechaCO9 = DTFecha(15, 05, 2024);
         float montoCO9 = 7000;
         DTPromocion promoCO8 = NULL;
         // Productos relacionados Compra 9
         // CP12 - Producto: PR1 - Cantidad: 5 - Enviado: No
         DTRegistroPrducto *primerRegistroCO9 = new DTRegistroPrducto(idPR1, nombrePR1, 5, precioPR1, false);
         */

  // std::cout << US1->GetNickname() << std::endl;
  std::cout << "Los datos iniciales fueron cargados." << std::endl;
}

// Casos de Uso:
void NuevoVendedor() // Implementado //
{
  std::string nickUS;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUS;
  while (nickUS.length() <= 5)
  {
    std::cout << "El nickname debe tener al menos 6 caracteres" << std::endl;
    std::cin >> nickUS;
  }
  if (!ExisteUsuario(nickUS))
  {
    std::string passUS;
    std::cout << "Escriba su password" << std::endl;
    std::cin >> passUS;
    while (passUS.length() <= 5)
    {
      std::cout << "Su password debe tener al menos 6 caracteres" << std::endl;
      std::cin >> passUS;
    }
    int diaUS;
    std::cout << "Escriba su dia de naciemiento" << std::endl;
    std::cin >> diaUS;
    while (diaUS >= 32)
    {
      std::cout << "Ingrese un numero de dia valido" << std::endl;
      std::cin >> diaUS;
    }
    int mesUS;
    std::cout << "Escriba su mes de naciemiento" << std::endl;
    std::cin >> mesUS;
    while (mesUS >= 13)
    {
      std::cout << "Ingrese un numero de mes valido" << std::endl;
      std::cin >> mesUS;
    }
    int anioUS;
    std::cout << "Escriba su anio de naciemiento" << std::endl;
    std::cin >> anioUS;
    while (anioUS >= 2025)
    {
      std::cout << "Ingrese un numero de anio valido" << std::endl;
      std::cin >> anioUS;
    }
    DTFecha fechaUS = DTFecha(diaUS, mesUS, anioUS);
    std::string rutUS;
    std::cout << "Escriba su codigo RUT" << std::endl;
    std::cin >> rutUS;
    while (rutUS.length() != 12)
    {
      std::cout << "El codigo RUT debe contener 12 caracteres" << std::endl;
      std::cin >> rutUS;
    }
    controladorUsuario->altaNuevoVendedor(nickUS, passUS, fechaUS, rutUS);
    std::cout << "Vendedor registrado con exito." << std::endl;
  }
  else
  {
    std::cout << "El nickname seleccionado no esta disponible." << std::endl;
  }
}

void NuevoCliente() // Implementado //
{
  std::string nickUS;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUS;
  while (nickUS.length() <= 5)
  {
    std::cout << "El nickname debe tener al menos 6 caracteres" << std::endl;
    std::cin >> nickUS;
  }
  if (!ExisteUsuario(nickUS))
  {
    std::string passUS;
    std::cout << "Escriba su password" << std::endl;
    std::cin >> passUS;
    while (passUS.length() <= 5)
    {
      std::cout << "Su password debe tener al menos 6 caracteres" << std::endl;
      std::cin >> passUS;
    }
    int diaUS;
    std::cout << "Escriba su dia de naciemiento" << std::endl;
    std::cin >> diaUS;
    while (diaUS >= 32)
    {
      std::cout << "Ingrese un numero de dia valido" << std::endl;
      std::cin >> diaUS;
    }
    int mesUS;
    std::cout << "Escriba su mes de naciemiento" << std::endl;
    std::cin >> mesUS;
    while (mesUS >= 13)
    {
      std::cout << "Ingrese un numero de mes valido" << std::endl;
      std::cin >> mesUS;
    }
    int anioUS;
    std::cout << "Escriba su anio de naciemiento" << std::endl;
    std::cin >> anioUS;
    while (anioUS >= 2025)
    {
      std::cout << "Ingrese un numero de anio valido" << std::endl;
      std::cin >> anioUS;
    }
    DTFecha fechaUS = DTFecha(diaUS, mesUS, anioUS);
    std::string calleUS;
    std::cout << "Escriba la calle de su domicilio" << std::endl;
    std::getline(std::cin >> std::ws, calleUS);
    int nroPuertaUS;
    std::cout << "Escriba su numero de puerta" << std::endl;
    std::cin >> nroPuertaUS;
    DTDireccion adressUS = DTDireccion(calleUS, nroPuertaUS);
    std::string cityUS;
    std::cout << "Escriba la ciudad en la que vive" << std::endl;
    std::getline(std::cin >> std::ws, cityUS); // uso ws para limpiar los espacios pendientes
    controladorUsuario->altaNuevoCliente(nickUS, passUS, fechaUS, adressUS, cityUS);
    std::cout << "Cliente registrado con exito." << std::endl;
  }
  else
  {
    std::cout << "El nickname seleccionado no esta disponible." << std::endl;
  }
}

void ListarUsuarios() // Implementado //
{
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    DTFecha fecha = (*it)->getFechaNacimiento();
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int anio = fecha.getAnio();
    std::string rut = (*it)->getCodigoRUT();
    std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << ", Codigo RUT: " << rut;
    std::cout << std::endl;
  }
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    DTFecha fecha = (*it)->getFechaNacimiento();
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int anio = fecha.getAnio();
    DTDireccion adress = (*it)->getDireccion();
    int nroPuerta = adress.getNroPuerta();
    std::string calle = adress.getNombreCalle();
    std::string ciudad = (*it)->getCiudadDeResidencia();
    std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << ", Direccion: " << calle << "," << nroPuerta << ", Ciudad: " << ciudad;
    std::cout << std::endl;
  }
}

void AltaDeProducto() // Implementado //
{
  std::string nickVendedor;
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  ListarNickVendedores(vendedores);
  std::cout << "Escriba el nombre del vendedor" << std::endl;
  std::cin >> nickVendedor;
  if (ExisteVendedor(nickVendedor, vendedores))
  {
    std::string nombreProducto;
    std::cout << "Escriba el nombre del producto" << std::endl;
    std::getline(std::cin >> std::ws, nombreProducto);
    float precioProducto;
    std::cout << "Escriba el precio del producto" << std::endl;
    std::cin >> precioProducto;
    int stockProducto;
    std::cout << "Escriba el stock del producto" << std::endl;
    std::cin >> stockProducto;
    std::string descripcionProducto;
    std::cout << "Escriba la descripcion del producto" << std::endl;
    std::getline(std::cin >> std::ws, descripcionProducto);
    int intCategoriaProducto;
    std::cout << "Seleccione la categoria del producto" << std::endl
              << "1-Electrodomestico" << std::endl
              << "2-Ropa" << std::endl
              << "3-Otros" << std::endl;
    std::cin >> intCategoriaProducto;
    TipoProducto categoriaProducto = (TipoProducto)intCategoriaProducto;
    DTVendedor *punteroVendedor = datoVendedor(nickVendedor);
    controladorProducto->registrarDatosProductos(nombreProducto, precioProducto, stockProducto, descripcionProducto, categoriaProducto, punteroVendedor);
    std::cout << "El producto fue registrado con exito" << std::endl;
  }
  else
  {
    std::cout << "El vendedor ingresado no existe" << std::endl;
  }
}

void ConsultarUnProducto() // Implementado //
{
  std::set<DTProducto *> productos = controladorProducto->obtenerProductosDisponibles();
  for (auto it = productos.begin(); it != productos.end(); it++)
  {
    int idProductos = (*it)->getId();
    std::string nickProductos = (*it)->getNombre();
    std::cout << "Codigo: " << idProductos << ", Nombre: " << nickProductos;
    std::cout << std::endl;
  }
  int idProducto;
  std::cout << "Escriba el ID del producto que desea ver." << std::endl;
  std::cin >> idProducto;
  DTProducto *producto = controladorProducto->obtenerProductoDisponible(idProducto);

  int precioProducto = producto->getPrecio();
  int stockProducto = producto->getCantidadEnStock();
  std::string descripcionProducto = producto->getDescripcion();
  TipoProducto tipoDelProducto = producto->getTipoProducto();
  std::string tipoDelPrudctoString;
  switch (tipoDelProducto)
  {
  case TipoProducto::Electrodomesticos:
    tipoDelPrudctoString = "Electrodomesticos";
    break;
  case TipoProducto::Ropa:
    tipoDelPrudctoString = "Ropa";
    break;

  default:
    tipoDelPrudctoString = "Otros";
    break;
  }
  DTVendedor *vendedorProducto = producto->getVendedor();
  std::string vendedorProductoString = vendedorProducto->getNickname();
  std::cout << "Precio: " << precioProducto << ", Stock: " << stockProducto << ", Descripcion: " << descripcionProducto << ", Categoria: " << tipoDelPrudctoString << ", Vendedor: " << vendedorProductoString;
  std::cout << std::endl;
}

void CrearPromocion() // incompleto // agregar "EstaEnPromo"
{
  // ingreso de datos de la promo
  std::string nombrePromo;
  std::cout << "Escriba el nombre de la promocion" << std::endl;
  std::getline(std::cin >> std::ws, nombrePromo);
  std::string descripcionPromo;
  std::cout << "Escriba la descripcion de la promocion" << std::endl;
  std::getline(std::cin >> std::ws, descripcionPromo);
  int diaPromo;
  std::cout << "Escriba el dia de vencimiento de la promocion" << std::endl;
  std::cin >> diaPromo;
  while (diaPromo >= 32)
  {
    std::cout << "Ingrese un numero de dia valido" << std::endl;
    std::cin >> diaPromo;
  }
  int mesPromo;
  std::cout << "Escriba el mes de vencimiento de la promocion" << std::endl;
  std::cin >> mesPromo;
  while (mesPromo >= 13)
  {
    std::cout << "Ingrese un numero de mes valido" << std::endl;
    std::cin >> mesPromo;
  }
  int anioPromo;
  std::cout << "Escriba el anio de vencimiento de la promocion" << std::endl;
  std::cin >> anioPromo;
  DTFecha fechaPromo = DTFecha(diaPromo, mesPromo, anioPromo);
  // porsentaje de descuento a la promocion
  int descuentoPromo;
  std::cout << "Escriba el porsentaje de descuento de la promocion" << std::endl;
  std::cin >> descuentoPromo;
  while (descuentoPromo >= 101)
  {
    std::cout << "El descuento no puede ser mayor al 100%" << std::endl;
    std::cin >> descuentoPromo;
  }
  controladorPromocion->registrarDatosPromo(nombrePromo, descripcionPromo, fechaPromo, descuentoPromo);
  // seleccion de vendedor
  controladorUsuario->listarVendedores();
  std::string vendedorPromo;
  std::cout << "Escriba el nickname del vendedor de la promocion" << std::endl;
  std::cin >> vendedorPromo;
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  while (!ExisteVendedor(vendedorPromo, vendedores))
  {
    std::cout << "El vendedor ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un vendedor valido" << std::endl;
    std::cin >> vendedorPromo;
  }
  controladorPromocion->asignarVendedor(vendedorPromo);
  // seleccion de productos del vendedor mencionado.
  int opcion = 1;
  while (opcion != 2)
  {
    if (opcion == 1)
    {
      ListarProductosDeVendedor(vendedorPromo);
      int IdAgregarPromo;
      std::cout << "Escriba el codigo de producto que desea asignar a la promocion" << std::endl;
      std::cin >> IdAgregarPromo;
      while (!EstaEnPromo(IdAgregarPromo))
      {
        std::cout << "El producto seleccionado ya se encuentra en una promocion" << std::endl;
        std::cout << "Porfavor ingrese un producto valido" << std::endl;
        std::cin >> IdAgregarPromo;
      };
      int stockAgregarPromo;
      std::cout << "Escriba la cantidad minima del producto" << std::endl;
      std::cin >> stockAgregarPromo;
      controladorPromocion->agregarAPromo(IdAgregarPromo, stockAgregarPromo);
    }
    std::cout << "1-Agregar otro producto a la promocion" << std::endl
              << "2-Dar de alta la promocion" << std::endl;
    std::cin >> opcion;
  }
  // se realiza el alta de la promocion
  controladorPromocion->altaNuevaPromo();
}

void ConsultarPromocion()
{
  std::cout << "PROMOCIONES VIGENTES EN EL SISTEMA" << std::endl;
  std::set<DTPromocion *> promociones = controladorPromocion->obtenerPromocionesVigentes();
  for (auto it = promociones.begin(); it != promociones.end(); it++)
  {
    std::string nombrePromo = (*it)->getNombre();
    std::string descripcionPromo = (*it)->getDescripcion();
    DTFecha fechaVPromo = (*it)->getFechaVencimiento();
    float descuentoPromo = (*it)->getPorcentajeDescuento();
    std::cout << "Nombre: " << nombrePromo << std::endl
              << "Descripcion: " << descripcionPromo << std::endl
              << "Fecha de vencimiento: " << fechaVPromo.getDia() << "/" << fechaVPromo.getMes() << "/" << fechaVPromo.getAnio() << std::endl
              << "Descuento: " << descuentoPromo << "%" << std::endl
              << "Productos: " << std::endl;
    // imprimo todos los productos de cada promo
    std::map<int, DTProductoPromo *> productos = (*it)->getProductos();
    for (auto it = productos.begin(); it != productos.end(); it++)
    {
      int idProductos = (*it).first;
      std::string nickProductos = ((*it).second)->getNombre();
      std::cout << "Codigo: " << idProductos << ", Nombre: " << nickProductos;
      std::cout << std::endl;
    }
  }
  std::cout << "1-Ver en detalle los productos de una promocion" << std::endl
            << "2-Salir";
  int opcionElegida;
  std::cin >> opcionElegida;
  if (opcionElegida == 1)
  {
    std::cout << "Ingrese el nombre de la promocion: ";
    std::string nombrePromoElegida;
    std::cin >> nombrePromoElegida;
    DTPromocion *promoElegida = controladorPromocion->getPromocion(nombrePromoElegida);
    std::cout << "Informacion del vendedor de la promocion: " << std::endl;
    DTVendedor *vendedorElegido = (promoElegida->getVendedor());
    std::cout << "Nombre: " << vendedorElegido->getNickname() << std::endl
              << "Fecha de nacimiento" << vendedorElegido->getFechaNacimiento().getDia() << vendedorElegido->getFechaNacimiento().getMes() << vendedorElegido->getFechaNacimiento().getAnio() << std::endl
              << "Codigo Rut: " << vendedorElegido->getCodigoRUT() << std::endl;
    std::cout << "Informacion de los productos de la promocion: " << std::endl;
    ListarProductosDeVendedor(vendedorElegido->getNickname());
  }
  else if (opcionElegida == 2)
  {
    //////
  }
};

void RealizarCompra()
{
}

void DejarComentario()
{
}

void EliminarComentario()
{
}

void EnviarProducto()
{
}

void ExpedienteUsuario() // incompleto // falta obtener lista de promos de un vendedor
{
  ListarUsuarios();
  std::string nickUsuario;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUsuario;
  while (!ExisteUsuario(nickUsuario))
  {
    std::cout << "El usuario ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un usuario valido" << std::endl;
    std::cin >> nickUsuario;
  }
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  if (ExisteCliente(nickUsuario, clientes))
  {
    DTCliente *esCliente = datoCliente(nickUsuario);
    std::string nick = esCliente->getNickname();
    DTFecha fecha = esCliente->getFechaNacimiento();
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int anio = fecha.getAnio();
    std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio;
    std::cout << std::endl;
    // ListarComprasRealizadas(nickCliente);
  }
  else
  {
    DTVendedor *esVendedor = datoVendedor(nickUsuario);
    std::string nickVendedor = esVendedor->getNickname();
    DTFecha fechaVendedor = esVendedor->getFechaNacimiento();
    int dia = fechaVendedor.getDia();
    int mes = fechaVendedor.getMes();
    int anio = fechaVendedor.getAnio();
    std::cout << "Nickname: " << nickVendedor << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio;
    std::cout << std::endl;
    ListarProductosDeVendedor(nickVendedor);
    // ListarPromosVigentesVendedor(nickVendedor);
  }
}

void SuscribirseNotificacion() // Implementado
{
  ListarNickClientes();
  std::string nickCliente;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickCliente;
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  while (!ExisteCliente(nickCliente, clientes))
  {
    std::cout << "El cliente ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un cliente valido" << std::endl;
    std::cin >> nickCliente;
  }
  int opcion = 1;
  std::set<std::string> nickVendedores;
  while (opcion != 2)
  {
    if (opcion == 1)
    {
      std::set<DTVendedor *> vendedoresNoSuscripto = controladorUsuario->listarVendedoresNoSuscritos(nickCliente);
      ListarNickVendedores(vendedoresNoSuscripto);
      std::string vendedor;
      std::cout << "Ingrese el nickname del vendedor al que desea suscribirse" << std::endl;
      std::cin >> vendedor;

      while (!ExisteVendedor(vendedor, vendedoresNoSuscripto))
      {
        std::cout << "Porfavor ingrese un vendedor valido" << std::endl;
        std::cin >> vendedor;
      };
      nickVendedores.insert(vendedor);
      controladorUsuario->realizarSuscripciones(nickCliente, nickVendedores);
      nickVendedores.erase(vendedor);
    }
    std::cout << "1-Agregar otra suscripcion" << std::endl
              << "2-Salir de realizar suscripciones" << std::endl;
    std::cin >> opcion;
  }
}

void ConsultaNotificacion() // incompleto // falta obtener string de nombre de los "productosEnPromo", "eliminarNotificaciones"
{
  ListarNickClientes();
  std::string nickCliente;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickCliente;
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  while (!ExisteCliente(nickCliente, clientes))
  {
    std::cout << "El cliente ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un cliente valido" << std::endl;
    std::cin >> nickCliente;
  }
  std::set<DTNotificacion *> notificaciones = controladorUsuario->listarNotificaciones(nickCliente);
  std::set<std::string> nickVendedores;
  for (auto it = notificaciones.begin(); it != notificaciones.end(); it++)
  {
    std::string nickVendedor = (*it)->getNicknameVendedor();
    std::string nombrePromocion = (*it)->getNombrePromocion();
    // std::set<string> productosEnPromo = (*it)->getProductosEnPromo();
    std::cout << "Vendedor: " << nickVendedor << ", Promocion: " << nombrePromocion;
    // for (auto it2 = productosEnPromo.begin(); it2 != productosEnPromo.end(); it2++)
    //{
    //   std::cout << ", Producto: " << (*it2);
    // };
    std::cout << std::endl;
    nickVendedores.insert(nickVendedor);
  };
  // controladorUsuario->eliminarNotificaciones(nickCliente, nickVendedores);
}

void EliminarSuscripcion() // incompleto // falta: "ListarVendedoresSuscripto"
{
  ListarNickClientes();
  std::string nickCliente;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickCliente;
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  while (!ExisteCliente(nickCliente, clientes))
  {
    std::cout << "El cliente ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un cliente valido" << std::endl;
    std::cin >> nickCliente;
  }
  /*std::set<DTVendedor *> vendedoresSuscripto = controladorUsuario->ListarVendedoresSuscripto(nickCliente);
  ListarNickVendedores(vendedoresSuscripto);
  std::string vendedor;
  std::cout << "Ingrese el nickname del vendedor al que desea eliminar su suscripcion" << std::endl;
  std::cin >> vendedor;
  int opcion = 1;
  std::set<std::string> nickVendedores;
  while (opcion != 2)
  {
    if (opcion == 1)
    {
      std::set<DTVendedor *> vendedoresSuscripto = controladorUsuario->ListarVendedoresSuscripto(nickCliente);
      ListarNickVendedores(vendedoresSuscripto);
      std::string vendedor;
      std::cout << "Ingrese el nickname del vendedor al que desea eliminar su suscripcion" << std::endl;
      std::cin >> vendedor;
      while (!ExisteVendedor(vendedor, vendedoresSuscripto))
      {
        std::cout << "Porfavor ingrese un vendedor valido" << std::endl;
        std::cin >> vendedor;
      };
      nickVendedores.insert(vendedor);
      controladorUsuario->eliminarSuscripciones(nickCliente,nickVendedores);
      nickVendedores.erase(vendedor);
    }
    std::cout << "1-Eliminar otra suscripcion" << std::endl
              << "2-Salir de eliminar suscripciones" << std::endl;
    std::cin >> opcion;
  }*/
}

int main()
{
  while (true)
  {
    int input = 0;
    std::cout << "Menu de Opciones" << std::endl
              << "1-Cargar datos iniciales" << std::endl
              << "2-Registrar nuevo usuario" << std::endl       // Implementado
              << "3-Listado de usuarios exitentes" << std::endl // Implementado
              << "4-Alta de producto" << std::endl              // Implementado
              << "5-Consultar un producto" << std::endl         // Implementado
              << "6-Crear una nueva promocion" << std::endl     // incompleto
              << "7-Consultar una promocion" << std::endl
              << "8-Realizar una compra" << std::endl
              << "9-Dejar un comentario" << std::endl
              << "10-Eliminar un comentario" << std::endl
              << "11-Enviar un producto" << std::endl
              << "12-Expediente de usuario" << std::endl
              << "13-Suscribirse a notificacion" << std::endl // Implementado
              << "14-Consulta de notificaciones" << std::endl // incompleto
              << "15-Eliminar suscripcion" << std::endl       // incompleto
              << "16-Salir" << std::endl;
    std::cin >> input;
    switch (input)
    {
    case 1: // Cargar datos iniciales
      CargarDatos();
      break;

    case 2: // Registrar nuevo usuario
      std::cout << "Elija el tipo de usuario que desea registrar" << std::endl
                << "1-Vendedor" << std::endl
                << "2-Cliente" << std::endl;
      std::cin >> input;
      switch (input)
      {
      case 1:
        NuevoVendedor();
        break;
      case 2:
        NuevoCliente();
        break;
      default:
        std::cout << "Opcion invalida" << std::endl;
        break;
      }
      break;

    case 3: // Listado de usuarios exitentes
      ListarUsuarios();
      break;

    case 4: // Alta de producto
      AltaDeProducto();
      break;

    case 5: // Consultar un producto
      ConsultarUnProducto();
      break;

    case 6: // Crear una nueva promocion
      CrearPromocion();
      break;

    case 7: // Consultar una promocion
      ConsultarPromocion();
      break;

    case 8: // Realizar una compra
      RealizarCompra();
      break;

    case 9: // Dejar un comentario
      DejarComentario();
      break;

    case 10: // Eliminar un comentario
      EliminarComentario();
      break;

    case 11: // Enviar un producto
      EnviarProducto();
      break;

    case 12: // Expediente de usuario
      ExpedienteUsuario();
      break;

    case 13: // Suscribirse a notificacion
      SuscribirseNotificacion();
      break;

    case 14: // Consulta de notificaciones
      ConsultaNotificacion();
      break;

    case 15: // Eliminar suscripcion
      EliminarSuscripcion();
      break;

    case 16: // Salir
      return 0;
      break;

    default: // Otro numero
      std::cout << "Opcion invalida" << std::endl;
      break;
    }
  }

  return 0;
}