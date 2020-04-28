#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED
bool login();



bool login (){

char nombreUsuario[20], clave[20];

clrscr();

textcolor(0,0);
        clrscr();
        recuadro(17, 6, 48, 11, cVERDE_CLARO, cMAGENTA);
        recuadro(19, 7, 44, 9, cBLANCO, cNEGRO);
        textcolor(cBLANCO, cNEGRO);
        gotoxy(21,8);
        cout << "INGRESE NOMBRE DE USUARIO: ";
        cin >> nombreUsuario;
        gotoxy(21,9);
        cout << "INGRESE CLAVE: ";
        cin >> clave;

        cout << endl;
        //gotoxy(21,10);

        //encontro = buscar_Usuario(nombreUsuario);
        //gotoxy(21,9);

                int pos=0;
                Usuarios reg;
                while(reg.leerDisco(pos++)==1)
                    {
                    if(strcmp(nombreUsuario,reg.getNomusuario())==0 && strcmp(clave,reg.getClave())==0 && reg.getEstado()==1)
                        return true;

                    }
                return false;


}


#endif // LOG_H_INCLUDED
