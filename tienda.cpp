//
// Created by samir.diaz on 29/08/2025.
//

#include "tienda.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/* ====================== DATOS DEL CATALOGO ======================= */
const int    CAT_CODIGOS[N_JUEGOS]   = {100,101,102, 110,111,112, 120,121,122, 130,131,132};
const string CAT_NOMBRES[N_JUEGOS]   = {
    "Shadow Assault", "Cyber Fray", "Neon Hunt",
    "Jungle Quest", "Crystal Shores", "Echoes of Ruins",
    "Ultimate Soccer 25", "Pro Hoops 25", "Street Tennis Pro",
    "Empire Forge", "Galactic Tactics", "Kingdoms & Castles"
};
const int    CAT_PRECIOS[N_JUEGOS]   = {
    249000, 229000, 199000,
    179000, 259000, 209000,
    199000, 219000, 169000,
    239000, 249000, 189000
};
const string CAT_PLATAFORMA[N_JUEGOS]= {
    "PS5","Xbox","PC",
    "Switch","PS5","PC",
    "Xbox","PS5","Switch",
    "PC","Xbox","Switch"
};
const string CAT_CATEGORIA[N_JUEGOS] = {
    "Accion","Accion","Accion",
    "Aventura","Aventura","Aventura",
    "Deportes","Deportes","Deportes",
    "Estrategia","Estrategia","Estrategia"
};

/* ====================== HELPERS ======================= */
int indexPorCodigo(int codigo) {
    for (int i = 0; i < N_JUEGOS; ++i)
        if (CAT_CODIGOS[i] == codigo) return i;
    return -1;
}

int totalUnidadesEnCarrito(const int cantidades[], int n) {
    int t = 0;
    for (int i = 0; i < n; ++i) t += cantidades[i];
    return t;
}

/* ====================== IMPLEMENTACIONES ======================= */
void mostrarCatalogoJuegos() {
    cout << "\n================= CATALOGO GAMESTORE =================\n";
    cout << left << setw(8) << "Codigo" << setw(24) << "Nombre" << setw(12) << "Plataforma"
         << setw(14) << "Categoria" << right << setw(10) << "Precio\n";
    cout << string(70, '-') << "\n";
    for (int i = 0; i < N_JUEGOS; ++i) {
        cout << left << setw(8)  << CAT_CODIGOS[i]
             << setw(24) << CAT_NOMBRES[i].substr(0,23)
             << setw(12) << CAT_PLATAFORMA[i]
             << setw(14) << CAT_CATEGORIA[i]
             << right << setw(10) << CAT_PRECIOS[i] << "\n";
    }
    cout << string(70, '-') << "\n";
}

int leerCodigoJuego() {
    while (true) {
        cout << "Ingresa el codigo del juego (0 para cancelar): ";
        int codigo;
        if (!(cin >> codigo)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida.\n";
            continue;
        }
        if (codigo == 0) return 0;
        if (indexPorCodigo(codigo) == -1) {
            cout << "Codigo no existente.\n";
            continue;
        }
        return codigo;
    }
}

int leerCantidadJuegos() {
    while (true) {
        cout << "Cantidad (1-10): ";
        int cant;
        if (!(cin >> cant)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida.\n";
            continue;
        }
        if (cant < 1 || cant > 10) {
            cout << "Fuera de rango.\n";
            continue;
        }
        return cant;
    }
}

string obtenerNombreJuego(int codigoJuego) {
    int idx = indexPorCodigo(codigoJuego);
    return (idx >= 0 ? CAT_NOMBRES[idx] : "Desconocido");
}

int obtenerPrecioJuego(int codigoJuego) {
    int idx = indexPorCodigo(codigoJuego);
    return (idx >= 0 ? CAT_PRECIOS[idx] : 0);
}

string obtenerPlataforma(int codigoJuego) {
    int idx = indexPorCodigo(codigoJuego);
    return (idx >= 0 ? CAT_PLATAFORMA[idx] : "-");
}

string obtenerCategoria(int codigoJuego) {
    int idx = indexPorCodigo(codigoJuego);
    return (idx >= 0 ? CAT_CATEGORIA[idx] : "-");
}

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& n) {
    mostrarCatalogoJuegos();
    int codigo = leerCodigoJuego();
    if (codigo == 0) return;
    int cantidad = leerCantidadJuegos();

    if (totalUnidadesEnCarrito(cantidades, n) + cantidad > MAX_UNIDADES) {
        cout << "Supera el maximo permitido.\n"; return;
    }
    for (int i=0;i<n;i++) {
        if (codigos[i]==codigo) { cantidades[i]+=cantidad; return; }
    }
    if (n>=MAX_LINEAS) { cout<<"Carrito lleno.\n"; return; }
    codigos[n]=codigo; cantidades[n]=cantidad; n++;
}

double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int n) {
    double subtotal=0;
    for (int i=0;i<n;i++) subtotal+=obtenerPrecioJuego(codigos[i])*cantidades[i];
    return subtotal;
}

int leerTipoCliente() {
    cout << "\nTipo de cliente:\n1) Oro\n2) Plata\n3) Regular\n";
    int t;
    while (true){
        cout<<"Selecciona 1-3: ";
        if(!(cin>>t)){cin.clear();cin.ignore(9999,'\n');continue;}
        if(t>=1 && t<=3) return t;
    }
}

double obtenerPorcentajeDescuento(int tipoCliente) {
    if (tipoCliente==1) return DESC_ORO;
    if (tipoCliente==2) return DESC_PLATA;
    return DESC_REG;
}

double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int n) {
    double desc=0;
    for(int i=0;i<n;i++){
        if (obtenerPlataforma(codigos[i])=="Switch")
            desc += obtenerPrecioJuego(codigos[i])*cantidades[i]*DESC_SWITCH;
        if (obtenerCategoria(codigos[i])=="Estrategia")
            desc += obtenerPrecioJuego(codigos[i])*cantidades[i]*DESC_ESTRATEGIA;
    }
    return desc;
}

double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales) {
    double descCliente=subtotal*porcentajeDescuento;
    double total=subtotal-descCliente-descuentosAdicionales;
    return (total<0?0:total);
}

void mostrarResumenCompra(const int codigos[], const int cantidades[], int n, double pDesc) {
    if(n==0){cout<<"Carrito vacio.\n";return;}
    cout<<"\n===== RESUMEN DE COMPRA =====\n";
    for(int i=0;i<n;i++){
        cout<<obtenerNombreJuego(codigos[i])<<" x"<<cantidades[i]
            <<" = "<<obtenerPrecioJuego(codigos[i])*cantidades[i]<<"\n";
    }
    double subtotal=calcularSubtotalCarrito(codigos,cantidades,n);
    double descCliente=subtotal*pDesc;
    double descAdic=calcularDescuentosAdicionales(codigos,cantidades,n);
    double total=calcularTotalFinal(subtotal,pDesc,descAdic);
    cout<<"Subtotal: "<<subtotal<<"\n";
    cout<<"Desc Cliente: -"<<descCliente<<"\n";
    cout<<"Desc Adic: -"<<descAdic<<"\n";
    cout<<"TOTAL: "<<total<<"\n";
}

void cargarCompraDemo(int codigos[], int cantidades[], int& n) {
    int demoCods[4]={100,112,122,130};
    int demoCants[4]={1,1,2,1};
    for(int i=0;i<4;i++){codigos[i]=demoCods[i];cantidades[i]=demoCants[i];}
    n=4;
}

void limpiarCarrito(int codigos[], int cantidades[], int& n){
    for(int i=0;i<n;i++){codigos[i]=0;cantidades[i]=0;}
    n=0;
}