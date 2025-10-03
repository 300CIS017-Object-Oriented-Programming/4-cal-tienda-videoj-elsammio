#include <iostream>
#include "tienda.h"
using std::cout;
using std::cin;
using std::fixed;

int main() {
    int carritoCodigos[MAX_LINEAS]={0};
    int carritoCantidades[MAX_LINEAS]={0};
    int nCarrito=0;

    while(true){
        cout<<"\n=========== GameStore ===========\n";
        cout<<"1) Agregar juego\n2) Limpiar carrito\n3) Cargar demo\n4) Ver resumen y pagar\n5) Salir\n";
        int op; cin>>op;
        if(op==1) agregarJuegoAlCarrito(carritoCodigos,carritoCantidades,nCarrito);
        else if(op==2) limpiarCarrito(carritoCodigos,carritoCantidades,nCarrito);
        else if(op==3) cargarCompraDemo(carritoCodigos,carritoCantidades,nCarrito);
        else if(op==4){
            int tipo=leerTipoCliente();
            double pDesc=obtenerPorcentajeDescuento(tipo);
            mostrarResumenCompra(carritoCodigos,carritoCantidades,nCarrito,pDesc);
        }
        else if(op==5) {cout<<"Gracias, hasta luego!\n"; break;}
        else cout<<"Opcion invalida.\n";
    }
    return 0;
}