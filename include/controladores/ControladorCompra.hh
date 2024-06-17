#ifndef CONTROLADOR_COMPRA
#define CONTROLADOR_COMPRA

#include "../datatypes/DTFecha.hh"
#include "../Compra.hh"
#include <set>
#include <iostream>
#include "../interfaces/IControladorCompra.hh"

class ControladorCompra {
    private:
        std::set<Compra*> comprasExitosas;
        Compra *compraActual;
    public:
        void crearCompra(int,int,int); // dia/mes/anio de hoy
        void asignarCliente(std::string);
        void agregarProductoACompra(int,int);
        void obtenerDatosCompra();
        void registrarCompraExitosa();
};

#endif