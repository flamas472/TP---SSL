#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// VARIABLES GLOBALES Y CONSTANTES SIMBOLICAS

#define TAMC 7
#define TAMF 10
#define ER_MENSAJE "Lenguaje regular: (REGEX) [01]\\.[0-9]{2}|[01]+B\tCentinela: #\n"
#define CENTINELA '#'
#define FDT '\0'
#define CANTIDADEF 2 // Cantidad de estados finales
#define ESTADOFDT 9
#define MAXLINE 100

int estadoFinal[2] = {6, 7}; // Estados finales
int tt[TAMF][TAMC] =  { // Tabla de Transiciones
  {1, 8, 8, 8, 8, 0, 9},
  {2, 8, 3, 4, 8, 0, 9},
  {2, 8, 3, 8, 8, 0, 9},
  {8, 8, 8, 8, 8, 6, 7},
  {5, 5, 8, 8, 8, 0, 9},
  {3, 3, 8, 8, 8, 0, 9},
  {1, 8, 8, 8, 8, 0, 9},
  {'-', '-', '-', '-', '-', '-', '-'},
  {8, 8, 8, 8, 8, 0, 9},
  {'-', '-', '-', '-', '-', '-', '-'}
};

// FUNCIONES

int menuPrincipal();
void mostrarTT();
void reconocedorDePalabras(int contador);
int actualizarEstado(int estado, int caracter);
int consultarCaracter(char caracter);
int hacerTransicion(int estado, char caracter);
int esEstadoFinal(int estado);
int tomarLinea(char s[], int lim);
int scanfIntervalo(int limInf, int limSup);
int algoritmo3(char lineaDeTexto[MAXLINE], int contador);


int main() {

  int opcion = 0;

  do{
    opcion = menuPrincipal();
    switch(opcion){
      case 0:
        system("CLS");
        printf("Hasta Luego\n\n");
        system("PAUSE");
        system("CLS");
      break;
      case 1:
        system("CLS");
        mostrarTT(tt);
        system("PAUSE");
        system("CLS");
      break;
      case 2:
        system("CLS");
        reconocedorDePalabras(0);
        system("PAUSE");
        system("CLS");
      break;
      default:
        system("CLS");
        printf("Opcion Incorrecta\n\n");
        system("PAUSE");
        system("CLS");
      break;
    }
  }while(opcion);

  return 0;
}

void reconocedorDePalabras(int contador){
  char lineaDeTexto[100];
  int eleccion;

  tomarLinea(lineaDeTexto, 100);

  contador = algoritmo3(lineaDeTexto, contador);

  do{
    printf("Lectura completada,palabras encontradas: %d\n", contador);
    printf("Desea continuar?\n");
    printf("1) Si.\n");
    printf("0) No.\n");
    printf("-> ");
    eleccion = scanfIntervalo(0, 1);
    if(eleccion == 0){
      printf("\nProceso de reconocimiento finalizado,\nvolvera al menu principal\n");
    }else{
      printf("Desea resetear el contador de palabras encontradas?\n");
      printf("1) Si.\n");
      printf("0) No.\n");
      printf("->");
      eleccion = scanfIntervalo(0, 1);
      if(eleccion==1){

        tomarLinea(lineaDeTexto, 100);

        contador = algoritmo3(lineaDeTexto, 0);

      }else{

        tomarLinea(lineaDeTexto, 100);

        contador = algoritmo3(lineaDeTexto, contador);

        eleccion = 1;
      }
    }
  }while(eleccion != 0);
}

