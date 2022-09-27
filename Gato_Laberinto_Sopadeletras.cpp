#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;

int gato[4][4]={0};//tablero gato global

//INICIA FUNCIONES DE GATO
void imprimirgato()
{
	for(int i=1;i<=3;i++)
	{
		for (int j=1; j<=3;j++)
		{
			if(gato[i][j]!=0)
			{
				printf("  %c  |",gato[i][j]); 
			}
			else
			{
				printf("     |"); //remplaza 0 por espacio en blanco
			}
		}
		cout<<endl;
		cout<<"--------------------";
		cout<<endl;
	}
}
	
int ganar()
{
	int ganar=0;
	for(int i=1;i<=3;i++)
	{
		if((gato[i][1]==gato[i][2])&&(gato[i][2]==gato[i][3]))
		{
			//cout<<gato[i][1]<<"=="<<gato[i][2]<<"con "<<gato[i][2]<<"=="<<gato[i][3]<<endl;
			ganar=gato[i][2];
		}
	}
	
	for(int i=1;i<=3;i++)
	{
		if((gato[1][i]==gato[2][i])&&(gato[2][i]==gato[3][i]))
		{
				//cout<<gato[1][i]<<"=="<<gato[2][i]<<"con "<<gato[2][i]<<"=="<<gato[3][i]<<endl;
		ganar=gato[2][i];
		}
	}
		if(gato[1][1]==gato[2][2]&&gato[2][2]==gato[3][3])
	    {
			ganar=gato[2][2];
		}
		if(gato[1][3]==gato[2][2]&&gato[2][2]==gato[3][1])
		{
			ganar=gato[2][2];
		}
		
	return ganar;
}


int espacio()
{
	int ceros=0;
	for(int i=1;i<=3;i++)
	{
		for (int j=1;j<=3;j++)
		{
			if(gato[i][j]==0)
			{
				ceros++;
			}
		}
	}
	return ceros;
}

void casilla(int player)
{
	int selectedi, selectedj;
	do
	{
		cout<<"Elegir casilla a seleccionar"<<endl;
		cout<<"Coordenada en x: ";
		cin>>selectedj;
		cout<<"Coordenada en y: ";
		cin>>selectedi; 
	}
	while(selectedj<=0||selectedi>=4||selectedi<=0||selectedj>=4||gato[selectedi][selectedj]!=0);
	    //si las cooredenadas son invalidas vuelve a pedir 
				
	gato[selectedi][selectedj]=player;//marca casilla en gato(tablero)
	cout<<"Casilla marcada"<<endl;//confirma de marcar la casilla
}
				
void juego_gato()
{
	int contador=1;
	int player=1;
	printf("---------------\n");
	printf("INSTRUCCIONES\n");
	printf("---------------\n");
	printf("El tablero en el que se jugara el gato es una tabla de 3x3 por lo que las casillas se ubican respecto a los ejes X y Y.\n La coordenadas son las siguientes:\n");
	printf("X1,Y1|X2,Y1|X3,Y1\n------------------\nX1,Y2|X2,Y2|X3,Y2\n------------------\nX1,Y3|X2,Y3|X3,Y3\n");
	printf("\n");
	printf("En este juego participan dos jugadores, en donde el primero a elejir es el signo 0\n");
	printf("1.-Elejir la posicion en el eje X dentro de un rango de 1 a 3, en base a la tabla mostrada anteriormente.\n");
	printf("2.-Elejir la posicion en el eje Y dentro de un rango de 1 a 3, en base a la tabla mostrada anteriormente.\n");
	printf("\n");
	printf("El siguiente jugador es el signo X\n");
	printf("3.-Elejir la posicion en el eje X dentro de un rango de 1 a 3, en base a la tabla mostrada anteriormente.\n");
	printf("4.-Elejir la posicion en el eje y dentro de un rango de 1 a 3, en base a la tabla mostrada anteriormente.\n");
	printf("\n");
	printf("REGLAS:\n-El juego termina de dos formas:\n");
	printf("Cuando algun jugador resulta ganador, completando filas verticales, horizontales o fdiagonales de su signo, sea X o 0.\n");
	printf("Cuando ningun jugador logre juntar la fila de sus signos.\n");
	printf("-Si algun jugador elije alguna coordenada que este fuera del rango, el programa le pedira que ingrese de nuevo la coordenada respetando el rango.\n");
	imprimirgato();
					
		for(int a=1;a<=9;a++)
		{
			if((contador%2)==0)
			{
			    player=88;//X en ascii
			}
			else
			{
			    player=48;//0 en ascii
			}
						
			cout<<"TURNO DE JUDADOR "<<(char)player<<endl;
			casilla(player);
			//printf("\e[1;1H\e[2J");//Limpiar pantalla
			system("cls");
			imprimirgato();
						
			//Declara y checa Ganador
	        int x=ganar();
	        if(x!=0)
	        {
	        	cout<<"El GANADOR ES EL JUGADOR: "<< (char)x<<endl;
	        	a=10;
	        }
			else if(espacio()==0)
	        {
	            cout<<"ES EMPATE"<<endl;
	    	    a=10;
	        }
		contador++;
		} 
		
		for(int i=1;i<=3;i++)
		{
			for (int j=1;j<=3;j++)
			{
				gato[i][j]=0;
			}
		}//LIMPIAR AL FINAL
}
//FIN FUNCIONES GATO

