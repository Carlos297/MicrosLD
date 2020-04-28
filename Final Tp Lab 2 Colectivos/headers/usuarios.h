#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

int buscar_Usuario(char *);
void alta_Usuario();
void modifica_Usuario();
void baja_logica_Usuario();
void listar_Usuario();


void menuUsuario(){
int opc;
while(true){
textcolor(0,0);
        clrscr();
        recuadro(6, 0, 42, 18, cVERDE_CLARO, cMAGENTA);
        recuadro(8, 1, 38, 16, cBLANCO, cCIAN);
        textcolor(cBLANCO, cCIAN);

gotoxy(50,2);
cout << FECHA_SIS.getDia()<<"/"<<FECHA_SIS.getMes()<<"/"<<FECHA_SIS.getAnio() << endl;
gotoxy(50,4);



gotoxy(10,3);  cout<<"MENU USUARIOS";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) CARGAR USUARIOS";
gotoxy(10,6);  cout<<"2) CAMBIAR CLAVE";
gotoxy(10,7);  cout<<"3) ELIMINAR USUARIO";
gotoxy(10,8);  cout<<"4) LISTAR TODOS LOS USUARIOS";
gotoxy(10,9);  cout<<"---------------";
gotoxy(10,10); cout<<"0) VOLVER";
gotoxy(10,11); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: alta_Usuario();
    break;
    case 2: modifica_Usuario();
    break;
    case 3: baja_logica_Usuario();
    break;
    case 4: listar_Usuario();
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


bool Usuarios::Cargar()
	{
	int encontro;
	cout << "**  INFORMACION DEL USUARIO **" << endl;
    cout << "________________________________" << endl;
    cout << endl;
	cout<<"Ingrese el nombre: ";
	cin>>nomusuario;
	encontro=buscar_Usuario(nomusuario);
	if(encontro==-1)
	{


    cout<<"Ingrese la clave:  ";
    cin>>clave;

    estado=1;
    return true;
	}
	else
	{
	  cout << endl << endl << endl;
	  cout<<"Ya existe ese usuario" << endl;
	  cout<<"Presione una tecla para continuar";
	  system("pause>nul");
	  return false;

	  }
	}



int Usuarios::leerDisco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("headers/usuarios.dat","rb");
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


	void Usuarios::ModificarDisco(int pos)
	{
	FILE *p;
	p=fopen("headers/usuarios.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}


	void Usuarios::Mostrar(){
    cout << setw(30) << nomusuario;
    cout << setw(30) << clave;
    cout << setw(30) << "ACTIVO" << "\n";
}

void listar_Usuario()
	{
	Usuarios reg;
	int pos=0;

	system("cls");
	menuListarUsiarios();
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



void alta_Usuario()
{
	Usuarios reg;
	system("cls");
	if(reg.Cargar()==true){
    reg.grabarDisco();
    cout << endl << endl << endl;
	cout<<"El registro se Grabo con Exito"<<endl;
    cout<<"Presione una tecla para continuar";
    system("pause>nul");}

}


int buscar_Usuario(char *nom)
{
	int pos=0;
	Usuarios reg;
	while(reg.leerDisco(pos)==1)
		{
		if(strcmp(nom,reg.getNomusuario())==0 && reg.getEstado()==1)
			return pos;
		pos++;
		}
	return -1;
}


void baja_logica_Usuario()
{
	char nom[30];
	int pos;
	Usuarios reg;
	system("cls");
	cout<<"Ingrese el nombre del usuario a eliminar: ";
	cin>>nom;
	pos=buscar_Usuario(nom);
	if(pos!=-1)
		{
		reg.leerDisco(pos);
		reg.setEstado(0);
		reg.ModificarDisco(pos);
		cout << endl << endl;
		cout<<"El usuario se elimino con exito!"<<endl;
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

void modifica_Usuario()
{
	//char nom[30];
	char clave[30];
	int pos;
	Usuarios reg;
	system("cls");
	cout<<"Ingrese el nombre del usuario a modificar:";
	cin>>clave;
	pos=buscar_Usuario(clave);
	if(pos!=-1)
		{


		cout<<"Ingrese la nueva clave: ";
		cin>>clave;



		reg.leerDisco(pos);
		//reg.setNomusuario(nom);
		reg.setClave(clave);
		reg.ModificarDisco(pos);
		cout<<"La Clave se modifico con exito!!"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
	else
		{
        cout << endl << endl;
		cout<<"No existe el usuario ingresado o fue dado de baja"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
}


#endif // USUARIOS_H_INCLUDED
