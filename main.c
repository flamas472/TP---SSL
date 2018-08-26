#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define TAMC 7
#define TAMF 4
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
void llenarTT(int tt[TAMF][TAMC]);
void mostrarTT(int tt[TAMF][TAMC]);
void reconocedorDePalabras(char lineaDeTexto[], char tt[TAMF][TAMC]);
bool perteneceAint(int buscado, int vector[], int tam);
bool perteneceAchar(char buscado, char vector[], int tam);
bool esEtadoFinal(int estado){return perteneceAint(estado, estadoFinal, 2);}
bool esEstadoInicial(int estado){return perteneceAint(estado, estadoInicial, 1);}



int main() {

  enum estado{e0, e1, e2, e3, e4, e5, e6};
  enum caracter{c01, c2_9, cB , cPunto};
  int tablaDeTransiciones[TAMF][TAMC];
  llenarTT(tablaDeTransiciones);
  int opcion = 0;


  do{
    opcion = menuPrincipal();
    switch(opcion){
      case 0:
        system("CLS");
        printf("HASTA LUEGO\n");
        system("PAUSE");
        system("CLS");
      break;
      case 1:
        system("CLS");
        mostrarTT(tablaDeTransiciones);
        system("PAUSE");
        system("CLS");
      break;
      case 2:
        system("CLS");
        printf("EN DESARROLLO\n");
        system("PAUSE");
        system("CLS");
      break;
      default:
        system("CLS");
        printf("OPCION INCONRRECTA\n");
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
  printf("Lenguaje regular: (REGEX) [01]\\.[0-9]{2}|[01]+B\tCentinela: #\n");
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

void llenarTT(int tt[TAMF][TAMC]){
  int vacio = '-';

  //TABLA DE TRANSICIONES
  tt[0][0] = 1;
  tt[0][1] = vacio;
  tt[0][2] = vacio;
  tt[0][3] = vacio;
  //FILA ESTADO 0-
  tt[1][0] = 2;
  tt[1][1] = vacio;
  tt[1][2] = 3;
  tt[1][3] = 4;
  //FILA ESTADO 1
  tt[2][0] = 2;
  tt[2][1] = vacio;
  tt[2][2] = 3;
  tt[2][3] = vacio;
  //FILA ESTADO 2
  tt[3][0] = vacio;
  tt[3][1] = vacio;
  tt[3][2] = vacio;
  tt[3][3] = vacio;
  //FILA ESTADO 3+
  tt[4][0] = 5;
  tt[4][1] = 5;
  tt[4][2] = vacio;
  tt[4][3] = vacio;
  //FILA ESTADO 4
  tt[5][0] = 6;
  tt[5][1] = 6;
  tt[5][2] = vacio;
  tt[5][3] = vacio;
  //FILA ESTADO 5
  tt[6][0] = vacio;
  tt[6][1] = vacio;
  tt[6][2] = vacio;
  tt[6][3] = vacio;
  //FILA ESTADO 6+
}

void mostrarTT(int tt[TAMF][TAMC]){
  int f, c;
  printf("TABLA DE TRANSICIONES\n");
  printf("\n\t\t0,1\t2-9\tB\t.\n");
  for(f=0; f<TAMC; f++){
    printf("\nestado%d\t", f);
    for(c=0; c<TAMF; c++){
      if(tt[f][c]>6){
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
