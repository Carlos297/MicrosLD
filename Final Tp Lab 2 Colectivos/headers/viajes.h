#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED

int buscar_Viaje(int);
void alta_Viaje();
void modifica_Viaje();
void listar_Viaje();


int buscarCodigodeDestino(int);

Destinos buscarNomDestino(int);



bool verFechasr(int,int,int);


void menuViajes(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);
        gotoxy(50,2);
        cout << FECHA_SIS.getDia()<<"/"<<FECHA_SIS.getMes()<<"/"<<FECHA_SIS.getAnio() << endl;

gotoxy(10,3);  cout<<"MENU VIAJES";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) CARGAR VIAJES";
gotoxy(10,6);  cout<<"2) LISTAR TODOS LOS VIAJES";
gotoxy(10,7);  cout<<"3) EDITAR VIAJES";
gotoxy(10,8);  cout<<"---------------";
gotoxy(10,9); cout<<"0) VOLVER";
gotoxy(10,10); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: alta_Viaje();
    break;
    case 2: listar_Viaje();
    break;
    case 3: modifica_Viaje();
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


bool Viajes::Cargar()
	{
	int encontro ,pos1, pos2;
	cout << "**  INFORMACION DEL VIAJE **" << endl;
    cout << "________________________________" << endl;
    cout << endl;
	cout<<"Ingrese el Codigo de Viaje: ";
	cin>>codviaje;

	if(codviaje<0){
    cout << endl << endl;
    cout<<"El ID de Viaje deve ser un numero mayor a cero."<<endl;
    cout << endl << endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");
    return false;
    }

	encontro=buscar_Viaje(codviaje);
	if(encontro>=0)
	{
      cout << endl << endl;
	  cout<<"Ya existe un Viaje con ese Codigo!!";
	  cout << endl << endl;
	  cout<<"Presione una tecla para continuar";
	  system("pause");
	  return false;
	}



	cout << "ID DESTINO: ";

    cin>>coddestino;

    if ((buscar_Destino(coddestino))<0){
        cout << endl << endl;
        cout << "DESTINO INEXISTENTE!!" << endl;
        cout << endl << endl;
        cout<<"Presione una tecla para continuar";
        system("pause>nul");
        return false;
          }


    //cout << "NOMBRE DEL DESTINO: ";
    //cin >> nombredest;


    cout << "Fecha del Viaje: " << endl;
    if(fechaviaje.Cargar()==false){
        cout << endl << endl;
        cout<<"Fecha incoherente.." << endl;
        cout << endl << endl;
        cout<<"Presione una tecla para continuar";
        system("pause>nul");
        return false;
    }


    if(verFechasr(fechaviaje.getDia(),fechaviaje.getMes(),fechaviaje.getAnio())==false){

        cout << endl << endl;

        cout<<"Ingrese Fecha Viaje Posterior a Fecha Sistema!!!.." << endl;
        cout << endl << endl;
        cout<<"Presione una tecla para continuar";
        system("pause>nul");
        return false;
    }



    cout << "COSTO: $";
    cin >> costo;
    if(costo<0){
        cout << endl << endl;
        cout<<"El costo del viaje deve ser mayor a cero" << endl;
        cout << endl << endl;
        cout<<"Presione una tecla para continuar";
        system("pause>nul");
        return false;
    }
    cout << "PATENTE (con mayusculas): ";
    cin >> patente;

  pos1 = buscar_Micro(patente);



  if (pos1 < 0){
    cout << endl << endl;
    cout << "NO EXISTE MICRO CON DICHA PATENTE O ESTA DADO DE BAJA" << endl;
    cout << endl << endl;
    system("pause");
    return false;
  }


    cout << "NUMERO DE DNI DE CHOFER: ";
    cin >> dni;
    pos2 = buscar_Chofer(dni);
    if (pos2 < 0){
    cout << endl << endl;
    cout << "NO EXISTE CHOFER CON DICHA PATENTE O ESTA DADO DE BAJA" << endl;
    cout << endl << endl;
    system("pause");
    return false;
  }


return true;


}

int Viajes::leerDisco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("headers/viajes.dat","rb");
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





int buscar_Viaje(int codvia)
{
	int pos=0;
	Viajes reg;
	while(reg.leerDisco(pos)==1)
		{
		if(codvia == reg.getCodviaje())
			return pos;
		    pos++;
		}
return -1;
}


void alta_Viaje()
{
	Viajes reg;
	system("cls");
	if (reg.Cargar()==true){
    reg.grabarDisco();
    cout << endl << endl << endl;
	cout<<"El registro se Grabo con Exito"<<endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");}

}


int buscarCodigodeDestino(int codviaje){
Viajes reg;
int pos=0;
while(reg.leerDisco(pos++)==1){
    if (reg.getCodviaje() == codviaje){

            return reg.getCoddestino();

    }


}


}


Destinos buscarNomDestino(int coddest){
Destinos reg;
int pos=0;
while(reg.leerDisco(pos++)==1){
    if (reg.getCoddestino() == coddest){

            return reg;

    }


}


}

void Viajes::Mostrar(){
    Destinos p;
    cout << setw(10) << codviaje;
    cout << setw(10) << coddestino;
    p = buscarNomDestino(coddestino);
    cout << setw(10) << p.getNombredest() <<"$";
    cout << setw(10) << costo;
    cout << setw(10) << patente;
    cout << setw(10) << dni <<fechaviaje.getDia()<<"/"<<fechaviaje.getMes()<<"/"<<fechaviaje.getAnio();
    cout << setw(10)  << "\n";
}


void listar_Viaje()
	{
	Viajes reg;
	int pos=0;

	system("cls");
	menuListarViajes();
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



void modifica_Viaje()
{
    char nombredest[10];
	float costo;
	int iddest;
	int codvia;
	int pos;
	Viajes reg;
	system("cls");
	cout<<"Ingrese el codigo del viaje a modificar: ";
	cin>>codvia;
	pos=buscar_Viaje(codvia);
	if(pos!=-1)
		{

		cout<<"Ingrese el nuevo id de destino: ";
		cin>>iddest;

        cout<<"Ingrese el nuevo costo: ";
		cin>>costo;


		reg.leerDisco(pos);
		reg.setCoddestino(iddest);
		reg.setCosto(costo);
		reg.ModificarDisco(pos);

		cout << endl << endl;
		cout<<"El viaje se modifico con exito!"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
	else
		{
        cout << endl << endl;
		cout<<"No existe el viaje "<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");

		}
}


void Viajes::ModificarDisco(int pos)
	{
	FILE *p;
	p=fopen("headers/viajes.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}




bool verFechasr(int dia,int mes,int anio){

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
#endif // VIAJES_H_INCLUDED
