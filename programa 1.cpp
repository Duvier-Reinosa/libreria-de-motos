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
//estructuras
typedef struct vehiculo	{
		char marca[15];
		char modelo[15];
		char nMotor[10];
		char nChasise[12];

		int transmision;
		int velocidades;
		int cilindraje;
		int anyo;
		int color;
		float peso;
		int torque;
		float capacidadDelTanque;
		vehiculo *dir;
	
};

typedef struct datos{
		int automatica ;
		int semiautomatica ;
		int manual ;
		
		int nNegro ;
		int nAzul ;
		int nMarron ;
		int nGris ;
		int nVerde ;
		int nNaranja ;
		int nRosa ;
		int nPurpura ;
		int nRojo ;
		int nBlanco ;
		int nAmarillo ;
};

//
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

//int ordenarDatos(int orden[nroMotos], char marcas [nroMotos][15], int& n){
//	int aux;
//
//	
//	for(int i = 0; i < n; i++){
//		for(int j = i + 1; j < n; j++){
//			char a = marcas[i][0];
//			char b = marcas[j][0];
//			if(a > b){
//				aux = orden[i];
//				orden[i] = orden[j];
//				orden[j] = aux;
//			}
//		}
//	}
//			printf("\n                                                Datos ordenados!");
//}

int imprimirEstadistica(datos *estadisticas){
			printf("\n--------------------------------Salida de estadisticas--------------------------------\n");
			
			printf("\n                         Las Motos guardadas en nuestra base de datos son de Transmision:");
			printf("\n                         -Automaticas: %i", estadisticas->automatica);
			printf("\n                         -Semiautomaticas: %i", estadisticas->semiautomatica);
			printf("\n                         -Manuales: %i", estadisticas->manual);
			
			printf("\n\n--------------------------------Las Motos guardadas en nuestra base de datos son de color:");
			printf("\n                         -Negras: %i", estadisticas->nNegro);
			printf("\n                         -Azules: %i", estadisticas->nAzul);
			printf("\n                         -Marron: %i", estadisticas->nMarron);
			printf("\n                         -Grises: %i", estadisticas->nGris);
			printf("\n                         -Verdes: %i", estadisticas->nVerde);
			printf("\n                         -Naranjas: %i", estadisticas->nNaranja);
			printf("\n                         -Rosas: %i", estadisticas->nRosa);
			printf("\n                         -Purpuras: %i", estadisticas->nPurpura);
			printf("\n                         -Rojas: %i", estadisticas->nRojo);
			printf("\n                         -Blancas: %i", estadisticas->nBlanco);
			printf("\n                         -Amarillas: %i", estadisticas->nAmarillo);								
}

int imprimirDatos(int& n, vehiculo *moto){
  		while(moto){
				printf("\n--------------------------------Salida de datos--------------------------------\n");
//				printf("\n------------------------------------Moto %i--------------------------------\n", i);
				printf("\n                         Marca: %s \n", moto->marca);
		    	printf("\n                         Modelo: %s \n", moto->modelo);
				printf("\n                         Numero De Motor: %s \n", moto->nMotor);
				printf("\n                         Numero de chasis: %s \n", moto->nChasise);
				printf("\n                         Transmision: %s \n", numTransmisiones[moto->transmision] );
				
				if(moto->transmision > 1){
					printf("\n                         Velocidades: %i \n", moto->velocidades);
				}
				printf("\n                         Cilindraje: %u Centimetros Cubicos\n", moto->cilindraje);
				printf("\n                         Anyo: %i \n", moto->anyo);
				printf("\n                         Color: %s \n", nColores[moto->color]);
				printf("\n                         Peso: %.2f Kg\n", moto->peso);
				printf("\n                         Torque: %i Revoluciones\n", moto->torque);
				printf("\n                         Capacidad del tanque: %.2f Galones\n", moto->capacidadDelTanque);
  				moto = moto->dir;
  }
	


}

