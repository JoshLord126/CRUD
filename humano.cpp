#include "alumno.cpp"
#include <iostream>
using namespace std;

class Humano : Alumno{
	
	private: char h_nom[50], h_ape[50], h_dir[150];
		int h_tel;		
	
	public : 
		Humano(){
		}
		Humano(int codigo, char nombre[50], char apellido[50], char direccion[150], int telefono): Alumno(codigo){
			for(int i=0; i<150; i++){
				if(i<50){
					h_nom[i] = nombre[i];
					h_ape[i] = apellido[i];
				}
				h_dir[i] = direccion[i];
			}
			h_tel = telefono;
		}
};
