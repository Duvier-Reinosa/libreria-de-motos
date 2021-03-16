//Taller 1
// proposito: aprender sobre el tipo de datos con una buena obtención e impresión de datos, en este caso, datos de una motocicleta
// Autores: Santiago Castrillón - Duvier Reinosa Pelaez
//Fecha de creación: 7/03/2021


#include <stdio.h>
#include <string>

const char* numMes[] = { "No permitido", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre",
						"Octubre","Noviembre", "Diciembre"};

const char* nColores [] = {"", "Negro","Azul", "Marron", "Gris", "Verde", "Naranja", "Rosa", "Purpura", 
							"Rojo", "Blanco", "Amarillo" };
const char* numTransmisiones [] = {"","Automatica", "Semiautomatica", "Manual"};

							
int main (){
	char marca [10];
	char modelo [10];
	char nMotor [15];
	char nChasis [15];
	int transmision;
	int velocidades;
	int cilindraje;
	int dia;
	int mes;
	int anyo;
	int color;
	float peso;
	int torque;
	float capacidadDelTanque;
	
	printf("\n--------------------------------Entrada de datos--------------------------------\n");
	printf("\n                         Marca: "); scanf("%s", marca); fflush(stdin); 
	printf("\n                         Modelo: "); scanf("%s", modelo); fflush(stdin);
	printf("\n                         Numero de motor: "); scanf("%s", nMotor); fflush(stdin);	
	printf("\n                         Numero de chasis: "); scanf("%s", nChasis); fflush(stdin);
	printf("\n                            Tipo de transmision: ");
	printf("\n                            1.  Automatica");
	printf("\n                            2.  Semiautomatica");
	printf("\n                            3.  Manual");
	printf("\n                         Transmision: "); scanf("%u", &transmision); fflush(stdin);
	printf("\n                         Velocidades: "); scanf("%u", &velocidades); fflush(stdin);		
	printf("\n                         Cilindraje: "); scanf("%u", &cilindraje); fflush(stdin);	
	printf("\n                         Fecha de fabricacion: ");
	printf("\n                         Dia: "); scanf("%u", &dia); fflush(stdin);
	printf("\n                            Meses");
	printf("\n                            1.  Enero");
	printf("\n                            2.  Febrero");
	printf("\n                            3.  Marzo");
	printf("\n                            4.  Abril");
	printf("\n                            5.  Mayo");
	printf("\n                            6.  Junio");
	printf("\n                            7.  Julio");
	printf("\n                            8.  Agosto");
	printf("\n                            9.  Septiembre");
	printf("\n                            10. Octubre");
	printf("\n                            11. Noviembre");
	printf("\n                            12. Diciembre");
	printf("\n                         Mes: "); scanf("%u", &mes); fflush(stdin);
	printf("\n                         Anyo: "); scanf("%u", &anyo); fflush(stdin);	
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
	printf("\n                         Color: "); scanf("%u", &color); fflush(stdin);
	printf("\n                         Peso: "); scanf("%f", &peso); fflush(stdin);
	printf("\n                         Torque: "); scanf("%u", &torque); fflush(stdin);
	printf("\n                         Capacidad del tanque: "); scanf("%f", &capacidadDelTanque); fflush(stdin);

	printf("\n--------------------------------Salida de datos--------------------------------\n");
    printf("\n                         Marca: %s \n", marca);
    printf("\n                         Modelo: %s \n", modelo);
	printf("\n                         Numero De Motor: %s \n", nMotor);
	printf("\n                         Numero de chasis: %s \n", nChasis);
	printf("\n                         Transmision: %s \n", numTransmisiones[transmision] );
	printf("\n                         Velocidades: %i \n", velocidades);
	printf("\n                         Cilindraje: %u \n", cilindraje);
	printf("\n                         Anyo: %i \n", dia);
    printf("\n                         Mes: %s \n", numMes[mes]);; 
	printf("\n                         Anyo: %i \n", anyo);
	printf("\n                         Color: %s \n", nColores[color]);
	printf("\n                         Peso: %f \n", peso);
	printf("\n                         Torque: %i \n", torque);
	printf("\n                         Capacidad del tanque: %f \n", capacidadDelTanque);
}
