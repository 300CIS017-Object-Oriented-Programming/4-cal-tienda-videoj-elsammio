[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/is4wfVCZ)
# Enunciado: Sistema de Gestión para Tienda de Videojuegos "GameStore"

## Descripción General
Desarrollar un sistema de gestión para una tienda de videojuegos que permita realizar ventas, aplicar promociones según el tipo de cliente y generar reportes básicos de ventas.

## Requisitos Funcionales

### 1. Catálogo de Productos
- Manejar al menos 4 categorías de videojuegos (Acción, Aventura, Deportes, Estrategia)
- Cada categoría debe tener al menos 3 juegos con precios diferentes
- Los juegos deben tener código, nombre, precio y plataforma (PS5, Xbox, PC, Switch)

### 2. Sistema de Ventas
- Permitir seleccionar juegos para añadir a un carrito de compras
- Manejar cantidades de cada juego
- Actualizar cantidades si se añade un juego ya existente en el carrito
- Mostrar lista de juegos en el carrito con sus precios individuales y subtotales

### 3. Sistema de Descuentos
- Implementar 3 tipos de clientes con diferentes descuentos:
  - Miembro Oro (15% descuento)
  - Miembro Plata (8% descuento)
  - Cliente Regular (0% descuento)
- Aplicar descuentos adicionales para juegos de ciertas plataformas o categorías

### 4. Funcionalidades Adicionales
- Función para limpiar el carrito actual
- Opción para cargar una compra de demostración
- Calcular y mostrar totales con y sin descuentos
- Validar que no se pueda exceder un límite máximo de ítems en el carrito

## Funciones Mínimas Requeridas

```cpp
void mostrarCatalogoJuegos();
int leerCodigoJuego();
int leerCantidadJuegos();
string obtenerNombreJuego(int codigoJuego);
int obtenerPrecioJuego(int codigoJuego);
string obtenerPlataforma(int codigoJuego);
string obtenerCategoria(int codigoJuego);
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
int leerTipoCliente();
double obtenerPorcentajeDescuento(int tipoCliente);
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);
void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);
void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
```

## Restricciones
- Utilizar arreglos para almacenar los productos y cantidades
- Definir constantes para precios y descuentos
- Implementar validaciones para entradas del usuario
- Usar funciones modulares con parámetros y valores de retorno apropiados
- Aplicar el mismo estilo de comentarios y documentación que en el proyecto TecnoCafé

Este ejercicio tiene una complejidad equivalente al sistema de café, pero introduce elementos nuevos como categorías adicionales de productos, plataformas y un sistema de descuentos más complejo que requiere lógica adicional.

Puede ver el ejemplo del caso de ejercicio del cafe en : https://github.com/lufe089/cpp_familiaridad_ejercicio_cafe

> Haga multiples commits al repositorio para evidenciar el avance del desarrollo del proyecto, haga push cuando desee publicar lo que ha hecho. Puede hacer múltiples veces push 
Este ejercicio permitirá desarrollar en usted un mayor nivel de familiaridad con la codificacion en el lenguaje C++

>NO olvide agregar el archivo .gitignore