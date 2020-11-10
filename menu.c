/**
 * @file menu.c
 * @brief
 * @details
 *
 * @author Desarrolladores del proyecto
 *   Jose Pablo Montero C
 * @date Fecha de creaciòn
 *   10 de Noviembre 2020
 *
 * @author Desarrollador que realizo la ultima modificacion
 *   Jose Pablo Montero Cantu
 * @date Fecha de ultima modificacion
 *   10 de Noviembre 2020
 */

#include <stdio.h>
#include <stdlib.h>

/**@brief Prototipos de funcion*/
void mostrarInstrucciones(char [], char []);
void limpiarEntradaDatos(void);
void mostrarMenuPrincipal(void);
void mostrarMenuCatalogos(void);
void mostrarMenuRegistroClientes(void);
void agendarCita(void);
void mostrarMenuReportes(void);

/**
 * @fn  Funcion del programa Principal.
 * @return Entero: Si muestra un valor 0 nuestro programa, se esta ejecutando correctamente.
 */


int main(void)
{
  mostrarInstrucciones("Jose Pablo Montero","Descripcion del programa");
  limpiarEntradaDatos();
  
  return 0;
}


/**
 *@fn Procedimiento Muestra las instrucciones del programa.
 */
void mostrarInstrucciones(char autores[], char instrucciones[])
{
  printf("Aplicacion desarrollada por:\n");
  printf("\t%s\n\n", autores);
  printf("Descripcion del programa:\n");
  printf("\t%s\n\n", instrucciones);
  printf("Presiona la tecla enter para continuar:\n");
  getchar();
  
  system("clear");

  
  return;
  
}

/**
 *@fn Procedimiento que limpia el bufer de entrada.
 */
void limpiarEntradaDatos(void)
{
  int limpiar;
  
  while((limpiar = getchar()) != '\n' && limpiar !=EOF) {}

  return;

}

/**
 *@fn Procedimiento que muestra las opciones del menu princpial.
 */

void mostrarMenuPrincipal(void)
{
  printf("Menu Principal.\n\n");


  return;
  
}

/**
 *@fn Procedimiento que muestra el menu catalogos.
 */

void mostrarMenuCatalogos(void)
{
  printf("Menu Catalogos.\n\n");

  return;
}


/**
 *@fn Procedimiento que muestra el menu registro clientes.
 */

void mostrarMenuRegistroClientes(void)
{
  printf("Menu Registro Clientes.\n\n");

  return;
}

/**
 *@fn Procedimiento que muestra el menu para agendar una cita.
 */

void agendarCita(void)
{
  printf("Agendar cita.\n\n");

  return;
}

/**
 *@fn Procedimiento que muestra el menu reportes.
 */

void mostrarMenuReportes(void)
{
  printf("Menu Reportes.\n\n");

  return;
}
