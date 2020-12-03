/**
 * @file principal.
 * @brief Sistema para administrar un negocio de autolavado.
 * @details Programa uqe muestra las diferentes funciones de un autolavado.
 *
 * @author Desarrolladores del proyecto
 *   Jose Pablo Montero C, Thalia Bravo Pimentel, Ricardo Lopez.
 * @date Fecha de creaciòn
 *   10 de Noviembre 2020
 *
 * @author Desarrollador que realizo la ultima modificacion
 *   Jose Pablo Montero Cantu
 * @date Fecha de ultima modificacion
 *   02 de Diciembre 2020
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
  mostrarInstrucciones("Jose Pablo Montero, Thalia BRavo y Ricardo Lopez","Sistema de un autolavado.");
  mostrarMenuPrincipal();
  
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
  short int opcionMenu;
 
 
  do
    {
      system("clear");
      printf("Menu Principal.\n\n");
      printf("\t1) Catalogos.\n");
      printf("\t2) Registro clientes.\n");
      printf("\t3) Agendar cita.\n");
      printf("\t4) Reportes.\n");
      printf("\t5) Salir.\n\n");
      
      
      printf("Selecciona una opcion del menu (1  -  5): ");
      scanf(" %hd", &opcionMenu);
      limpiarEntradaDatos();
    }
  while(opcionMenu < 1 || opcionMenu > 5);

  switch(opcionMenu)
    {
      
    case 1:
       mostrarMenuCatalogos();
    break;
    
    case 2:
       mostrarMenuRegistroClientes();
    break;
    
    case 3:
      agendarCita();  
    break;
    
    case 4:
      mostrarMenuReportes();  
    break;
    
    case 5:
      printf("\nMuchas gracias por utilizar el sistema, que tenga buen dia.\n\n"); 
     break;
     
    default:
       printf("\nOpcion invalida o no disponible por el momento.\n\n");
       printf("Presiona la tecla \"enter\" para continuar.\n");
       getchar();
       mostrarMenuPrincipal();
    break;
      
    }
  
  return;
  
}

/**
 *@fn Procedimiento que muestra el menu catalogos.
 */

void mostrarMenuCatalogos(void)
{
  short int opcionMenu;
  
  

  do
    {
      system("clear");
      printf("Menu catalogos.\n\n");
      printf("\t1) Paquetes para lavado de autos.\n");
      printf("\t2) Regresar al menu principal.\n\n");

      printf("Selecciona una opcion del menu (1  -  5): ");
      scanf(" %hd", &opcionMenu);
      limpiarEntradaDatos();
      
    }while(opcionMenu <1 || opcionMenu > 2);

  switch(opcionMenu)
    {
    case 1:
      printf("Acciones para mostrar paquetes de lavado de autos.\n\n");
       printf("Presiona la tecla \"enter\" para continuar.\n");
       getchar();
       mostrarMenuCatalogos();
       
    break;
    
    case 2:
      mostrarMenuPrincipal();  
    break;
    
    default:
      printf("\nOpcion invalida o no disponible por el momento.\n\n");
       printf("Presiona la tecla \"enter\" para continuar.\n");
       getchar();
       mostrarMenuCatalogos();
    break;
      
    }
  
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
