#ifndef MICROS_H_INCLUDED
#define MICROS_H_INCLUDED

int buscar_Micro(char *);
void alta_Micro();
void modifica_Micro();
void baja_logica_Micro();
void listar_Micro();


void menuMicros(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);

gotoxy(10,3);  cout<<"MENU MICROS";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) CARGAR MICRO";
gotoxy(10,6);  cout<<"2) EDITAR MICRO";
gotoxy(10,7);  cout<<"3) ELIMINAR MICRO";
gotoxy(10,8);  cout<<"4) LISTAR TODOS LOS MICROS";
gotoxy(10,9);  cout<<"---------------";
gotoxy(10,10); cout<<"0) VOLVER";
gotoxy(10,11); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: alta_Micro();
    break;
    case 2: modifica_Micro();
    break;
    case 3: baja_logica_Micro();
    break;
    case 4: listar_Micro();
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


bool Micros::Cargar()
	{
	int encontro;
	cout << "**  INFORMACION DEL MICRO **" << endl;
    cout << "________________________________" << endl;
    cout << endl;
	cout<<"Ingrese la patente (con mayusculas): ";
	cin>>patente;
	encontro=buscar_Micro(patente);
	if(encontro==-1)
	{
    cout<<"Ingrese el modelo:  ";
    cin>>modelo;
    if( modelo<1990){
            cout << "Anio incorrecto" << endl;
            system("pause");
            return false;
        }
    cout<<"Ingrese la cantidad de asientos:  ";
    cin>>cantasientos;
    if(cantasientos<0){
            cout << endl << endl;
            cout << "La cantidad de asientos debe ser positiva" << endl;
            system("pause");
            return false;
        }
    estado=1;
    return true;
	}
	else
	{
	  cout << endl << endl;
	  cout<<"Ya existeun micro con esa patente!!"<<endl;
	  cout << endl << endl;
	  cout<<"Presione una tecla para continuar";
	  system("pause>nul");
	  return false;

	  }
	}



int Micros::leerDisco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("headers/micros.dat","rb+");
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


	void Micros::ModificarDisco(int pos)
	{
	FILE *p;
	p=fopen("headers/micros.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}


	void Micros::Mostrar(){
    cout << setw(15) << patente;
    cout << setw(15) << modelo;
    cout << setw(15) << cantasientos;
    if(estado==1){cout << setw(15) << "ACTIVO" << "\n";
    }else{
    cout << setw(15) << "INACTIVO" << "\n";
    }
	}
void listar_Micro()
	{
	Micros reg;
	int pos=0;

	system("cls");
	menuListarMicros();
	while(reg.leerDisco(pos++)==1)
		{
		if(reg.getEstado()==1)
			{
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



void alta_Micro()
{
	Micros reg;
	system("cls");
	if(reg.Cargar()){
    reg.grabarDisco();
    cout << endl << endl << endl;
	cout<<"El registro se Grabo con Exito"<<endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");
	}

}


int buscar_Micro(char *cod)
{
	int pos=0;
	Micros reg;
	while(reg.leerDisco(pos)==1)
		{
		if(strcmp(cod,reg.getPatente())==0 && reg.getEstado()==1)
			return pos;
		    pos++;
		}
	return -1;
}

void baja_logica_Micro()
{
	char cod[20];
	int pos;
	Micros reg;
	system("cls");
	cout<<"Ingrese la patente del micro a eliminar:";
	cin>>cod;
	pos=buscar_Micro(cod);
	if(pos!=-1)
		{
		reg.leerDisco(pos);
		reg.setEstado(false);
		reg.ModificarDisco(pos);
		cout << endl << endl;
		cout<<"El micro se elimino con exito!"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
	else
		{
        cout << endl << endl;
		cout<<"No existe el micro"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}

}

void modifica_Micro()
{
	char pat[10];
	int modelo;
	int cantasientos;
	int pos;
	Micros reg;
	system("cls");
	cout<<"Ingrese la patente del micro a modificar:";
	cin>>pat;
	pos=buscar_Micro(pat);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo modelo: ";
		cin>>modelo;

		cout<<"Ingrese la nueva cantidad de asientos: ";
		cin>>cantasientos;



		reg.leerDisco(pos);
		reg.setModelo(modelo);
		reg.setCantasientos(cantasientos);
		reg.ModificarDisco(pos);
		cout << endl << endl << endl << endl;
		cout << "El micro se modifico con exito!!" << endl;
		system("pause");
		}
	else
		{
        cout << endl << endl;
		cout<<"No existe la patente "<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
}


#endif // MICROS_H_INCLUDED
