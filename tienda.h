//
// Created by samir.diaz on 29/08/2025.
//

#ifndef INC_4_CAL_TIENDA_VIDEOJ_ELSAMMIO_TIENDA_H
#define INC_4_CAL_TIENDA_VIDEOJ_ELSAMMIO_TIENDA_H
#include <string>
using namespace std;

/* ====================== CONFIGURACIÓN / CATÁLOGO ======================= */
const int N_JUEGOS = 12;

// Catálogo
extern const int    CAT_CODIGOS[N_JUEGOS];
extern const string CAT_NOMBRES[N_JUEGOS];
extern const int    CAT_PRECIOS[N_JUEGOS];
extern const string CAT_PLATAFORMA[N_JUEGOS];
extern const string CAT_CATEGORIA[N_JUEGOS];

// Descuentos
const double DESC_ORO   = 0.15;
const double DESC_PLATA = 0.08;
const double DESC_REG   = 0.00;
const double DESC_SWITCH     = 0.05;
const double DESC_ESTRATEGIA = 0.07;

// Límites del carrito
const int MAX_LINEAS   = 20;
const int MAX_UNIDADES = 30;

/* ====================== PROTOTIPOS ========================= */
void   mostrarCatalogoJuegos();
int    leerCodigoJuego();
int    leerCantidadJuegos();
string obtenerNombreJuego(int codigoJuego);
int    obtenerPrecioJuego(int codigoJuego);
string obtenerPlataforma(int codigoJuego);
string obtenerCategoria(int codigoJuego);
void   agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
int    leerTipoCliente();
double obtenerPorcentajeDescuento(int tipoCliente);
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);
void   mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);
void   cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
void   limpiarCarrito(int codigos[], int cantidades[], int& n);

#endif //INC_4_CAL_TIENDA_VIDEOJ_ELSAMMIO_TIENDA_H