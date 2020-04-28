#ifndef DESTINOS_H_INCLUDED
#define DESTINOS_H_INCLUDED

int buscar_Destino(int);
void alta_Destino();
void modifica_Destino();
void baja_logica_Destino();
void listar_Destino();


void menuDestinos(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);

gotoxy(10,3);  cout<<"MENU DESTINOS";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) CARGAR DESTINO";
gotoxy(10,6);  cout<<"2) LISTAR TODOS LOS DESTINOS";
gotoxy(10,7);  cout<<"3) EDITAR DESTINO";
gotoxy(10,8);  cout<<"4) ELIMINAR DESTINO";
gotoxy(10,9);  cout<<"---------------";
gotoxy(10,10); cout<<"0) VOLVER";
gotoxy(10,11); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: alta_Destino();
    break;
    case 2: listar_Destino();
    break;
    case 3: modifica_Destino();
    break;
    case 4: baja_logica_Destino();
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


bool Destinos::Cargar()
	{
	int encontro;

	cout << "**  INFORMACION DEL DESTINO **" << endl;
    cout << "________________________________" << endl;
    cout << endl;

	cout<<"Ingrese el ID del Destino: ";
	cin>>coddestino;

	if(coddestino<0){
    cout << endl << endl;
    cout<<"El ID del Destino deve ser un numero mayor a cero!!"<<endl;
    cout << endl << endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");
    return false;
    }


	if ((coddestino <= 0) || (coddestino > 500)){
        cout << endl << endl;
        cout << "DESTINO INVALIDO, INGRESE UN NUMERO ENTRE 1 Y 500. " << endl;
        cout << endl << endl;
        cout<<"Presione una tecla para continuar";
        system("pause>nul");
        return false;
          }


	encontro=buscar_Destino(coddestino);

	if(encontro>=0)
	{
      cout << endl << endl;
	  cout<<"Ya existe un Destino con ese Codigo!!!";
	  cout << endl << endl;
	  cout<<"Presione una tecla para continuar";
	  system("pause>nul");
	  return false;
	}


	cout << "Ingrese el Nombre: ";
	cin.ignore();
    cin.getline(nombredest, 20);
	//cin >> nombredest;

estado=1;

return true;

}


int Destinos::leerDisco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("headers/destinos.dat","rb");
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


int buscar_Destino(int coddest)
{
	int pos=0;
	Destinos reg;
	while(reg.leerDisco(pos)==1)
		{
		if(coddest == reg.getCoddestino() && reg.getEstado()==1)
			return pos;
		    pos++;
		}
return -1;
}


void alta_Destino()
{
	Destinos reg;
	system("cls");
	if (reg.Cargar()==true){
    reg.grabarDisco();
    cout << endl << endl << endl;
	cout<<"El registro se Grabo con Exito"<<endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");}

}

void Destinos::Mostrar(){
    cout << setw(30) << coddestino;
    cout << setw(30) << nombredest;
    cout << setw(30) << "ACTIVO" << "\n";
}



void listar_Destino()
	{
	Destinos reg;
	int pos=0;

	system("cls");
	menuListarDestinos();
	while(reg.leerDisco(pos++)==1)
		{
		    if(reg.getEstado()==1){
                cout << endl;
                reg.Mostrar();
		    }

		}
		system("pause>nul");
	if(pos==1)
		{
		cout<<"No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
	}


void modifica_Destino()
{
    char nombredest[10];
	//float costo;
	//int iddest;
	int coddest;
	int pos;
	Destinos reg;
	system("cls");
	cout<<"Ingrese el codigo del Destino a modificar: ";
	cin>>coddest;
	pos=buscar_Destino(coddest);
	if(pos!=-1)
		{
        cout<<"Ingrese el nuevo nombre del Destino: ";
		cin>>nombredest;

		reg.leerDisco(pos);
		reg.setNombredest(nombredest);
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

void Destinos::ModificarDisco(int pos)
	{
	FILE *p;
	p=fopen("headers/destinos.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

void baja_logica_Destino()
{
	int coddest;
	int pos;
	Destinos reg;
	system("cls");
	cout<<"Ingrese el ID del Destino a eliminar: ";
	cin>>coddest;
	pos=buscar_Destino(coddest);
	if(pos!=-1)
		{
		reg.leerDisco(pos);
		reg.setEstado(0);
		reg.ModificarDisco(pos);
		cout << endl << endl;
		cout<<"El Destino se elimino con exito!"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
	else
		{
        cout << endl << endl;
		cout<<"No Destino el chofer ingresado"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}

}


#endif // DESTINOS_H_INCLUDED
