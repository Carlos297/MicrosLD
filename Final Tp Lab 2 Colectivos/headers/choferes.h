#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED

int buscar_Chofer(int);
void alta_Chofer();
void modifica_Chofer();
void baja_logica_Chofer();
void listar_Chofer();

void menuChoferes(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);

gotoxy(10,3);  cout<<"MENU CHOFERES";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) CARGAR CHOFER";
gotoxy(10,6);  cout<<"2) EDITAR CHOFER";
gotoxy(10,7);  cout<<"3) ELIMINAR CHOFER";
gotoxy(10,8);  cout<<"4) LISTAR TODOS LOS CHOFERES";
gotoxy(10,9);  cout<<"---------------";
gotoxy(10,10); cout<<"0) VOLVER";
gotoxy(10,11); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: alta_Chofer();
    break;
    case 2: modifica_Chofer();
    break;
    case 3: baja_logica_Chofer();
    break;
    case 4: listar_Chofer();
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




bool Choferes::Cargar()
	{
	int encontro;
	cout << "**  INFORMACION DEL CHOFER **" << endl;
    cout << "________________________________" << endl;
    cout << endl;
	cout<<"Ingrese el DNI: ";
	cin>>dni;
	encontro=buscar_Chofer(dni);
	if(dni<0){
            cout << endl << endl;
            cout << "El numero de DNI debe ser positivo" << endl;
            system("pause");
            return false;

	}
	if(encontro==-1)
	{
    cout<<"Ingrese el Apellido:  ";
    cin>>apellido;
    cout<<"Ingrese el nombre:  ";
    cin>>nombre;

    estado=1;
    return true;
	}
	else
	{
      cout << endl << endl;
	  cout<<"Ya existe un chofer con ese dni";
	  cout << endl << endl;
	  cout<<"Presione una tecla para continuar";
	  system("pause>nul");
	  return false;

	  }
	}

int Choferes::leerDisco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("headers/choferes.dat","rb");
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


int buscar_Chofer(int dni)
{
	int pos=0;
	Choferes reg;
	while(reg.leerDisco(pos)==1)
		{
		if(dni == reg.getdni() && reg.getEstado()==1)
			return pos;
		pos++;
		}
	return -1;
}

void alta_Chofer()
{
	Choferes reg;
	system("cls");
	if(reg.Cargar()==true){
    reg.grabarDisco();
    cout << endl << endl << endl;
	cout<<"El registro se Grabo con Exito"<<endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");
	}

}

void Choferes::Mostrar(){
    cout << setw(15) << dni;
    cout << setw(15) << apellido;
    cout << setw(15) << nombre;
    cout << setw(15) << "ACTIVO" << "\n";
}

void listar_Chofer()
	{
	Choferes reg;
	int pos=0;

	system("cls");
	menuListarChoferes();
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



void modifica_Chofer()
{
	char nombre[30];
	char apellido[30];
	int dni;
	int pos;
	Choferes reg;
	system("cls");
	cout<<"Ingrese el dni del chofer a modificar: ";
	cin>>dni;
	pos=buscar_Chofer(dni);
	if(pos!=-1)
		{

		cout<<"Ingrese el nuevo nombre: ";
		cin>>nombre;

		cout<<"Ingrese el nuevo apellido: ";
		cin>>apellido;



		reg.leerDisco(pos);
		//reg.setdni(dni);
		reg.setNombre(nombre);
		reg.setApellido(apellido);
		reg.ModificarDisco(pos);
		}
	else
		{
        cout << endl << endl;
		cout<<"No existe el chofer "<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
}


void Choferes::ModificarDisco(int pos)
	{
	FILE *p;
	p=fopen("headers/choferes.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}


void baja_logica_Chofer()
{
	int dni;
	int pos;
	Choferes reg;
	system("cls");
	cout<<"Ingrese el dni del chofer a eliminar: ";
	cin>>dni;
	pos=buscar_Chofer(dni);
	if(pos!=-1)
		{
		reg.leerDisco(pos);
		reg.setEstado(0);
		reg.ModificarDisco(pos);
		cout << endl << endl;
		cout<<"El chofer se elimino con exito!"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
	else
		{
        cout << endl << endl;
		cout<<"No existe el chofer ingresado"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}

}

#endif // CHOFERES_H_INCLUDED
