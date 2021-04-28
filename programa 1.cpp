//Taller 4
// proposito: Manejar nuestro programa bajo un menú dividido en funciones fisica y logicamente
// Autores: Santiago Castrillon - Duvier Reinosa Pelaez
//Fecha de creación: 13/04/2021


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//------------------------------------------------------------------------------------------------------------------------------------------
//macros

#define nroMotos 1000
#define anyoActual 2021
#define anyoMinimo 1867
//


using namespace std;
//-------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------
//constantes para imprimir por pantalla lo que eliió el usuario
const char* nColores [] = {"", "Negro","Azul", "Marron", "Gris", "Verde", "Naranja", "Rosa", "Purpura", 
							"Rojo", "Blanco", "Amarillo" };
const char* numTransmisiones [] = {"","Automatica", "Semiautomatica", "Manual"};
//-------------------------------------------------------------------------------------------------------------------------------------

int obtenerColor(int n){
	int t;
	scanf("%d", &t); 
	fflush(stdin);
	
	while(1 > t || t > 11){
		printf("\n                         Error: El valor Ingresado debe estar entre 1 y 11");
		printf("\n                         [%i]Color: ",n);  	
		scanf("%d", &t); 
		fflush(stdin);
	}
	return t;
}

int obtenerAnyo(int n){
	int t;
	scanf("%d", &t); 
	fflush(stdin);
	
	while(anyoMinimo > t || t > (anyoActual + 1)){
		printf("\n                         Error: El valor Ingresado debe estar entre %i y %i", anyoMinimo, (anyoActual + 1));
		printf("\n                         [%i]Anyo de fabricacion: ",n); 	
		scanf("%d", &t); 
		fflush(stdin);
	}
	return t;
}

int obtenerVelocidades(int n){
	int t;
	scanf("%d", &t); 
	fflush(stdin);
	
	while(4 > t || t > 6){
		printf("\n                         Error: El valor Ingresado debe estar entre 4 y 6");
		printf("\n                         [%i]Velocidades: ",n); 		
		scanf("%d", &t); 
		fflush(stdin);
	}
	return t;
}

int leerTransmision(int n){
	int t;
	
	scanf("%d", &t); 
	fflush(stdin);

	
	while(t<1 || t>3){
		printf("\n                         Error: El valor Ingresado debe estar entre 1 y 3");
		printf("\n                         [%i]Transmision: ",n); 
		scanf("%d", &t); 
		fflush(stdin);
	}
	return t;
}

int imprimirEstadistica(int automatica,int semiautomatica,int manual,int nNegro, int nAzul,int nMarron,int nGris,
						 int nVerde, int nNaranja, int nRosa, int nPurpura, int nRojo, int nBlanco, int nAmarillo){
			printf("\n--------------------------------Salida de datos--------------------------------\n");
			
			printf("\nLas Motos guardadas en nuestra base de datos son de Transmision:");
			printf("\n-Automaticas: %i", automatica);
			printf("\n-Semiautomaticas: %i", semiautomatica);
			printf("\n-Manuales: %i", manual);
			
			printf("\nLas Motos guardadas en nuestra base de datos son de color:");
			printf("\n-Negras: %i", nNegro);
			printf("\n-Azules: %i", nAzul);
			printf("\n-Marron: %i", nMarron);
			printf("\n-Grises: %i", nGris);
			printf("\n-Verdes: %i", nVerde);
			printf("\n-Naranjas: %i", nNaranja);
			printf("\n-Rosas: %i", nRosa);
			printf("\n-Purpuras: %i", nPurpura);
			printf("\n-Rojas: %i", nRojo);
			printf("\n-Blancas: %i", nBlanco);
			printf("\n-Amarillas: %i", nAmarillo);								
}

