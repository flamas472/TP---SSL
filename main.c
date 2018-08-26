#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define TAMC 7
#define TAMF 10
#define ER_MENSAJE "Lenguaje regular: (REGEX) [01]\\.[0-9]{2}|[01]+B\tCentinela: #\n"
/// VARIABLES GLOBALES
char caracteres0y1[2] = {'0', '1'};
char caracteres2a9[8] = {'2', '3', '4', '5', '6', '7', '8', '9' };
char caracterB[1] = {'B'};
char caracter[1] = {'.'};
char centinela = '#';
int estadoInicial[1] = {0};
int estadoFinal[2] = {3, 6};
/// FUNCIONES
int menuPrincipal();
void mostrarTT(int tt[TAMF][TAMC]);
void reconocedorDePalabras(char lineaDeTexto[], char tt[TAMF][TAMC]);
bool perteneceAint(int buscado, int vector[], int tam);
bool perteneceAchar(char buscado, char vector[], int tam);
bool esEtadoFinal(int estado){return perteneceAint(estado, estadoFinal, 2);}
bool esEstadoInicial(int estado){return perteneceAint(estado, estadoInicial, 1);}
void buscadorDePalabras(char s[32]);



int main() {
  int tt[TAMF][TAMC] =  {
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
  enum estado{e0, e1, e2, e3, e4, e5, e6};
  enum caracter{c01, c2_9, cB , cPunto};
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
        printf("EN DESARROLLO\n\n");
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

void reconocedorDePalabras(char lineaDeTexto[], char tt[TAMF][TAMC]){
  int cantidadDePalabrasPresentes = 0;
  int pos = 0;
  int estado;
  ///ALGORITMO 3
  while(lineaDeTexto[pos] != '\0' /*NO FDT*/){
    ///ESTADO ACTUAL DEL AUTOMATA: INICIAL
    estado = 0;
    while(lineaDeTexto[pos] != '#' /*NO CENTINELA*/){
      ///DETERMINAR NUEVO ESTADO DEL AUTOMATA
      ///ACTUALIZAR CARACTER A ANALIZAR
      switch(lineaDeTexto[pos]){
        case '0': case '1':
          ///COMPLETAR CASOS 0y1
        break;
        case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
          ///COMPLETAR CASOS 2a9
        break;
        case 'B':
          ///COMPLETAR CASO B
        break;
        case '.':
          ///COMPLETAR CASO .
        break;
        default:
          ///COMPLETAR CASO CARACTER NO PERTENECIENTE AL ALFABETO NI CENTINELA
        break;


      }/// FIN SWITCH

    }/// FIN WHILE CENTINELA
    ///SI EL ESTADO ES FINAL LA CADENA PERTENECE AL LENGUAJE

    if (esEtadoFinal(estado)){
      cantidadDePalabrasPresentes++;
      printf("COMPLETAR");///IMPRIMIR CADENA ENCONTRADA
    }
    pos++;
  }/// FIN WHILE FDT
}

int menuPrincipal(){
  int opcion = 0;
  printf("Menu Principal\n");
  printf("\n");
  printf(ER_MENSAJE);
  printf("\n");
  printf("1) Ver tabla de transiciones.\n");
  printf("2) Ejecutar reconocedorde secuencias de cadenas.\n");
  printf("\n");
  printf("0) Salir");
  printf("\n");
  printf("Ingrese la opcion deseada: ");
  scanf("%d", &opcion);
  return opcion;
}

void mostrarTT(int tt[TAMF][TAMC]){
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

bool perteneceAint(int buscado, int vector[], int tam){
  int i;
  for(i=0; i<tam;i++){
    if(vector[i]==buscado);
      return true;
  }
  return false;
}

bool perteneceAchar(char buscado, char vector[], int tam){
  int i;
  for(i=0; i<tam;i++){
    if(vector[i]==buscado);
      return true;
  }
  return false;
}

//FUNCIONES DE PRUEBA
void buscadorDePalabras(char s[32]);