//iNICIO JUEGO DE LABERINTO
void imprimirtablero(int x[12][12])
{
	for (int i=0;i<=11;i++)
	{
		for (int j=0;j<=11;j++)
		{
			if(x[i][j]==0)
			{
				printf("   ");
			}
			else if(x[i][j]==1)
			{
				printf("***");
			}
			else
			{
				printf(" ° ");
			}
			
		}
		cout<<endl;
	}
}
	
void juego_laberinto()
{
	int tablero[12][12]={
		    1,1,1,1,1,1,1,1,1,1,1,1,
			1,5,0,0,0,1,1,1,1,1,1,1,
			1,1,1,1,0,0,1,1,0,0,0,1,
			1,0,1,1,1,0,0,0,0,1,0,1,
			1,0,0,0,1,0,1,0,1,1,1,1,
			1,1,1,0,0,0,0,0,1,0,0,1,
			1,0,0,0,1,0,1,0,0,0,1,1,
			1,0,1,0,1,1,1,0,1,0,1,1,
			1,1,0,1,0,0,0,0,0,0,0,1,
			1,0,1,0,1,1,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,0,0,0,1,
			1,1,0,1,1,1,1,1,1,1,1,1 };
	
	
	int posactual_i=1;
	int posactual_j=1;
	
	int exit=1;
	cout<<"JUEGO LABERINTO:"<<endl;
	printf ("\n");
	
	printf ("Comandos de Movimiento\n");
	printf ("W: arriba, S: abajo, A: izquierda, D: derecha\n");
	printf ("En caso de salir, selecciona el comando e\n");
	printf ("\n");
	
	imprimirtablero(tablero);
	do
	{
		char movimiento;
		printf ("\n");
		printf("INSESRTE MOVIMIENTO\n");
		
		//printf("Si desea salir presione e\n");
		movimiento=getch();
		switch (movimiento)
		{
		case 'w':
		{
			//cout<<"entra a w"<<endl;
			int i, j;
			i=posactual_i;
			j=posactual_j;
			tablero[i][j]=0;
			int inuevo=i-1;
			
			if(tablero[inuevo][j]==0)
			{
				tablero[inuevo][j]=5;//remplaza monito a nueva posicion
				imprimirtablero(tablero);
				//cout<<"yafue"<<i<<""<<j<<endl;
				posactual_i=inuevo;
				posactual_j=j;
				//cout<<"mono se quedo en"<<posactual_i<<posactual_j<<endl;
			}
			else
			{
				Beep(1568,400);
				tablero[i][j]=5;
			}
			break;//cout<<"mono se quedo en"<<posactual_i<<posactual_j<<endl;
		}
		
		case 's':
		{
			int i, j;
			i=posactual_i;
			j=posactual_j;
			int inuevo=i+1;//marca cambio de posicion
			tablero[i][j]=0;//limpia posicion
			if(tablero[inuevo][j]==0)
			{
				tablero[inuevo][j]=5;//remplaza monito a nueva posicion
				imprimirtablero(tablero);
				//cout<<"yafue"<<i<<""<<j<<endl;
				posactual_i=inuevo;
				posactual_j=j;
				//cout<<"mono se quedo en"<<posactual_i<<posactual_j<<endl;
			}
			else
			{
				Beep(1568,400);
				tablero[i][j]=5;
			}
			break;//cout<<"mono se quedo en"<<posactual_i<<posactual_j<<endl;
		}
		
		case 'a':
		{
			int i, j;
			i=posactual_i;
			j=posactual_j;
			tablero[i][j]=0;//limpia posicion
			int jnuevo=j-1;//marca cambio de posicion
			
			if(tablero[i][jnuevo]==0)
			{
				tablero[i][jnuevo]=5;//remplaza monito a nueva posicion
				imprimirtablero(tablero);
				posactual_i=i;
				posactual_j=jnuevo;//guarda nueva posicion
			}
			else
			{
				Beep(1568,400);
				tablero[i][j]=5;
			}
			break;
		}
		
		case 'd':
		{
			int i, j;
			i=posactual_i;
			j=posactual_j;
			tablero[i][j]=0;
			int jnuevo=j+1;
			
			if(tablero[i][jnuevo]==0)
			{
				tablero[i][jnuevo]=5;//remplaza monito a nueva posicion
				imprimirtablero(tablero);
				posactual_i=i;
				posactual_j=jnuevo;//guarda nueva posicion
			}
			else
			{
				Beep(1568,400);
				tablero[i][j]=5;
			}
			break;
		}
		
		case 'e':
		{
			exit=0;//te saca del do-while
			cout<<"Usted ha salido";
			break;
		}
		
		default:
		{
			cout<<"COMANDO INVALIDO"<<endl;
		}
		//limpiar pantalla
		} 
		//cout<<"mono se quedo en"<<posactual_i<<posactual_j<<"valor"<<tablero[posactual_i][posactual_j]<<endl;
		//cout<<"status salida"<<tablero[11][2]<<endl;
		if(tablero[11][2]==5)
		{//checa si mono esta en salida
			cout<<"USTED HA GANADO, ¡FELICIDADES!"<<endl;
			getch();
			exit=0;
		}
		
	}while(exit==1);
	
}
//FIN JUEGO DE LABERINTO 