int imprimirDatos(char marcas [nroMotos][15], char modelos [nroMotos][15], char nMotors [nroMotos][10], char nChasises [nroMotos][12],
				int transmision[nroMotos], int velocidades[nroMotos], int cilindraje[nroMotos], int anyo[nroMotos], int color[nroMotos],
				float peso[nroMotos], int torque[nroMotos], float capacidadDelTanque[nroMotos], char& seguir, int& stateI, float& stateF,
				int& n){
			for(int i = 0; i < n; i++){
				printf("\n--------------------------------Salida de datos--------------------------------\n");
				printf("\n------------------------------------Moto %i--------------------------------\n", i);
				printf("\n                         Marca: %s \n", marcas[i]);
		    	printf("\n                         Modelo: %s \n", modelos[i]);
				printf("\n                         Numero De Motor: %s \n", nMotors[i]);
				printf("\n                         Numero de chasis: %s \n", nChasises[i]);
				printf("\n                         Transmision: %s \n", numTransmisiones[transmision[i]] );
				
				if(transmision[n] > 1){
					printf("\n                         Velocidades: %i \n", velocidades[i]);
				}
				printf("\n                         Cilindraje: %u Centimetros Cubicos\n", cilindraje[i]);
				printf("\n                         Anyo: %i \n", anyo[i]);
				printf("\n                         Color: %s \n", nColores[color[i]]);
				printf("\n                         Peso: %.2f Kg\n", peso[i]);
				printf("\n                         Torque: %i Revoluciones\n", torque[i]);
				printf("\n                         Capacidad del tanque: %.2f Galones\n", capacidadDelTanque[i]);
	} 

}

int entrarDatos(char marcas [nroMotos][15], char modelos [nroMotos][15], char nMotors [nroMotos][10], char nChasises [nroMotos][12],
				int transmision[nroMotos], int velocidades[nroMotos], int cilindraje[nroMotos], int anyo[nroMotos], int color[nroMotos],
				float peso[nroMotos], int torque[nroMotos], float capacidadDelTanque[nroMotos], char& seguir, int& stateI, float& stateF,
				int& n, int& automatica, int& semiautomatica, int& manual, int& nNegro, int& nAzul, int& nMarron, int& nGris, int& nVerde,
				int& nNaranja, int& nRosa, int& nPurpura, int& nRojo, int& nBlanco, int& nAmarillo)
	{
		while(toupper(seguir) == 'S')
		{
			system("cls");
			printf("\n--------------------------------Entrada de datos--------------------------------\n");
			printf("\n                         [%i]Marca: ", n); gets(marcas[n]); fflush(stdin); 
			printf("\n                         [%i]Modelo: ",n); gets(modelos[n]); fflush(stdin);
			printf("\n                         [%i]Numero de motor: ",n); gets(nMotors[n]); fflush(stdin);	
			printf("\n                         [%i]Numero de chasis: ",n); gets(nChasises[n]); fflush(stdin);
			printf("\n                            Tipo de transmision: ");
			printf("\n                            1.  Automatica");
			printf("\n                            2.  Semiautomatica");
			printf("\n                            3.  Manual");
			printf("\n                         [%i]Transmision: ",n); 
				transmision[n] = leerTransmision(n);
			switch (transmision[n])
    			{
    			case 1: automatica++; break;
			    case 2: semiautomatica++; break;
			    case 3: manual++; break;
			    }
			if(transmision[n] > 1){
				printf("\n                         [%i]Velocidades: ",n); 	
				velocidades[n] = obtenerVelocidades(n);
			}	
			printf("\n                         [%i]Cilindraje: ",n);
				scanf("%d", &stateI); 
				fflush(stdin);	
				cilindraje[n] = stateI;
			printf("\n                         [%i]Anyo de fabricacion: ",n); 
				anyo[n] = obtenerAnyo(n);
			printf("\n                            Colores");
			printf("\n                             1. Negro");
			printf("\n                             2. Azul");
			printf("\n                             3. Marron");
			printf("\n                             4. Gris");
			printf("\n                             5. Verde");
			printf("\n                             6. Naranja");
			printf("\n                             7. Rosa");
			printf("\n                             8. Purpura");
			printf("\n                             9. Rojo");
			printf("\n                             10. Blanco");
			printf("\n                             11. Amarillo");
			printf("\n                         [%i]Color: ",n); 
				color[n] = obtenerColor(n);
				
				switch (color[n])
				    {
				    case 1: nNegro++; break;
				    case 2: nAzul++; break;
				    case 3: nMarron++; break;
				    case 4: nGris++; break;
				    case 5: nVerde++; break;
				    case 6: nNaranja++; break;
				    case 7: nRosa++; break;
				    case 8: nPurpura++; break;
				    case 9: nRojo++; break;
				    case 10: nBlanco++; break;
				    case 11: nAmarillo++; break;
				    }
			printf("\n                         [%i]Peso: ",n); 
				scanf("%f", &stateF);
				fflush(stdin);
				peso[n] = stateF;
			printf("\n                         [%i]Torque: ",n); 
				scanf("%d", &stateI);
				fflush(stdin);
				torque[n] = stateI;
			printf("\n                         [%i]Capacidad del tanque: ",n); 
			scanf("%f", &stateF);
				fflush(stdin);
				capacidadDelTanque[n] = stateF;
			printf("\n                         ¿Deseas continuar?: (S/N)");
			seguir = getchar(); fflush(stdin); 
			n++;
	}
}

