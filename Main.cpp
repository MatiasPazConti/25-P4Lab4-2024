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
}

void NuevoVendedor()
{
  std::string nickUS;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUS;
  std::string passUS;
  std::cout << "Escriba su password" << std::endl;
  std::cin >> passUS;
  int diaUS;
  std::cout << "Escriba su dia de naciemiento" << std::endl;
  std::cin >> diaUS;
  int mesUS;
  std::cout << "Escriba su mes de naciemiento" << std::endl;
  std::cin >> mesUS;
  int anioUS;
  std::cout << "Escriba su anio de naciemiento" << std::endl;
  std::cin >> anioUS;
  DTFecha fechaUS = DTFecha(diaUS, mesUS, anioUS);
  std::string rutUS;
  std::cout << "Escriba su codigo RUT" << std::endl;
  std::cin >> rutUS;
  controladorUsuario->altaNuevoVendedor(nickUS, passUS, fechaUS, rutUS);
  std::cout << "Vendedor registrado con exito." << std::endl;
}

void NuevoCliente()
{
  std::string nickUS;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUS;
  std::string passUS;
  std::cout << "Escriba su password" << std::endl;
  std::cin >> passUS;
  int diaUS;
  std::cout << "Escriba su dia de naciemiento" << std::endl;
  std::cin >> diaUS;
  int mesUS;
  std::cout << "Escriba su mes de naciemiento" << std::endl;
  std::cin >> mesUS;
  int anioUS;
  std::cout << "Escriba su anio de naciemiento" << std::endl;
  std::cin >> anioUS;
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

void ListarUsuarios()
{
  controladorUsuario->listarUsuarios();
}

/* LISTAR VENDEDORES
    for (auto it = vendedores.begin(); it != vendedores.end(); it++)
    {
      std::string nick = it->second->getNickname();
      DTFecha fecha = it->second->getFechaNacimiento();
      int dia = fecha.getDia();
      int mes = fecha.getMes();
      int anio = fecha.getAnio();
      std::string rut = it->second->getCodigoRUT();
      std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << ", Codigo RUT: " << rut;
      std::cout << std::endl;
    };
*/

void AltaDeProducto()
{
  std::string nickVendedor;
  controladorUsuario->listarVendedores();
  std::cin >> nickVendedor;
  std::string nombreProducto;
  std::cout << "Escriba el nombre del producto" << std::endl;
  std::getline(std::cin >> std::ws, nombreProducto);
  int precioProducto;
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
  controladorProducto->registrarDatosProductos(nombreProducto, precioProducto, stockProducto, descripcionProducto, categoriaProducto, 8);
}

int main()
{
  while (true)
  {
    int input = 0;
    std::cout << "Menu de Opciones" << std::endl
              << "1-Cargar datos iniciales" << std::endl
              << "2-Registrar nuevo usuario" << std::endl
              << "3-Listado de usuarios exitentes" << std::endl
              << "4-Alta de producto" << std::endl
              << "5-Consultar un producto" << std::endl
              << "6-Crear una nueva promocion" << std::endl
              << "7-Consultar una promocion" << std::endl
              << "8-Realizar una compra" << std::endl
              << "9-Dejar un comentario" << std::endl
              << "10-Eliminar un comentario" << std::endl
              << "11-Enviar un producto" << std::endl
              << "12-Expediente de usuario" << std::endl
              << "13-Consulta de notificaciones" << std::endl
              << "14-Suscribirse a notificacion" << std::endl
              << "15-Eliminar suscripcion" << std::endl
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

      break;

    case 6: // Crear una nueva promocion

      break;

    case 7: // Consultar una promocion

      break;

    case 8: // Realizar una compra

      break;

    case 9: // Dejar un comentario

      break;

    case 10: // Eliminar un comentario

      break;

    case 11: // Enviar un producto

      break;

    case 12: // Expediente de usuario

      break;

    case 13: // Consulta de notificaciones

      break;

    case 14: // Suscribirse a notificacion

      break;

    case 15: // Eliminar suscripcion

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