//iNICIO JUEGO DE SOPA
void juego_sopa()
{
	char palabra[10]="  ";
	int contador=0, intentos=13;
	printf("Bienvenido/a a la sopa de letras de la Formula 1\n");
	printf("Modalidad del juego:\n-Son en total 10 palabras\n-La respuesta se debe de escribir en minusculas\n-Cuenta con un margen de error de 3 intentos\n-NO está permito repetir palabras\n");
	cout<<"NOTA: usted podría escribir la misma palabra y obtener mas puntos (no lo haga no es divertido)"<<endl;
	printf("Presiona una tecla para comenzar\n");
	getch();
	system("cls");
	printf("G L Q H M E R C E D E S T R\n");
	printf("A A L P H A T A U R I H N N\n");
	printf("S R U Z V L A T G B U X P M\n");
	printf("T L Q B B Z M G T B J F E C\n");
	printf("O D T U H J E V B S A O U L\n");
	printf("N R E D B U L L J R L M O A\n");
	printf("M L A C U F U W U C F F W R\n");
	printf("A N N F E R R A R I A L E E\n");
	printf("R E F R R T F A P C R E K N\n");
	printf("T V U D W V J M A G O R X Q\n");
	printf("I W I L L I A M S F M A H C\n");
	printf("N C T S F K Y B F J E Y A B\n");
	printf("X S F A L P I N E E O L A V\n");
	printf("R M G U G Q Y N T P W I S L\n");
	
	
	while(intentos>=0)
	{
		cout<<"Inserte palabra encontrada"<<endl;
		scanf("%s", &palabra);
		if(strcmp(palabra,"ferrari")==0)//1
		{
			cout<<"Encontraste Ferrari +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"mercedes")==0)//2
		{
			cout<<"Encontraste Mercedes +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"redbull")==0)//3
		{
			cout<<"Encontraste Redbull +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"alphatauri")==0)//4
		{
			cout<<"Encontraste Alpha Tauri +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"hass")==0)//5
		{
			cout<<"Encontraste Hass +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"williams")==0)//6
		{
			cout<<"Encontraste Williams +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"alpine")==0)//7
		{
			cout<<"Encontraste Alpine +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"astonmartin")==0)//8
		{
			cout<<"Encontraste Aston Martin +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"alfaromeo")==0)//9
		{
			cout<<"Encontraste Alfa Romeo +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else if(strcmp(palabra,"mclaren")==0)//10
		{
			cout<<"Encontraste Mclaren +100"<<endl;
			contador=contador+100;
			Beep(1175,2000);
		}
		else
		{
			cout<<"PERDISTE UN INTENTO"<<endl;
			Beep(1821,600);
		}
		intentos--;//quita 1 inento por palabra
		
	}
	cout<<"\n-------------------------------------\n";
	cout<<"Oportunidades acabadas\n"<<endl;
	cout<<"Puntos totales: "<< contador<<endl;
	cout<<"\nFin del juego";
}
// FIN DE JUEGO DE SOPA 

void pausar()
{
	cout<<"Usted ha terminado de jugar"<<endl;
	cout<<"Para seguir presione cualquier letra";
	getch();//PAUSAR PANTALLA
	system("cls");
}

int main() 
{
	system("color 17");
	int opcionjuego,seguir=1;
	cout << "Bienvenido al mundo de los juegos!\n"<<endl;
						
	do
	{
		int iniciar;
		cout<<"Selecciona tu juego:\n"<<endl;
		cout<<"1.GATO"<<endl;
		cout<<"2.LABERINTO"<<endl;
		cout<<"3.SOPA DE LETRAS\n"<<endl;
		cout<<"4.Salir"<<endl;
	    cout<<"Seleccionar... "<<endl;
		cin>>opcionjuego;
							
		switch(opcionjuego)
		{
			case 1:
			{
				system("color E0");
				printf ("\n");
				cout<<"JUEGO DE GATO----------"<<endl;
				cout<<"Presione 4 para jugar"<<endl;
				cin>>iniciar;
				if(iniciar==4)
				{
					juego_gato();
					pausar();
				}
				else if(iniciar==2)
				{
					cout<<"Opción invalida";
				}
			break;
			}
			
			case 2:
			{
				system("color D7");
				
				printf("Bienvenido/a al juego del laberinto\n");
				printf ("\n");
				cout<<"Instrucciones:"<<endl;
				printf("Los * son paredes, no se pueden atravesar y una colicion del jugador es marcada con sonido\n");
				printf("El objetivo es salir del laberinto de la manera mas rapida\n");
				printf("Los comandos tienen que ser ingresados en minusculas\n");
				printf("Una vez completado el juego, el usuario puede elegir ir a la pantalla de inicio para seleccionar otro juego\n");
				printf("Buena Suerte!!!\n");
				cout<<"Presione una tecla para comenzar\n"<<endl;
				getch();//PAUSAR PANTALLA
				juego_laberinto();
			    pausar();
			    break;
			}
			
			case 3:
			{
				system("color B0");
				
				juego_sopa();
			    pausar();
			    break;
			}
			
			case 4:
			{
				
			seguir=0;
			break;
			}
			
			default: 
			{
				cout<<"OPCION INVALIDA"<<endl;
				pausar();
			}
			
		}
			//printf("\e[1;1H\e[2J"); //Borrar lo anterior
			
		system("cls");
	}
	while(seguir!=0);

}