int menu (int indiceMenu){
	printf("\n--------------------------------Base de datos motos\n");
		printf("\n                                  Menu:\n");
		printf("\n                                  1. Entrar datos:");
		printf("\n                                  2. Imprimir datos:");
		printf("\n                                  3. Imprimir estadisticas:");
		printf("\n                                  4. Salir:\n");
		printf("\n                                     Opcion:");
				scanf("%i", &indiceMenu); 
				fflush(stdin);
		return indiceMenu;
	
}
							
int main (){
	
	int indiceMenu = 0;
//	--------------------------------------------------------------------------------------------------------------------------------------
//	matrices
		char marcas [nroMotos][15];
		char modelos [nroMotos][15];
		char nMotors [nroMotos][10];
		char nChasises [nroMotos][12];
//	----------------------------------------------------------------------------------------------------------------------------------------
		int transmision[nroMotos];
		int velocidades[nroMotos];
		int cilindraje[nroMotos];
		int anyo[nroMotos];
		int color[nroMotos];
		float peso[nroMotos];
		int torque[nroMotos];
		float capacidadDelTanque[nroMotos];
		char seguir = 'S';
		int n = 0;
		int stateI;
		float stateF;
//-----variables para estdisticas----------------------------------------------------------------------------------------------------------
		int automatica = 0;
		int semiautomatica = 0;
		int manual = 0;
		
		int nNegro = 0;
		int nAzul = 0;
		int nMarron = 0;
		int nGris = 0;
		int nVerde = 0;
		int nNaranja = 0;
		int nRosa = 0;
		int nPurpura = 0;
		int nRojo = 0;
		int nBlanco = 0;
		int nAmarillo = 0;
//--------------------------------------------------------------------------------------------------------------------------------

	
	while(indiceMenu < 4){

		indiceMenu = menu(indiceMenu);
				
		switch(indiceMenu){
			case 1 : if(n < nroMotos){
				entrarDatos(marcas, modelos, nMotors, nChasises, transmision, velocidades, cilindraje, anyo, color, peso, torque,
								capacidadDelTanque, seguir, stateI, stateF, n, automatica, semiautomatica, manual,
								nNegro, nAzul, nMarron, nGris, nVerde, nNaranja, nRosa, nPurpura, nRojo, nBlanco, nAmarillo);

			}else{
				printf("ERROR: Nuestra base de datos ha llegado a su limite, no puedes ingresar más datos");
			}
			
			
			break;
			case 2 : imprimirDatos(marcas, modelos, nMotors, nChasises, transmision, velocidades, cilindraje, anyo, color, peso, torque,
								capacidadDelTanque, seguir, stateI, stateF, n);
			break;
			case 3 : imprimirEstadistica(automatica, semiautomatica, manual,
								nNegro, nAzul, nMarron, nGris, nVerde, nNaranja, nRosa, nPurpura, nRojo, nBlanco, nAmarillo);
			break;
		}
	}
}
