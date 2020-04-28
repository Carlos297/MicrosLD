#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void muestraMicrosBaja(void);

void cantidadViajeschofer(void);
int contarViajesxchofer(int);


void cantidadPasajxviaje();
int contarPasajeros(int);


void menuReporte(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);

gotoxy(10,3);  cout<<"MENU REPORTES";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) LISTAR MICROS ELIMINADOS";
gotoxy(10,6);  cout<<"2) CANTIDAD DE VIAJES POR CHOFER";
gotoxy(10,7);  cout<<"3) CANT DE PASAJEROS POR VIAJE";
gotoxy(10,8);  cout<<"---------------";
gotoxy(10,9);  cout<<"0) VOLVER";
gotoxy(10,10); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: muestraMicrosBaja();
    break;
    case 2: cantidadViajeschofer();
    break;
    case 3: cantidadPasajxviaje();
    break;
    case 0: system ("cls");return;
    break;
    default:
    gotoxy(13,17);
    textcolor(cROJO_CLARO);
    cout<<"* OPCION INCORRECTA *";
    pausa();
    break;
    }
}
}

void muestraMicrosBaja()
	{
	Micros reg;
	int pos=0;

	system("cls");
	menuListarMicros();

	while(reg.leerDisco(pos++)){
		if(reg.getEstado()==false){
            cout << endl;
            reg.Mostrar();
            }
     }

    system("pause>nul");
	}



int contarViajesxchofer(int dni){
int cont=0, pos=0;

Viajes reg;

while(reg.leerDisco(pos++)){
    if(dni == reg.getdni()){

        cont ++;
    }

}
return cont;

}


void cantidadViajeschofer(){
  clrscr();
  int pos = 0;
  Choferes reg;

  while(reg.leerDisco(pos++)){

         cout << "--------------------------------" << endl;
         cout << "DNI                         : " << reg.getdni() << endl;
         cout << "NOMBRE                      : " << reg.getNombre() << endl;
         cout << "APELLIDO                    : " << reg.getApellido() << endl;
         cout << "CANTIDAD DE VIAJES          : " << contarViajesxchofer(reg.getdni()) << endl;
         cout << "--------------------------------" << endl;

         cout << endl;

}
system("pause");

}





void cantidadPasajxviaje(){
clrscr();
Viajes obj;
int pos=0;


while(obj.leerDisco(pos++)==1){ //solo busca una!!!!!!!!

         cout << "--------------------------------" << endl;
         cout << "ID DE VIAJE                 : " << obj.getCodviaje() << endl;
         cout << "ID DE DESTINO               : " << obj.getCoddestino() << endl;
         cout << "CANTIDAD DE PASAJEROS       : " << contarPasajeros(obj.getCodviaje()) << endl;
         cout << "--------------------------------" << endl;

         cout << endl;


        }


        system("pause");

}



int contarPasajeros(int viaje){

Pasajes obj;
int pos=0;
float total=0;


while(obj.leerDisco(pos++)){ //solo busca una!!!!!!!!
        if(obj.getCodviaje()== viaje){
        total += obj.getCantboletos();
        }

        }
        return total;

}

#endif // REPORTES_H_INCLUDED
