#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

class Fecha{
  private:
    int dia,mes, anio;
  public:
    /*Fecha(int d=0, int m=0, int a=0){
      dia=d;
      mes=m;
      anio=a;
      }
      */
    void Mostrar();
    bool Cargar(){
    cout << "DIA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "ANIO: ";
    cin >> anio;
    if(compruebaFecha(dia,mes,anio)==true){

        return true;
    }
    else{
        return false;
    }

    }
    void grabarDisco();
    int leerDisco();
    //////// GETS //////////
    int getDia (){return dia;}
    int getMes (){return mes;}
    int getAnio (){return anio;}
    //////// SETS //////////
    void setDia(int DiaN){DiaN=dia;}
    void setMes(int MesN){MesN=mes;}
    void setAnio(int AnioN){AnioN=anio;}

  };


class Micros{
private:
    char patente[20];
    int modelo;
    int cantasientos;
    bool estado;

public:
    bool Cargar();
    void Mostrar();
    void grabarDisco();
    int leerDisco(int);
    void ModificarDisco(int);
    //////// GETS //////////
    char *getPatente(){return patente;}
    int getModelo(){return modelo;}
    int getCantasientos(){return cantasientos;}
    bool getEstado(){return estado;}
    //////// SETS //////////
    void setPatente(char *_patente){strcpy(patente,_patente);}
    void setModelo(int _modelo){modelo = _modelo;}
    void setCantasientos(int _cantasientos){cantasientos = _cantasientos;}
    void setEstado(bool _estado){estado = _estado;}
};

class Choferes{
private:
    int dni;
    char apellido[20];
    char nombre[20];
    Fecha fechanac;
    bool estado;

public:
    bool Cargar();
    void Mostrar();
    void grabarDisco();
    int leerDisco(int);
    void ModificarDisco(int);
    //////// GETS //////////
    int getdni(){return dni;}
    char *getApellido(){return apellido;}
    char *getNombre(){return nombre;}
    Fecha getFechanac(){return fechanac;}
    bool getEstado(){return estado;}
    //////// SETS //////////+
    void setdni(int _dni){dni = _dni;}
    void setApellido(char *_apellido){strcpy(apellido,_apellido);}
    void setNombre(char * _Nombre){strcpy(nombre,_Nombre);}
    void setFechanac(Fecha _fechanac){fechanac = _fechanac;}
    void setEstado(bool _estado){estado = _estado;}
};

class Viajes{
private:
    int codviaje;
    int coddestino;
    //char nombredest[10];
    char patente[10];
    int dni;
    Fecha fechaviaje;
    float costo;

public:
    bool Cargar();
    void Mostrar();
    void grabarDisco();
    int leerDisco(int);
    void ModificarDisco(int);
    //////// GETS //////////
    int getCodviaje(){return codviaje;}
    //char *getNombredest(){return nombredest;}
    int getCoddestino(){return coddestino;}
    char *getPatente(){return patente;}
    int getdni(){return dni;}
    Fecha getFechaviaje(){return fechaviaje;}
    float getCosto(){return costo;}
    //////// SETS //////////
    void setCodviaje(int _codviaje){codviaje = _codviaje;}
    //void setNombredest(char * _nombredest){strcpy(nombredest,_nombredest);}
    void setCoddestino(int _coddestino){coddestino =_coddestino;}
    void setPatente(char *_patente){strcpy(patente,_patente);}
    void setdni(int _dni){dni = _dni;}
    void setCosto(float _costo){costo = _costo;}
};

class Destinos{
private:

    int coddestino;
    char nombredest[10];
    bool estado;

public:
    bool Cargar();
    void Mostrar();
    void grabarDisco();
    int leerDisco(int);
    void ModificarDisco(int);

    ///////gets////////
    char *getNombredest(){return nombredest;}
    int getCoddestino(){return coddestino;}
    bool getEstado(){return estado;}
    //////////////sets/////////////
    void setNombredest(char * _nombredest){strcpy(nombredest,_nombredest);}
    void setCoddestino(int _coddestino){coddestino =_coddestino;}
    void setEstado(int _estado){estado =_estado;}

};

class Pasajes{
  private:
    int codboleto;
    int codviaje;
    int cantboletos;
    float total;

  public:
    void Mostrar();
    bool Cargar();
    void grabarDisco();
    int leerDisco(int);
    void ModificarDisco(int);
    //////// GETS //////////
    int getCodboleto (){return codboleto;}
    int getCodviaje (){return codviaje;}
    int getCantboletos (){return cantboletos;}
    float getTotal (){return total;}
    //////// SETS //////////
    void setCodboleto(int _codboleto){codboleto = _codboleto;}
    void setCodviaje(int _codviaje){codviaje =_codviaje;}
    void setCantboletos(int _cantboletos){cantboletos = _cantboletos;}
    void setTotal(float _total){total = _total;}
  };

class Usuarios{
private:
    char nomusuario[20];
    char clave[20];
    Fecha fechacreacion;
    bool estado;

public:
    bool Cargar();
    void Mostrar();
    void grabarDisco();
    int leerDisco(int);
    void ModificarDisco(int);
    //////// GETS //////////
    char *getNomusuario(){return nomusuario;}
    char *getClave(){return clave;}
    Fecha getFechaCreacion(){return fechacreacion;}
    bool getEstado(){return estado;}
    //////// SETS //////////
    void setNomusuario(char *_nomusuario){strcpy(nomusuario,_nomusuario);}
    void setClave(char * _clave){strcpy(clave,_clave);}
    void setFechacreacion(Fecha _fechacreacion){fechacreacion = _fechacreacion;}
    void setEstado(bool _estado){estado = _estado;}
};



void Micros::grabarDisco(void)
	{
	FILE *p;
	p=fopen("headers/micros.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

void Choferes::grabarDisco(void)
	{
	FILE *p;
	p=fopen("headers/choferes.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

void Viajes::grabarDisco(void)
	{
	FILE *p;
	p=fopen("headers/viajes.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}


void Usuarios::grabarDisco(void)
	{
	FILE *p;
	p=fopen("headers/usuarios.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

void Pasajes::grabarDisco(void)
	{
	FILE *p;
	p=fopen("headers/pasajes.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}


void Destinos::grabarDisco(void)
	{
	FILE *p;
	p=fopen("headers/destinos.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

#endif // CLASES_H_INCLUDED
