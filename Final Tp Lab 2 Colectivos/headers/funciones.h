#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ENTER 13

bool gotoxyFlecha(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);

return true;
}


void OcultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}

/*void limites(){
recuadro(1, 1, 77, 33);
}
*/
void menuListarMicros(){
    cout << "-------------------------------------------------------------------------" << endl;
    cout << setiosflags(ios::left);
    cout << setw(15) << "Patente";
    cout << setw(15) << "Modelo";
    cout << setw(15) << "Asientos";
    cout << setw(15) << "Estado" << "\n";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
}

void menuListarChoferes(){
    cout << "-------------------------------------------------------------------------" << endl;
    cout << setiosflags(ios::left);
    cout << setw(15) << "DNI";
    cout << setw(15) << "Apellido";
    cout << setw(15) << "Nombres";
    cout << setw(15) << "Estado" << "\n";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
}

void menuListarViajes(){
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << setiosflags(ios::left);
    cout << setw(10) << "IDViaje";
    cout << setw(10) << "IDDestino";
    cout << setw(10) << "Destino";
    cout << setw(10) << "Costo";
    cout << setw(10) << "Patente";
    cout << setw(10) << "DNI";
    cout << setw(10) << "Fecha" << "\n";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
}

void menuListarUsiarios(){
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << setiosflags(ios::left);
    cout << setw(30) << "Nombre";
    cout << setw(30) << "Clave";
    cout << setw(30) << "Estado" << "\n";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
}

void menuListarPasajes(){

    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << setiosflags(ios::left);
    cout << setw(15) << "ID Ticket";
    cout << setw(15) << "ID Viaje";
    cout << setw(15) << "Destino";
    cout << setw(15) << "Cantidad";
    cout << setw(15) << "Importe" << "\n";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;


}

void menuListarDestinos(){
    cout << "-------------------------------------------------------------------------" << endl;
    //cout << endl;
    cout << setiosflags(ios::left);
    cout << setw(30) << "ID Destino";
    cout << setw(30) << "Destino";
    cout << setw(30) << "Estado" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    //cout << endl;
}

void borrarPantalla(void){
  //LINUX
  //system("clear");
  //WINDOWS
  system("cls");
}
void pausa(void){
  //LINUX
  cin.get();
  cin.get();
  //WINDOWS
  //system("pause >nul");
}

#include <windows.h>
enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};
void clrscr(void){
    system("cls");
}
void pause(void){
    system("pause >nul");
}
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

void recuadroSimple(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 196;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 179;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

bool esBisiesto(int anio){

bool bisiesto=false;


        if(anio % 4 == 0){
        bisiesto = true;

        if(anio % 100 == 0){
        bisiesto = false;

        if(anio % 400 == 0){
        bisiesto = true;
       }
     }
   }

  return bisiesto;
}


bool compruebaFecha(int dia, int mes, int anio ){

          if(dia<1 || mes<1 || anio<1)
            return false;
          if(mes > 12)
            return false;

          if(mes==2){
          if(esBisiesto(anio) && dia > 29)
            return false;

            else if(!esBisiesto(anio) && dia > 28)
            return false;
          }
          if(mes==2 && ((esBisiesto(anio) && dia > 29) || (!esBisiesto(anio) && dia > 28))) {
            return false;
          }

          if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            if(dia > 30)
            return false;
          }

          else{
            if(dia > 31)
            return false;
          }
            return true;

}






#endif // FUNCIONES_H_INCLUDED
