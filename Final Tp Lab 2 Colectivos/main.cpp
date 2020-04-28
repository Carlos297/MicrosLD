#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdio.h>


using namespace std;
#include "headers/funciones.h"
#include "headers/clases.h"
Fecha FECHA_SIS;
#include "headers/configuracion.h"
#include "headers/micros.h"
#include "headers/choferes.h"
#include "headers/destinos.h"
#include "headers/viajes.h"
#include "headers/usuarios.h"
#include "headers/log.h"
//#include "headers/destinos.h"
#include "headers/boletos.h"
#include "headers/reportes.h"



int progressbar();



int main()
{
    progressbar();
    clrscr();
    system("color 2D");
    cout << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
    cout<<"\t\t\t   COMPLETADO CON EXITO!!!\n" << endl << endl;
    cout << "\t\t\tBIENVENIDO A TRANSPORT SEEK!!" << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
    cout << "\t\tGESTION EMPRESA TRANSPORTE MEDIA Y LARGA DISTANCIA" << endl;
    cout << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
    system("pause");

    int opc;
    while(true){
    clrscr();
    // LECTURA FECHA //

    FECHA_SIS.leerDisco();


     textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);
    gotoxy(50,2);
    cout << FECHA_SIS.getDia()<<"/"<<FECHA_SIS.getMes()<<"/"<<FECHA_SIS.getAnio() << endl;


    gotoxy(10,3);
    cout << "MENU PRINCIPAL" << endl;
    gotoxy(10,4);
    cout << "------------------" << endl;
    gotoxy(10,5);
    cout << "1 - MICROS" << endl;
    gotoxy(10,6);
    cout << "2 - CHOFERES" << endl;
    gotoxy(10,7);
    cout << "3 - VIAJES" << endl;
    gotoxy(10,8);
    cout << "4 - DESTINOS" << endl;
    gotoxy(10,9);
    cout << "5 - BOLETOS" << endl;
    gotoxy(10,10);
    cout << "6 - USUARIOS" << endl;
    gotoxy(10,11);
    cout << "7 - CONFIGURACION" << endl;
    gotoxy(10,12);
    cout << "8 - REPORTES" << endl;
    //cout << "7 - CANTID DE VIAJES POR CHOFER" << endl;
    gotoxy(10,13);
    //cout << "9 - VIAJE MAYOR CANTIDAD PASAJEROS(NOM.CHO. PAT.COL.)" << endl;
    gotoxy(10,14);
    cout << "------------------" << endl;
    gotoxy(10,15);
    cout << "0) SALIR" << endl << endl;
    cout << endl;
    gotoxy(10,16);
    cout << "OPCION: ";

    cin >> opc;
cout << endl << endl << endl << endl << endl;
 switch(opc){
      case 1:
          menuMicros();
      break;
      case 2:
          menuChoferes();
      break;
      case 3:
          menuViajes();
      break;

      case 4:
          menuDestinos();
      break;
      case 5:
          menuPasajes();
      break;

      case 6:
          if(login()){
            menuUsuario();
          }else{
                gotoxy(21,12);
                cout << "NOMBRE DE USUARIO O CONTRASE" << char(165) << "A INVALIDAS!!" << endl;
                cout << endl;
                gotoxy(21,15);
                system("pause");
          }
      break;

      case 7:
          if(login()){
          menuConfiguracion();
          }else{
          gotoxy(21,12);
                cout << "NOMBRE DE USUARIO O CONTRASE" << char(165) << "A INVALIDAS!!" << endl;
                gotoxy(21,15);
                system("pause");
          }
      break;
      case 8:
            menuReporte();
      break;


      case 0:
      return 0;
      default : cout<<"Opcion Incorrecta.";
                system("pause > null");
      break;

    }
  }



    return 0;
}


int progressbar()
{
int segundos=5;
for(int i=0; i<=21; i++)
cout << "\n";
cout << "\t\t\t\t AGUARDE... CARGANDO...\n";
for(int i=0; i<=79; i++)
cout << "_";
for(int i=0; i<=79; i++)
{
cout<<char(219);
Sleep(segundos*1000/80);
}
return 0;
}




