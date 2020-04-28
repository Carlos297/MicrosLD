#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void altaFecha();
void listarFecha();

bool recuperarRegistro();
bool altaRegchofer(int);
bool altaRegcolectivo(char *);

void menuConfiguracion(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);
gotoxy(50,2);
cout << FECHA_SIS.getDia()<<"/"<<FECHA_SIS.getMes()<<"/"<<FECHA_SIS.getAnio() << endl;


gotoxy(10,3);  cout<<"MENU CONFIGURACION";
gotoxy(10,4);  cout<<"----------------------------";
gotoxy(10,5);  cout<<"1) CAMBIAR FECHA DEL SISTEMA";
gotoxy(10,6);  cout<<"2) RECUPERAR REGISTROS";
gotoxy(10,7);  cout<<"----------------------------";
gotoxy(10,8); cout<<"0) VOLVER";
gotoxy(10,9); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: altaFecha();
    break;
    case 2: recuperarRegistro();
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



void altaFecha(){
system("cls");
if(FECHA_SIS.Cargar()==true){
FECHA_SIS.grabarDisco();
cout << endl << endl;
cout <<"La fecha se cargo con exito!!" << endl;
system("pause");
}
else{
cout << endl << endl << endl;
cout <<"Fecha Incoherente!!" << endl;
system("pause");
}

}


void Fecha::grabarDisco(){
FILE *p;
p = fopen("archivos/fechaSistema.dat", "wb");
    if(p==NULL){cout<<"ERROR ARCHIVO FECHA"; exit(1);}
fwrite(this, sizeof *this, 1, p);
fclose(p);
}

void Fecha::Mostrar(){
cout << dia << "/" << mes << "/" << anio;
}

int Fecha::leerDisco(){
int x;
FILE *p;
p = fopen("archivos/fechaSistema.dat", "rb");
    if(p == NULL){cout << "ERROR DE ARCHIVO FECHA"; exit(1);}
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

void listarFecha(){
Fecha obj;
while(obj.leerDisco()){
    obj.Mostrar();
}
}

bool recuperarRegistro(){
clrscr();
int codent,dni;
char patente[20];


cout << "( 1. DNI CHOFER       )" << endl;
cout << "( 2. PATENTE MICRO   )" << endl;
cout << endl;
cout << "INGRESE EL CODIGO DE ENTIDAD A RECUPERAR: ";

cin>>codent;

if(codent==1){

    cout<<"Ingrese el DNI del chofer: ";
    cin>>dni;

    if(altaRegchofer(dni)==true){
        cout << endl << endl << endl;
        cout <<"Se dio de alta al chofer con exito!!"<<endl;
        system("pause");
        return true;
    }else{
        cout << endl << endl << endl;
        cout <<"No se encontro el chofer!!"<<endl;
        system("pause");
        return false;
    }

}
else{
    if (codent==2){

    cout<<"Ingrese la patente: ";
    cin>>patente;

    if(altaRegcolectivo(patente)==true){
        cout << endl << endl << endl;
        cout <<"Se dio de alta al Micro con exito!!"<<endl;
        system("pause");
        return true;
    }else {
            cout << endl << endl << endl;
            cout <<"No se encontro al Micro!!"<<endl;
            system("pause");
            return false;
    }

}

}
return false;
}



bool altaRegchofer(int dni){
  int pos=0;
  Choferes reg;
  while(reg.leerDisco(pos)){
   if(dni == reg.getdni()){

        reg.setEstado(true);
        reg.ModificarDisco(pos);
        return true;
    }
    //i++;
    //return false;
    pos ++;
  }
    //return false;
}


bool altaRegcolectivo(char * patente){
  int pos=0;
  Micros reg;

  while(reg.leerDisco(pos)){
  if(strcmp(reg.getPatente(),patente)==0){

        reg.setEstado(true);
        reg.ModificarDisco(pos);
        return true;
    }
    //i++;
    //return false;
    pos ++;
  }

}

#endif // CONFIGURACION_H_INCLUDED
