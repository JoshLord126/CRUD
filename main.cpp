#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	char direccion[150];
	int telefono;
};
void buscar_codigo(){
	FILE* archivo = fopen(nombe_archivo,"r");	
	int cod=0;
	
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);	
	
	do{
		if(estudiante.codigo == cod){
			cout<<"Codigo: "<<estudiante.codigo<<endl;
			cout<<"Nombres: "<<estudiante.nombre<<endl;
			cout<<"Apellidos: "<<estudiante.apellido<<endl;
			cout<<"Telefono: "<<estudiante.telefono<<endl;
			cout<<"Direccion: "<<estudiante.direccion<<endl;
	   }
		fread(&estudiante,sizeof(Estudiante),1,archivo);	
	}while(feof(archivo)==0);
	
	fclose(archivo);
}
void mostrar_estudiante(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "r");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+");
	}
	
	Estudiante estudiante;
	int registro=0;
	
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<< "|id" <<"\t|"<< "CODIGO" <<"\t|"<< "NOMBRE"<<"\t\t|"<<"APELLIDO"<<"\t|"<<"TELEFONO"<<"\t|"<<"DIRECCION"<<endl;	
	cout<<"---------------------------------------------------------------------------------------------------"<<endl;
	
		do{
			if(estudiante.codigo != -1){
				cout << registro <<"\t|"<< estudiante.codigo <<"\t|"<< estudiante.nombre<<"\t|"<<estudiante.apellido<<"\t|"<<estudiante.telefono<<"\t|"<<estudiante.direccion<<endl;
			}
			fread ( &estudiante, sizeof(Estudiante), 1, archivo );
			registro += 1;	
		} while (feof( archivo ) == 0);
		
	fclose(archivo);
	}
void ingresar_estudiante(){
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "a");
	
	Estudiante estudiante;
	
	string nombre, apellido, direccion;
	char *p_nombre = new char[50];
	char *p_apellido = new char[50];
	char *p_direccion = new char[150];
	
	
	do{
		fflush(stdin);		
		cout<<"Ingrese el codigo: ";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el nombre: ";
		getline(cin,nombre);
		for(int i=0; i<=nombre.length(); i++){
			p_nombre[i] = nombre[i];
			estudiante.nombre[i] = p_nombre[i];
		}
		//strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el apellido: ";
		getline(cin,apellido);
		for(int i=0; i<=apellido.length(); i++){
			p_apellido[i] = apellido[i];
			estudiante.apellido[i] = p_apellido[i];
		}
		//strcpy(estudiante.apellido, apellido.c_str()); 
		        
        cout<<"Ingrese el telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
		
		cout<<"Ingrese la direccion: ";
		getline(cin,direccion);
		for(int i=0; i<=direccion.length(); i++){
			p_direccion[i] = direccion[i];
			estudiante.direccion[i] = p_direccion[i];
		}
		//strcpy(estudiante.direccion, direccion.c_str()); 
		
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	delete[] p_nombre;
	delete[] p_apellido;
	delete[] p_direccion;
	
	mostrar_estudiante();
}
void modificar_estudiante(){
	FILE* archivo = fopen(nombe_archivo, "r+");
	
	int id;
	string nombre,apellido, direccion;	
   	Estudiante estudiante;
    
	cout << "Ingrese el ID que desea Modificar: ";
    cin >> id;
	fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );
	
	cout<<"Ingrese el codigo: ";
	cin>>estudiante.codigo;
    cin.ignore();
       
	cout<<"Ingrese el nombre: ";
	getline(cin,nombre);
    strcpy(estudiante.nombre, nombre.c_str()); 
		
	cout<<"Ingrese el apellido: ";
	getline(cin,apellido);
	strcpy(estudiante.apellido, apellido.c_str()); 
		
	cout<<"Ingrese el telefono: ";
	cin>>estudiante.telefono;
	cin.ignore();
		
	cout<<"Ingrese la direccion: ";
	getline(cin,direccion);
	strcpy(estudiante.direccion, direccion.c_str()); 
		
	fwrite( &estudiante, sizeof(Estudiante), 1, archivo );	
	fclose(archivo);
	
	mostrar_estudiante();
	system("PAUSE");
}
void eliminar_estudiante(){
	FILE* archivo = fopen(nombe_archivo, "r+");
	int id;
	Estudiante estudiante;
	
	cout<<"Ingrese el ID del alumno que desea eliminar: ";
    cin>>id;
	
	fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );	
	estudiante.codigo = -1;
	fwrite( &estudiante, sizeof(Estudiante), 1, archivo );	
	fclose(archivo);
	
	mostrar_estudiante();
	system("PAUSE");
}
int main (){
	int op;
	char continuar;
	do{
		cout<<"Mostrar informacion..............1"<<endl;
		cout<<"Ingresar alumno..................2"<<endl;
		cout<<"Modificar alumno.................3"<<endl;
		cout<<"Buscar alumno....................4"<<endl;
		cout<<"Eliminar alumno..................5"<<endl<<endl<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>op;
		
		switch(op){
			case 1:
				mostrar_estudiante();
			break;
			case 2:
				ingresar_estudiante();
			break;
			case 3:
				mostrar_estudiante();
				modificar_estudiante();
			break;
			case 4:
				buscar_codigo();
			break;
			case 5:
				eliminar_estudiante();
			break;
		}
		
		cout<<"Desea continuar s/n : ";
		cin>>continuar;
		system("cls");
	} while((continuar=='s') || (continuar=='S'));
		
	return 0;	
}