int algoritmo3(char lineaDeTexto[MAXLINE], int contador){                         //ALGORITMO 3
  int pos = 0;
  char cadena[64];
  int posCadena = 0;
  int estado;
  int caracter;
  if(lineaDeTexto[pos] != FDT){                                                   // Intenta leer el priner caracter del texto

    while(lineaDeTexto[pos] != FDT){                                              // Mientras no sea fdt, repetir:

      estado = 0;

      while(!(esEstadoFinal(estado)) && (estado != ESTADOFDT)){                   // (2) Mientras no sea un estado final y no sea el estado fdt

        estado = hacerTransicion(estado, lineaDeTexto[pos]);                      // (2.1) Determinar el nuevo estado actual

        cadena[posCadena] = lineaDeTexto[pos];

        // Si se encuentra con un centinela debe reiniciarse la cadena actual
        // si se encuentra un centinela o fdt debe cerrarse la cadena
        if((lineaDeTexto[pos] == CENTINELA) || lineaDeTexto == FDT){
          cadena[posCadena] = '\0';
          posCadena = 0;
        }else{
        posCadena++;
        }
        pos++;                                                                    // (2.2) Actualizar el caracter a analizar
      }

      if (esEstadoFinal(estado)){                                                 // (3) Si el estado es final,
        contador++;                                                               // la cadena procesada es una palabra del lenguaje;
        printf("\t\t%d) %s\n", contador, cadena);                                 // caso contrario, no pertenece al lenguaje
      }
    }

  }
  return contador;
}                                                                                 // FIN DEL ALGORITMO 3

int scanfIntervalo(int limInf, int limSup){
  int eleccion;
  scanf("%d", &eleccion);
  while(eleccion<limInf || eleccion>limSup){
    printf("Opcion incorrecta\n");
    printf("-> ");
    scanf("%d", &eleccion);
  }
  return eleccion;
}

int menuPrincipal(){
  int opcion = 0;
  printf("Menu Principal\n");
  printf("\n");
  printf(ER_MENSAJE);
  printf("\n");
  printf("1) Ver tabla de transiciones.\n");
  printf("2) Ejecutar reconocedorde secuencias de cadenas.\n");
  printf("0) Salir");
  printf("\n");
  printf("-> ");
  scanf("%d", &opcion);
  return opcion;
}

void mostrarTT(){ // Muestra la tabla de transiciones
  int f, c;
  printf("Tabla de Transiciones\n\n");
  printf(ER_MENSAJE);
  printf("\nTT\t\t0,1\t2-9\tB\t.\totro\t#\tfdt\n");
  for(f=0; f<TAMF; f++){
    printf("\nestado%d\t", f);
    for(c=0; c<TAMC; c++){
      if(tt[f][c]>TAMF){
        printf("\t%c", tt[f][c]);
      }else{
        printf("\t%d", tt[f][c]);
      }
    }
  }
  printf("\n\n");
}

int esEstadoFinal(int estado){ // Devuelve 1 si el estado es final (segun vector estadoFinal[])
  int i;
  for(i=0; i<CANTIDADEF; i++){
    if(estadoFinal[i]==estado){
      return 1;
    }
  }
  return 0;
}

int copiar(char a[], char desde[]){ // Copia la cadena desde[] en a[]
  int i;
  i = 0;
  while((a[i] = desde[i]) != '\0')
   ++i;
  a[i+1] = '\0';
  return i;
}

int tomarLinea(char s[], int lim){ // Solicita una cadena por entrada en consola
  int longitud;
  char str[lim];
  printf("Ingrese una cadena:\n");
  printf("-> ");
  scanf("%s", &str);
  longitud = copiar(s, str);
  return longitud;
}

int actualizarEstado(int estado, int caracter){ // Recibe un estado y un caracter y devuelve el estado siguiente
  int nuevoEstado;
  nuevoEstado = tt[estado][caracter];
  return nuevoEstado;
}

int consultarCaracter(char caracter){ // Consulta el caracter, retorna la columna de la TT
  switch(caracter){
    case '0': case '1':
      return 0;
    break;
    case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
      return 1;
    break;
    case 'B':
      return 2;
    break;
    case '.':
      return 3;
    break;
    case CENTINELA:
      return 5;
    break;
    case FDT:
      return 6;
    break;
    default:
      return 4;
    break;
  }
}

int hacerTransicion(int estado, char caracter){ // Retorna el nuevo estado solicitando estado y caracter
  int columna = consultarCaracter(caracter);
  estado = actualizarEstado(estado, columna);
  return estado;
}