int entrarDatos(vehiculo *moto, vehiculo *mAux, char& seguir, int& stateI, float& stateF,int& n, datos *estadisticas){
		
			system("cls");
			printf("\n--------------------------------Entrada de datos--------------------------------\n");
			printf("\n                         [%i]Marca: ", n); gets(moto->marca); fflush(stdin); 
			printf("\n                         [%i]Modelo: ",n); gets(moto->modelo); fflush(stdin);
			printf("\n                         [%i]Numero de motor: ",n); gets(moto->nMotor); fflush(stdin);	
			printf("\n                         [%i]Numero de chasis: ",n); gets(moto->nChasise); fflush(stdin);
			printf("\n                            Tipo de transmision: ");
			printf("\n                            1.  Automatica");
			printf("\n                            2.  Semiautomatica");
			printf("\n                            3.  Manual");
			printf("\n                         [%i]Transmision: ",n); 	moto->transmision = leerTransmision(n);
			switch (moto->transmision)
    			{
    			case 1: estadisticas->automatica++; break;
			    case 2: estadisticas->semiautomatica++; break;
			    case 3: estadisticas->manual++; break;
			    }
			if(moto->transmision > 1){
				printf("\n                         [%i]Velocidades: ",n); 	
				moto->velocidades = obtenerVelocidades(n);
			}	
			printf("\n                         [%i]Cilindraje: ",n);
				scanf("%d", &stateI); 
				fflush(stdin);	
				moto->cilindraje = stateI;
			printf("\n                         [%i]Anyo de fabricacion: ",n); 
				moto->anyo = obtenerAnyo(n);
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
			printf("\n                         [%i]Color: ",n); moto->color = obtenerColor(n);
				
				switch (moto->color)
				    {
				    case 1: estadisticas->nNegro++; break;
				    case 2: estadisticas->nAzul++; break;
				    case 3: estadisticas->nMarron++; break;
				    case 4: estadisticas->nGris++; break;
				    case 5: estadisticas->nVerde++; break;
				    case 6: estadisticas->nNaranja++; break;
				    case 7: estadisticas->nRosa++; break;
				    case 8: estadisticas->nPurpura++; break;
				    case 9: estadisticas->nRojo++; break;
				    case 10: estadisticas->nBlanco++; break;
				    case 11: estadisticas->nAmarillo++; break;
				    }
			printf("\n                         [%i]Peso: ",n); 
				scanf("%f", &stateF);
				fflush(stdin);
				moto->peso = stateF;
			printf("\n                         [%i]Torque: ",n); 
				scanf("%d", &stateI);
				fflush(stdin);
				moto->torque = stateI;
			printf("\n                         [%i]Capacidad del tanque: ",n); 
			scanf("%f", &stateF);
				fflush(stdin);
				moto->capacidadDelTanque = stateF;
			printf("\n                         ¿Deseas continuar?: (S/N)");
			seguir = getchar(); fflush(stdin); 
			n++;
	
}

int menu (int indiceMenu){
	printf("\n--------------------------------Base de datos motos\n");
		printf("\n                                  Menu:\n");
		printf("\n                                  1. Entrar datos:");
		printf("\n                                  2. Imprimir datos:");
		printf("\n                                  3. Imprimir estadisticas:");
		printf("\n                                  4. Ordenar datos:");
		printf("\n                                  5. Salir:\n");
		printf("\n                                     Opcion:");
				scanf("%i", &indiceMenu); 
				fflush(stdin);
		return indiceMenu;
	
}
							
int main (){
	
	int indiceMenu = 0;
	
	vehiculo *moto = NULL;
	vehiculo *mAux = NULL;
	datos *estadisticas = (datos *) malloc(sizeof(datos));
		estadisticas->automatica = 0;
		estadisticas->semiautomatica = 0;
		estadisticas->manual = 0;
		
		estadisticas->nNegro = 0;
		estadisticas->nAzul = 0;
		estadisticas->nMarron = 0;
		estadisticas->nGris = 0;
		estadisticas->nVerde = 0;
		estadisticas->nNaranja = 0;
		estadisticas->nRosa = 0;
		estadisticas->nPurpura = 0;
		estadisticas->nRojo = 0;
		estadisticas->nBlanco = 0;
		estadisticas->nAmarillo = 0;

	char seguir = 'S';
	int n = 0;
	int stateI;
	float stateF;


	while(indiceMenu < 5){

		indiceMenu = menu(indiceMenu);
				
		switch(indiceMenu){
			case 1 : while(toupper(seguir) == 'S'){
							moto = (vehiculo *) malloc(sizeof(vehiculo));
							printf("%i", &moto);
							entrarDatos(moto, mAux, seguir, stateI, stateF, n, estadisticas);
							moto->dir = mAux;
							mAux = moto;}
					if(toupper(seguir) != 'S') seguir = 'S';
			break;
			case 2 : imprimirDatos(n, moto);
			break;
			case 3 : imprimirEstadistica(estadisticas);
//			case 4 : ordenarDatos(orden, marcas, n);
//			break;
		}
	}
}
