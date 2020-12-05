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
 *   04 de Diciembre 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Bibliotecas/funciones.h"

/**@brief Prototipos de funcion*/
void mostrarMenuPrincipal(void);
void mostrarMenuCatalogos(void);
void mostrarMenuRegistroClientes(void);
void agendarCita(void);
void mostrarMenuReportes(void);
int mostrarPaquetesCatalogos(void);

/**
 * @fn  Funcion del programa Principal.
 * @return Entero: Si muestra un valor 0 nuestro programa, se esta ejecutando correctamente.
 */

int main(void)
{
  system("clear");
  mostrarInstrucciones("Jose Pablo, Thalia Bravo y Ricardo Lopez","Sistema de un autolavado.");
  mostrarMenuPrincipal();
  
  return 0;
}

/**
 *@fn Procedimiento que muestra el menu principal.
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

      printf("Selecciona una opcion del menu (1  -  2): ");
      scanf(" %hd", &opcionMenu);
      limpiarEntradaDatos();
      
    }while(opcionMenu <1 || opcionMenu > 2);

  switch(opcionMenu)
    {
    case 1:
      system("clear");
      printf("Acciones para mostrar paquetes de lavado de autos.\n\n");
       printf("Presiona la tecla \"enter\" para continuar.\n");
       getchar();
       mostrarPaquetesCatalogos();
       
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
  

   short int opcionMenu;
   
  do
    {
      system("clear");
      printf("Menu Registro Clientes.\n\n");
      printf("\t1) Agregar un cliente.\n");
      printf("\t2) Modificar datos de cliente.\n");
      printf("\t3) Eliminar cliente.\n");
      printf("\t4) Regresar al menu principal.\n\n");

      printf("Selecciona una opcion del menu (1  -  4): ");
      scanf(" %hd", &opcionMenu);
      limpiarEntradaDatos();
      
    }while(opcionMenu <1 || opcionMenu > 4);

  switch(opcionMenu)
    {
    case 1:
     
      break;
    }

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

int mostrarPaquetesCatalogos(void)
{
  short int opcion, opcion2;
  int precio;
  char cajuela, tipoAuto;
  
   do
    {
      system("clear");
      printf("Paquetes para lavado de auto.\n\n");
      printf("\t1) Espuma activa.\n\n");
      printf("\t\t a.\tCosto $80.00.\n\n");
      printf("\t\t b.\tDescripcion del paquete:Espuma activa, lavado, aspirado interior y secado.\n\n");

      printf("\t2) Cera líquida.\n\n");
      printf("\t\t a.\tCosto $90.00.\n\n");
      printf("\t\t b.\tDescripcion del paquete: Espuma activa, lavado, aspirado interior, secado y super encerado.\n\n");

      printf("\t3) Premium.\n\n");
      printf("\t\t a.\tCosto $99.00.\n\n");
      printf("\t\t b.\tDescripcion del paquete: Premium, lavado, aspirado interior, secado, super encerado y lavado de chasis.\n\n");

      printf("\t4) Regresar.\n\n");


      printf("Selecciona una opcion del menu (1  -  4): ");
      scanf(" %hd", &opcion);
      limpiarEntradaDatos();
      
    }while(opcion <1 || opcion > 4);

   switch(opcion)
     {
     case 1:
       precio = 80;
       printf("\nEscogiste: Espuma activa, este paquete tiene un precio de: $%d\n\n",precio);
       printf("Por $10.00 mas quisieras que aspiremos tu cajuela?\n");
       printf("Escribe si (s) o no (n):");
       scanf(" %c", &cajuela);
       limpiarEntradaDatos();
       if(cajuela == 's')
	 {
	   precio = precio + 10;
	   system("clear");
	   printf("\nTu precio estimado es de: $%d\n\n", precio);
	 }else if(cajuela == 'n')
	 {
	   system("clear");
	   printf("\nTu precio estimado es de: $%d\n\n", precio);
	 }
       printf("\ta) Camioneta \tb)Pick-up \tc)Auto\n ");
       printf("Que tipo de vehiculo tienes?( a, b, c): ");
       scanf(" %c", &tipoAuto);
       limpiarEntradaDatos();
       if(tipoAuto == 'a' || tipoAuto == 'b')
	 {
	   precio = precio +10;
	   printf("\n\nTu total seria de: $%d", precio);
	   
	 }else if(tipoAuto == 'c')
	 {
	   printf("\n\nTu total es de: $%d", precio); 
	 }
       do
	 {
	   printf("\n\t1) Regresar.\n");
	   printf("\t2) Menu Principal.\n\n");
	   
	   
	   printf("Selecciona una opcion (1  -  2): ");
	   scanf(" %hd", &opcion2);
	   limpiarEntradaDatos();
	   
	 }while(opcion2 <1 || opcion2 > 2);
       
       switch(opcion2)
	 {
	 case 1:
	   mostrarPaquetesCatalogos();
	   break;
	   
	 case 2:
	   mostrarMenuPrincipal();
	   break;
	   
	 default:
	   printf("Por favor, ingresa una opcion valida: ");
	   mostrarPaquetesCatalogos();
	   break;
	 }
       break;

      case 2:
	precio = 90;
	printf("\nEscogiste: Cera Líquida, este paquete tiene un precio de: $%d\n\n",precio);
	printf("Por $10.00 mas quisieras que aspiremos tu cajuela?\n");
	printf("Escribe si (s) o no (n):");
	scanf(" %c", &cajuela);
	limpiarEntradaDatos();
	if(cajuela == 's')
	  {
	    precio = precio + 10;
	    system("clear");
	    printf("\nTu precio estimado es de: $%d\n\n", precio);
	  }else if(cajuela == 'n')
	  {
	    system("clear");
	    printf("\nTu precio estimado es de: $%d\n\n", precio);
	  }
	printf("\ta) Camioneta \tb)Pick-up \tc)Auto\n ");
	printf("Que tipo de vehiculo tienes?(a, b, c): ");
	scanf(" %c", &tipoAuto);
	limpiarEntradaDatos();
	if(tipoAuto == 'a' || tipoAuto == 'b')
	  {
	    precio = precio +10;
	    printf("\n\nTu total seria de: $%d", precio);
	    
	  }else if(tipoAuto == 'c')
	  {
	    printf("\n\nTu total es de: $%d", precio); 
	  }
	do
	  {
	    printf("\n\t1) Regresar.\n");
	    printf("\t2) Menu Principal.\n\n");
	    
	    
	    printf("Selecciona una opcion (1  -  2): ");
	    scanf(" %hd", &opcion2);
	    limpiarEntradaDatos();
	    
	  }while(opcion2 <1 || opcion2 > 2);
	
	switch(opcion2)
	  {
	  case 1:
	    mostrarPaquetesCatalogos();
	    break;
	    
	  case 2:
	    mostrarMenuPrincipal();
	    break;
	    
	  default:
	    printf("Por favor, ingresa una opcion valida: ");
	    mostrarPaquetesCatalogos();
	    break;
	  }
       break;

      case 3:
	precio = 99;
	printf("\nEscogiste: Espuma activa, este paquete tiene un precio de: $%d\n\n",precio);
	printf("Por $10.00 mas quisieras que aspiremos tu cajuela?\n");
	printf("Escribe si (s) o no (n):");
	scanf(" %c", &cajuela);
	limpiarEntradaDatos();
	if(cajuela == 's')
	  {
	    precio = precio + 10;
	    system("clear");
	    printf("\nTu precio estimado es de: $%d\n\n", precio);
	  }else if(cajuela == 'n')
	  {
	    system("clear");
	    printf("\nTu precio estimado es de: $%d\n\n", precio);
	  }

	printf("\ta) Camioneta \tb)Pick-up \tc)Auto\n ");
	printf("Que tipo de vehiculo tienes?(a, b, c): ");
	scanf(" %c", &tipoAuto);
	limpiarEntradaDatos();
	if(tipoAuto == 'a' || tipoAuto == 'b')
	  {
	    precio = precio +10;
	    printf("\n\nTu total seria de: $%d", precio);
	    
	  }else if(tipoAuto == 'c')
	  {
	    printf("\n\nTu total es de: $%d", precio); 
	  }
	do
	  {
	    printf("\n\t1) Regresar.\n");
	    printf("\t2) Menu Principal.\n\n");
	    
	    
	    printf("Selecciona una opcion (1  -  2): ");
	    scanf(" %hd", &opcion2);
	    limpiarEntradaDatos();
	    
	  }while(opcion2 <1 || opcion2 > 2);
	
	switch(opcion2)
	  {
	  case 1:
	    mostrarPaquetesCatalogos();
	    break;
	    
	  case 2:
	    mostrarMenuPrincipal();
	    break;
	    
	  default:
	    printf("Por favor, ingresa una opcion valida: ");
	    mostrarPaquetesCatalogos();
	    break;
	    
	  }
	
      	break;

      case 4:
	mostrarMenuPrincipal();
	break;

     default:
       printf("\nOpcion invalida, Por favor intenta de nuevo. ");
       mostrarPaquetesCatalogos();
       break;
     }
   
   return precio;
}
