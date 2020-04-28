#ifndef BOLETOS_H_INCLUDED
#define BOLETOS_H_INCLUDED

void alta_Pasaje();
void listar_Pasajes();
bool listar_PasajePorId();


int contarRegPasaje();
Viajes recuperarRegistroviaje(int);
Micros recuperarRegistrocolectivo(char*);
int pasajesVendidos(int);
bool verFechas(int,int,int);
float recuperarCosto(int);



void menuPasajes(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);
        gotoxy(50,2);
        cout << FECHA_SIS.getDia()<<"/"<<FECHA_SIS.getMes()<<"/"<<FECHA_SIS.getAnio() << endl;

gotoxy(10,3);  cout<<"MENU BOLETOS";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) COMPRAR BOLETOS";
gotoxy(10,6);  cout<<"2) LISTAR TODOS LOS BOLETOS";
gotoxy(10,7);  cout<<"3) LISTAR BOLETO POR ID DE TICKET";
gotoxy(10,8);  cout<<"---------------";
gotoxy(10,9); cout<<"0) VOLVER";
gotoxy(10,10); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: alta_Pasaje();
    break;
    case 2: listar_Pasajes();
    break;
    case 3: //listar_PasajePorId();
    if(listar_PasajePorId()==false){
        cout << endl << endl << endl;
        cout<<"NO EXISTE UN TICKET CON ESE ID" << endl;
        cout<<"Presione una tecla para continuar";
        system("pause>nul");
    }
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

bool Pasajes::Cargar()
	{
	int pos;
    Pasajes reg;
    Viajes p;
	cout << "**  INFORMACION DEL BOLETO **" << endl;
    cout << "________________________________" << endl;
    cout << endl;

	cout << "ID TICKET : " << (contarRegPasaje())+1 << endl;
    codboleto = (contarRegPasaje())+1;


	cout<<"Ingrese el Codigo de Viaje: ";
	cin>>codviaje;

	pos = buscar_Viaje(codviaje);

	if(pos<0){

        cout << endl << endl;
        cout<<"NO EXISTE UN VIAJE CARGADO CON ESE ID" << endl;
        cout << endl << endl;
        cout<<"Presione una tecla para continuar";
        system("pause>nul");
        return false;
	}

	///lo siguiente sirve para validar que sea una viaje vigente(anterior a la fecha del sitema)


	p = recuperarRegistroviaje(codviaje);

    if(verFechas(p.getFechaviaje().getDia(),p.getFechaviaje().getMes(),p.getFechaviaje().getAnio())==false){

        cout << endl << endl << endl << endl;
        cout<<"El viaje ingresado no esta vigente, ya se realizo!!!"<<endl;
        system("pause");
        return false;
    }


cout << "CANTIDAD DE PASAJES: ";
cin >> cantboletos;

if(cantboletos<=0){

    cout<<"La cantidad de pasajes debe ser un num entero positivo."<<endl;
    system("pause");
    return false;
}


Viajes v;
v = recuperarRegistroviaje(codviaje);


Micros c;
c = recuperarRegistrocolectivo(v.getPatente());



int aux = pasajesVendidos(codviaje);


/*cout << aux;
system("pause");*/


if (c.getCantasientos() - (cantboletos + aux) < 0){
    cout << endl << endl << endl;
    cout << "No alcanzan los asientos del Micro!!" << endl;
    system("pause");
    return false;
}

total = recuperarCosto(codviaje) * cantboletos;


return true;
}


int contarRegPasaje(){
int i=0 , pos=0;
Pasajes reg;
while(reg.leerDisco(pos++)==1){
    i++;
}

return i;
}


Viajes recuperarRegistroviaje(int viaje){
  int pos=0;
  Viajes reg;
  while(reg.leerDisco(pos++)){
   if(viaje == reg.getCodviaje()){

        return reg;

    }

  }
}


bool verFechas(int dia,int mes,int anio){

        if(anio>=FECHA_SIS.getAnio()){
            if(mes>=FECHA_SIS.getMes()){
                if(dia>=FECHA_SIS.getDia()){
                    return true;
                }else{
                        return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
}



Micros recuperarRegistrocolectivo(char* patente){

  Micros reg;
  int pos=0;


  while(reg.leerDisco(pos++)==1){
   if(strcmp(reg.getPatente(), patente)==0){

        return reg;
    }
  }

}

int Pasajes::leerDisco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("headers/pasajes.dat","rb");
	if(p==NULL)
		{
		cout<<"No existe el archivo";
		cout<<"Presione una tecla para continuar";
        system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

int pasajesVendidos(int viaje){
  int aux=0;
  int pos=0;

  Pasajes reg;
  while(reg.leerDisco(pos++)==1){
   if(viaje == reg.getCodviaje()){
        aux+=reg.getCantboletos();
    }
  }

return aux;

}


void alta_Pasaje()
{
	Pasajes reg;
	system("cls");
	if (reg.Cargar()==true){
    reg.grabarDisco();
    cout << endl << endl << endl;
	cout<<"El registro se Grabo con Exito"<<endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");}

}


void Pasajes::Mostrar(){
    Destinos p;
    int cod;
    cout << setw(15) << codboleto;
    cout << setw(15) << codviaje;

    cod = buscarCodigodeDestino(codviaje);
    p = buscarNomDestino(cod);
    cout << setw(15) << p.getNombredest();
    cout << setw(15) << cantboletos<<"$";
    cout << setw(15) << total;
    cout << setw(15)  << "\n";
}


void listar_Pasajes()
	{
	Pasajes reg;
	int pos=0;

	system("cls");
	menuListarPasajes();
	while(reg.leerDisco(pos++)==1)
		{   cout << endl;
            reg.Mostrar();
		}
		system("pause>nul");
	if(pos==1)
		{
		cout<<"No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
	}


float recuperarCosto(int viaje){
  int pos=0;
  Viajes reg;
  while(reg.leerDisco(pos++)==1){
   if(viaje == reg.getCodviaje()){
        return reg.getCosto();

    }
  }

}


bool listar_PasajePorId(){
clrscr();
Pasajes reg;
int IDpasaje, pos=0;
cout<<"INGRESE EL ID DEL PASAJE: ";
cin>>IDpasaje;
//Búsqueda del registro en el archivo
while(reg.leerDisco(pos++)==1){
        if (IDpasaje==reg.getCodboleto()){
         cout << "--------------------------------" << endl;
         cout << "ID TICKET              : " << reg.getCodboleto() << endl;
         cout << "ID VIAJE               : " << reg.getCodviaje() << endl;
         cout << "CANTIDAD DE PASAJES    : " << reg.getCantboletos() << endl;
         cout << "IMPORTE                : " <<"$"<<reg.getTotal() << endl;
         cout << "--------------------------------" << endl;
         system("pause");
         return true;
        }

}
        return false;

}





#endif // BOLETOS_H_INCLUDED
