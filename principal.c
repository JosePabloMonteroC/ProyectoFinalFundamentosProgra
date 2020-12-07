/**
 * @file principal.c
 * @brief Sistema para administrar un negocio de autolavado.
 * @details Programa que muestra las diferentes funciones de un autolavado.
 *
 * @author Desarrolladores del proyecto
 *   Jose Pablo Montero Cantú, Thalía Isabel Bravo Pimentel, Ricardo López Alvarez.
 * @date Fecha de creación
 *   10 de Noviembre 2020
 *
 * @author Desarrollador que realizo la ultima modificacion
 *   Jose Pablo Montero Cantú
 * @date Fecha de ultima modificacion
 *   07 de Diciembre 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/funciones.h"

/**
 *@brief Estructuras.
 */
 struct Datos
 {
 	char nombre[50], marca[50], modelo[50], color[15], placas[10];
	int ID, tipoAuto, numeroServicios;
 };
 
 struct Agendar
 {
   int dia, hora, paquete, cajuela, total;
 };


/**@brief Prototipos de funcion*/
void mostrarPrincipal(void);
void mostrarCatalogo(void);
void mostrarMenuRegistroClientes(void);
void mostrarMenuReportes(void);
void registrarClientes(int numClientes, struct Datos* Clientes);
void mostrarCliente(int numClientes, struct Datos* Clientes);
void editarCliente(int numClientes, struct Datos* Clientes);
void eliminarCliente(int numClientes, struct Datos* Clientes);
void agendarCitas(int numCita, int numClientes, struct Agendar* Cita, struct Datos* Clientes, int miercoles[1], int hmiercoles[5], int jueves[1], int hjueves[5], int viernes[1], int hviernes[5], int sabado[1], int hsabado[5], int domingo[1], int hdomingo[5]);
void mostrarGanancias(int  numCita, struct Agendar* Cita);
void mostrarCitas(int numCita, struct Agendar* Cita, int hmiercoles[5], int hjueves[5], int hviernes[5], int hsabado[5], int hdomingo[5];);
void mostrarProgramaLealtad(int numClientes,struct Datos* Clientes);

/**
 * @fn  Funcion del programa Principal.
 * @return Entero: Si muestra un valor 0 nuestro programa, se esta ejecutando correctamente.
 */

int main(void)
{
  struct Datos Clientes[100];
  struct Agendar Cita[6];
  int miercoles[1], jueves[1], viernes[1], sabado[1], domingo[1];
  int hmiercoles[5], hjueves[5], hviernes[5], hsabado[5], hdomingo[5];
  int opcionMenu, opcionClientes, opcionReportes, opcionGeneral = 1, numClientes = 0, numCita = 0, opcionCita;
  
  system("clear");
  mostrarInstrucciones("José Pablo Montero, Thalía Bravo y Ricardo López","Sistema del autolavado 'SuperWash'.");
  
  printf ("\n\n\t\t\t---->Autolavado 'SuperWash'<----\n\n");
  printf ("\tFundadores: José Pablo Montero, Ricardo López, Thalía Bravo\n");
  printf ("\t Abierto de Miércoles a Domingo, de 10:00 hrs a 15:00 hrs\n\n");
  printf("\t\t\tPresiona 'ENTER' para empezar!.");
  getchar();
  
  do 
    {
      mostrarPrincipal();
      printf ("Por favor seleccione la opción del menú que requiera: ");
      scanf (" %d", &opcionMenu);
      
      switch (opcionMenu)
	{
	case 1:
	  mostrarCatalogo();
	  getchar();
	  break;
	  
	case 2:
	  mostrarMenuRegistroClientes();
	  printf ("Seleccione una opción: ");
	  scanf (" %d", &opcionClientes);
	  switch (opcionClientes)
	    {
	    case 1:
	      registrarClientes(numClientes, Clientes);
	      numClientes = numClientes + 1;
	      getchar();
	      break;
	      
	    case 2:
	      mostrarCliente(numClientes, Clientes);
	      getchar();
	      break;
	      
	    case 3:
	      editarCliente(numClientes, Clientes);
	      getchar();
	      break;
	      
	    case 4:
	      eliminarCliente(numClientes, Clientes);
	      getchar();
	      break;
	      
	    case 5:
	      break;
	      
	    default:
	      printf ("No es una opción válida, intenta de nuevo\n");
	      break;
	    }
	  break;
	  
	case 3:
	  system("clear");
	  printf ("El cliente está registrado? ([1]Si [2]No [3]Regresar al menú principal): ");
	  scanf (" %d", &opcionCita);
	  switch (opcionCita)
	    {
	    case 1:
	      agendarCitas(numCita, numClientes, Cita, Clientes, miercoles, hmiercoles, jueves, hjueves, viernes, hviernes, sabado, hsabado, domingo, hdomingo);
	      numCita = numCita + 1;
	      getchar();
	      break;
	      
	    case 2:
	      registrarClientes(numClientes, Clientes);
	      numClientes = numClientes + 1;
	      getchar();
	      break;
	      
	    case 3:
	      break;
	      
	    default:
	      printf ("Opción no válida\n");
	      break;
	    }
	  break;
	  
	case 4:
	  mostrarMenuReportes();
	  printf ("Seleccione una opción: ");
	  scanf (" %d", &opcionReportes);
	  switch (opcionReportes)
	    {
	    case 1:
	      mostrarGanancias(numCita, Cita);
	      getchar();
	      break;
	      
	    case 2:
	      mostrarCitas(numCita, Cita, hmiercoles, hjueves, hviernes, hsabado, hdomingo);
	      getchar();
	      break;
	      
	    case 3:
	      mostrarProgramaLealtad(numClientes, Clientes);
	      getchar();
	      break;
	      
	    case 4:
	      break;
	      
	    default:
	      printf ("No es una opción válida, intenta de nuevo\n");
	      break;
	    }
	  break;	
	  
	case 5:
	  opcionGeneral = 0;
	  break;
	  
	default:
	  printf ("No es una opción válida, intenta de nuevo\n");
	  break;
	  
	}
    } while (opcionGeneral != 0);
  
  printf ("\n¡Gracias por venir!\n\n\n");
  
  return 0;
}

/**
 *@fn Procedimiento que muestra el menu principal.
 */
void mostrarPrincipal(void)
{
  system("clear");
  printf ("Menú principal\n\n");
  printf ("\t[1] Mostrar Catálogo\n\n\t\t[A] Paquetes para lavado de autos\n\n\n");
  printf ("\t[2] Registro de Clientes\n\n\t\t[A] Agregar cliente\n\t\t[B] Mostrar Cliente\n\t\t[C] Modificar datos de un cliente\n\t\t[D] Eliminar cliente\n\t\t[E] Regresar al menú principal\n\n\n");
  printf ("\t[3] Agendar Cita\n\n\t\t[A] Agendar una cita\n\t\t[B] Regresar al menú principal\n\n\n");
  printf ("\t[4] Reportes\n\n\t\t[A] Ganancias\n\t\t[B] Citas\n\t\t[C] Programa de lealtad\n\t\t[D] Regresar al menú principal\n\n\n");
  printf ("\t[5] Salir\n\n");
  
  return;
}

/**
 *@fn Procedimiento que muestra el catálogo.
 */
void mostrarCatalogo(void)
{
  
  system("clear");
  printf ("Catálogo\n\n");
  printf ("\t[1] Espuma activa\n\n\t\t[A] Costo: $80.00\n\t\t[B] Descripción del paquete: Espuma activa, lavado, aspirado interior y secado.\n\n");
  printf ("\t[2] Cera líquida\n\n\t\t[A] Costo: $90.00\n\t\t[B] Descripción del paquete: Espuma activa, lavado, aspirado interior, secado y super encerado.\n\n");
  printf ("\t[3] Premium\n\n\t\t[A] Costo: $99.00\n\t\t[B] Descripción del paquete: Espuma activa, lavado, aspirado interior, secado, super encerado y lavado de chasis.\n\n\n");
  printf ("\tNOTAS IMPORTANTES:\n\n\t\t[a] Aspirar la cajuela tiene un costo extra de $10.00.\n\t\t[b] Camionetas o pick-ups tienen un costo extra de $10.00.\n\n");
  printf ("\tPRESIONA 'ENTER' PARA CONTINUAR.\n");
  getchar();
    
  return;
}

/**
 *@fn Procedimiento que muestra el registro de clientes.
 */
void mostrarMenuRegistroClientes(void)
{
  system("clear");
  printf ("Registro de clientes\n\n");
  printf ("\t[1] Agregar cliente\n\n");
  printf ("\t[2] Mostrar clientes\n\n");
  printf ("\t[3] Editar cliente(ID necesario)\n\n");
  printf ("\t[4] Eliminar cliente(ID necesario)\n\n");
  printf ("\t[5] Regresar al menú principal\n\n");
  
  return;
}

/**
 *@fn Procedimiento que muestra los reportes.
 */
void mostrarMenuReportes(void)
{
  system("clear");
  printf ("Reportes\n\n");
  printf ("\t[1] Ganancias\n\n");
  printf ("\t[2] Citas\n\n");
  printf ("\t[3] Programa de lealtad\n\n");
  printf ("\t[4] Regresar al menú principal\n\n");
  
  return;
}

/**
 *@fn Función que registra a los clientes.
 */
void registrarClientes(int numClientes, struct Datos* Clientes)
{
  system("clear");
  printf("\nDame los datos del cliente #%d:\n", numClientes);
  printf("\tIngrese el nombre del cliente usando el siguiente formato (ejemplo: Jose_Pablo_Montero): ");
  scanf(" %s", Clientes[numClientes].nombre);
  printf("\tIngresa la marca del vehiculo: ");
  fflush(stdin);
  scanf(" %s", Clientes[numClientes].marca);
  printf("\tIngresa el modelo del vehiculo: ");
  fflush(stdin);
  scanf(" %s", Clientes[numClientes].modelo);
  printf("\tIngresa el color del vehiculo: ");
  fflush(stdin);
  scanf(" %s", Clientes[numClientes].color);
  printf("\tIngresa las placas del vehiculo: ");
  fflush(stdin);
  scanf(" %s", Clientes[numClientes].placas);
  printf("\tIngresa el tipo de vehiculo. ([1] Camioneta o Pick-up [2]Auto): ");
  fflush(stdin);
  scanf(" %d", &Clientes[numClientes].tipoAuto);
  printf("\tIngresa el número de servicios que lleva el cliente: ");
  fflush(stdin);
  scanf(" %d", &Clientes[numClientes].numeroServicios);
  
  Clientes[numClientes].ID = numClientes;
  printf("\t\n\nDatos del cliente: %s\n\tID del cliente: %d\n\tMarca del vehiculo: %s\n\tModelo: %s\n\tColor: %s\n\tPlacas: %s\n\tNumero de servicios: %d\n\n",Clientes[numClientes].nombre,Clientes[numClientes].ID, Clientes[numClientes].marca, Clientes[numClientes].modelo, Clientes[numClientes].color, Clientes[numClientes].placas, Clientes[numClientes].numeroServicios);
  printf("Cliente registrado! Presiona 'ENTER' para continuar.");

  getchar();
  
  return;
  
}

/**
 *@fn Función que muestra a los clientes.
 */
void mostrarCliente(int numClientes, struct Datos* Clientes)
{
  int x;
  
  system("clear");
  printf("\n");
  
   for(x = 0; x < numClientes; x++)
    {
      printf("\tNombre del cliente: %s\n", Clientes[x].nombre);
      printf("\tID del cliente: %d\n", Clientes[x].ID);
      printf("\tMarca del vehículo: %s\n", Clientes[x].marca);
      printf("\tModelo del vehículo: %s\n", Clientes[x].modelo);
      printf("\tColor del vehículo: %s\n", Clientes[x].color);
      printf("\tPlacas del vehículo: %s\n", Clientes[x].placas);
      printf("\tTipo de vehículo([1]camioneta o pick-up [2]Auto): %d\n", Clientes[x].tipoAuto);
      printf("\tNúmero de servicios que lleva el cliente: %d\n\n", Clientes[x].numeroServicios);
    }
  
  printf("\n\nPresiona 'ENTER' para continuar");
  
  getchar();
  
  return;
}

/**
 *@fn Función que edita a los clientes.
 */
void editarCliente(int numClientes, struct Datos* Clientes)
{
  int x;

  system("clear");
  printf("\nIngresa el ID del cliente que deseas modificar:\n\n");
  scanf (" %d", &x);
  
  printf("\nDame los datos del cliente #%d:\n", x);
  printf("\tIngrese el nombre del cliente con el siguiente formato(ejemplo: Jose_Pablo_Montero): ");
  scanf(" %s", Clientes[x].nombre);
  printf("\tIngresa la marca del vehículo: ");
  fflush(stdin);
  scanf(" %s", Clientes[x].marca);
  printf("\tIngresa el modelo del vehículo: ");
  fflush(stdin);
  scanf(" %s", Clientes[x].modelo);
  printf("\tIngresa el color del vehículo: ");
  fflush(stdin);
  scanf(" %s", Clientes[x].color);
  printf("\tIngresa las placas del vehículo: ");
  fflush(stdin);
  scanf(" %s", Clientes[x].placas);
  printf("\tIngresa el tipo de vehículo. ([1] Camioneta o Pick-up [2]Auto): ");
  fflush(stdin);
  scanf(" %d", &Clientes[x].tipoAuto);
  printf("\tIngresa el número de servicios que lleva el cliente: ");
  fflush(stdin);
  scanf(" %d", &Clientes[x].numeroServicios);

  printf("\n\nDatos actualizados!\n\n");
  printf("\tCliente: %s\n\tMarca: %s\n\tModelo: %s\n\tColor: %s\n\tPlacas: %s\n\tTipo Auto ([1]camioneta o pick-up [2]Auto): %d\n\tNúmero de servicios: %d\n\n",Clientes[x].nombre, Clientes[x].marca, Clientes[x].modelo, Clientes[x].color, Clientes[x].placas, Clientes[x].tipoAuto, Clientes[x].numeroServicios);

  printf("Presiona 'ENTER' para continuar");
  
  getchar();
  
  return;
}

/**
 *@fn Función que eliminar a los clientes.
 */
void eliminarCliente(int numClientes, struct Datos* Clientes)
{
  int x, i;

  system("clear");
  printf("\nIngresa el ID del cliente que deseas eliminar:\n\n");
  scanf (" %d", &x);
  
  for (i = 0; i < numClientes; i ++)
    {
      if (x == Clientes[i].ID)
	{
	  int j;
	  for (j = i +1; j < numClientes; j ++)
	    {
	      Clientes[j - 1] = Clientes[j];
	      Clientes[j - 1].ID = Clientes[j - 1].ID - 1;
	    }
	  numClientes = numClientes - 1;
	  printf ("Eliminado con éxito!\n");
	  break;
	}
    }
  printf("Presiona 'ENTER' para continuar");
  
  getchar();
  
  return;
}

/**
 *@fn Función para agendar citas.
 */
void agendarCitas(int numCita, int numClientes, struct Agendar* Cita, struct Datos* Clientes, int miercoles[1], int hmiercoles[5], int jueves[1], int hjueves[5], int viernes[1], int hviernes[5], int sabado[1], int hsabado[5], int domingo[1], int hdomingo[5])
{	
  int x, i, existe = 0;
  int contadorDias = 1, contadorHoras = 1;

  system("clear");
  
  while (existe != 6969)
    {
      printf ("Introduce el ID del cliente que desea agendar: ");
      scanf (" %d", &x);
      existe = x;
      
      for (i = 0; i < numClientes; i ++)
	{
	  if (x == Clientes[i].ID)
	    {
	      printf ("Cliente encontrado!\n");
	      existe = 6969;
	      
	      printf ("\t[1] Miércoles\n\t[2] Jueves\n\t[3] Viernes\n\t[4] Sábado\n\t[5] Domingo\n");
	      
	      do 
		{
		  printf ("Selecciona el día que deseas agendar: ");
		  scanf (" %d", &Cita[numCita].dia);
		  
		  switch (Cita[numCita].dia)
		    {
		    case 1:
		      if (miercoles[0] == 5)
			{
			  printf ("Día lleno\n");
			  contadorDias = 1;
			  getchar();
			}
		      else
			{
			  contadorDias = 0;
			}
		      break;
		      
		    case 2:
		      if (jueves[0] == 5)
			{
			  printf ("Día lleno\n");
			  contadorDias = 1;
			  getchar(); 
			}
		      else
			{
			  contadorDias = 0;
			}
		      break;
		      
		    case 3:
		      if (viernes[0] == 5)
			{
			  printf ("Día lleno\n");
			  contadorDias = 1;
			  getchar();
			}
		      else
			{
			  contadorDias = 0;
			}
		      break;
		      
		    case 4:
		      if (sabado[0] == 5)
			{
			  printf ("Día lleno\n");
			  contadorDias = 1;
			  getchar();
			}
		      else
			{
			  contadorDias = 0;
			}
		      break;
		      
		    case 5:
		      if (domingo[0] == 5)
			{
			  printf ("Día lleno\n");
			  contadorDias = 1;
			  getchar();
			}
		      else
			{
			  contadorDias = 0;
			}
		      break;
		      
		    default:
		      break;		
		    }
		} while (contadorDias != 0);
	      
	      
	      printf ("\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
	      
	      do 
		{
		  printf ("Selecciona la hora que deseas agendar: ");
		  scanf (" %d", &Cita[numCita].hora);
		  
		  switch (Cita[numCita].dia)
		    {
		    case 1:
		      if (hmiercoles[Cita[numCita].hora - 1] == 1)
			{
			  printf ("Horario ocupado\n");
			  contadorHoras = 1;
			  getchar();
			}
		      else
			{
			  mostrarCatalogo();
			  printf ("Ingrese el paquete que desea agregar: ");
			  scanf (" %d", &Cita[numCita].paquete);
			  switch (Cita[numCita].paquete)
			    {
			    case 1:
			      
			      Cita[numCita].paquete = 80;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el miércoles en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hmiercoles[Cita[numCita].hora - 1] = 1;
			      miercoles[0] = miercoles[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 2:
			      Cita[numCita].paquete = 90;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el miércoles en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hmiercoles[Cita[numCita].hora - 1] = 1;
			      miercoles[0] = miercoles[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 3:
			      Cita[numCita].paquete = 99;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el miércoles en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hmiercoles[Cita[numCita].hora - 1] = 1;
			      miercoles[0] = miercoles[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    default:
			      printf ("Opción no válida\n");
			      break;
			    }
			  
			}
		      break;
		      
		    case 2:
		      if (hjueves[Cita[numCita].hora - 1] == 1)
			{
			  printf ("Horario ocupado\n");
			  contadorHoras = 1;
			  getchar(); 
			}
		      else
			{
			  mostrarCatalogo();
			  printf ("Ingrese el paquete que desea agregar: ");
			  scanf (" %d", &Cita[numCita].paquete);
			  switch (Cita[numCita].paquete)
			    {
			    case 1:
			      Cita[numCita].paquete = 80;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el jueves en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hjueves[Cita[numCita].hora - 1] = 1;
			      jueves[0] = jueves[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 2:
			      Cita[numCita].paquete = 90;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el jueves en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hjueves[Cita[numCita].hora - 1] = 1;
			      jueves[0] = jueves[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 3:
			      Cita[numCita].paquete = 99;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el jueves en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hjueves[Cita[numCita].hora - 1] = 1;
			      jueves[0] = jueves[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    default:
			      printf ("Opción no válida\n");
			      break;
			    }
			}
		      break;
		      
		    case 3:
		      if (hviernes[Cita[numCita].hora - 1] == 1)
			{
			  printf ("Horario ocupado\n");
			  contadorHoras = 1;
			  getchar();
			}
		      else
			{
			  mostrarCatalogo();
			  printf ("Ingrese el paquete que desea agregar: ");
			  scanf (" %d", &Cita[numCita].paquete);
			  switch (Cita[numCita].paquete)
			    {
			    case 1:
			      Cita[numCita].paquete = 80;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el viernes en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hviernes[Cita[numCita].hora - 1] = 1;
			      viernes[0] = viernes[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 2:
			      Cita[numCita].paquete = 90;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el viernes en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hviernes[Cita[numCita].hora - 1] = 1;
			      viernes[0] = viernes[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 3:
			      Cita[numCita].paquete = 99;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el viernes en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hviernes[Cita[numCita].hora - 1] = 1;
			      viernes[0] = viernes[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    default:
			      printf ("Opción no válida\n");
			      break;
			    }
			}
		      break;
		      
		    case 4:
		      if (hsabado[Cita[numCita].hora - 1] == 1)
			{
			  printf ("Horario ocupado\n");
			  contadorHoras = 1;
			  getchar();
			}
		      else
			{
			  mostrarCatalogo();
			  printf ("Ingrese el paquete que desea agregar: ");
			  scanf (" %d", &Cita[numCita].paquete);
			  switch (Cita[numCita].paquete)
			    {
			    case 1:
			      Cita[numCita].paquete = 80;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el sábado en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hsabado[Cita[numCita].hora - 1] = 1;
			      sabado[0] = sabado[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 2:
			      Cita[numCita].paquete = 90;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el sábado en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hsabado[Cita[numCita].hora - 1] = 1;
			      sabado[0] = sabado[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    case 3:
			      Cita[numCita].paquete = 99;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el sábado en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hsabado[Cita[numCita].hora - 1] = 1;
			      sabado[0] = sabado[0] + 1;
			      printf ("\nAgendado\n");
			      break;
			      
			    default:
			      printf ("Opción no válida\n");
			      break;
			    }
			}
		      break;
		      
		    case 5:
		      if (hdomingo[Cita[numCita].hora - 1] == 1)
			{
			  printf ("Horario ocupado\n");
			  contadorHoras = 1;
			  getchar();
			}
		      else
			{
			  mostrarCatalogo();
			  printf ("Ingrese el paquete que desea agregar: ");
			  scanf (" %d", &Cita[numCita].paquete);
			  switch (Cita[numCita].paquete)
			    {
			    case 1:
			      Cita[numCita].paquete = 80;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el domingo en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hdomingo[Cita[numCita].hora - 1] = 1;
			      domingo[0] = domingo[0] + 1;
			      			      
			      printf ("\nAgendado\n");
			      break;
			      
			    case 2:
			      Cita[numCita].paquete = 90;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el domingo en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hdomingo[Cita[numCita].hora - 1] = 1;
			      domingo[0] = domingo[0] + 1;
			      			      
			      printf ("\nAgendado\n");
			      break;
			      
			    case 3:
			      Cita[numCita].paquete = 99;
			      printf ("Por $10 más, ¿desea que aspiremos su cajuela? ([1]Si [2]No): ");
			      scanf (" %d", &Cita[numCita].cajuela);
			      if (Cita[numCita].cajuela == 1)
				{
				  Cita[numCita].total = Cita[numCita].paquete + 10;
				}
			      else if (Cita[numCita].cajuela == 2)
				{
				  Cita[numCita].total = Cita[numCita].paquete;
				}
			      
			      if (Clientes[x].tipoAuto == 1)
				{
				  Cita[numCita].total = Cita[numCita].total + 10;
				}
			      else if (Clientes[x].tipoAuto == 2)
				{
				  Cita[numCita].total = Cita[numCita].total;
				}

			      
			      Clientes[x].numeroServicios = Clientes[x].numeroServicios + 1;
			      printf ("\n\n\t[1] 10:00 - 11:00 hrs\n\t[2] 11:00 - 12:00 hrs\n\t[3] 12:00 - 13:00 hrs\n\t[4] 13:00 - 14:00 hrs\n\t[5] 14:00 - 15:00 hrs\n");
			      printf("\t%s, agendó cita para el domingo en el horario #%d con un costo total de: $%d\n",Clientes[x].nombre, Cita[numCita].hora, Cita[numCita].total);
			      printf("\tTienes %d puntos de lealtad.\n", Clientes[x].numeroServicios);
			      contadorHoras = 0;
			      hdomingo[Cita[numCita].hora - 1] = 1;
			      domingo[0] = domingo[0] + 1;
			      
			      printf ("\nAgendado\n");
			      break;
			      
			    default:
			      printf ("Opción no válida\n");
			      break;
			    }
			}
		      break;
		      
		    default:
		      break;		
		    }
		} while (contadorHoras != 0);
	      
	    }
	   else
	    {
	      printf ("Cargando... (Ingresar '6969' para regresar al menú)\n");
	    }	
	}
      
    }
  printf("Presiona 'ENTER' para continuar.");
  getchar();
  
  return;
}
/**
 *@fn Función que muestra las ganancias.
 */

void mostrarGanancias(int  numCita, struct Agendar* Cita)
{
  int ganancias = 0, dia, i;

  system("clear");
  printf ("\n\t[1] Miércoles\n\t[2] Jueves\n\t[3] Viernes\n\t[4] Sábado\n\t[5] Domingo\n\n");
  printf("Dime el número de día en el que quieres consultar las ganancias: ");
  scanf(" %d", &dia);

  for(i = 0; i < numCita; i++)
    {
      if(Cita[i].dia == dia)
	{
	  ganancias = ganancias + Cita[i].total;
	}
    }
  printf("\nLas ganancias totales del día fueron: $%d\n\n", ganancias);
  printf("************************************************************\n");
  printf("Presiona 'ENTER' para continuar.\n\n");
  
  getchar();
  
  return;
  
}
/**
 *@fn Funcion que muestra las citas.
 */

void mostrarCitas(int  numCita, struct Agendar* Cita, int hmiercoles[5], int hjueves[5], int hviernes[5], int hsabado[5], int hdomingo[5])
{
  int x,i;
  
  system("clear");
  printf ("\n\t[1] Miércoles\n\t[2] Jueves\n\t[3] Viernes\n\t[4] Sábado\n\t[5] Domingo\n");
  printf("Por favor, ingrese el numero de dia que quisiera ver: ");
  scanf(" %d", &x);
  switch(x)
    {
    case 1:
      printf("Miércoles\n\n");
      printf ("\t[%d] 10:00 - 11:00 hrs\n\t[%d] 11:00 - 12:00 hrs\n\t[%d] 12:00 - 13:00 hrs\n\t[%d] 13:00 - 14:00 hrs\n\t[%d] 14:00 - 15:00 hrs\n", hmiercoles[0], hmiercoles[1], hmiercoles[2], hmiercoles[3], hmiercoles[4]);
      printf("\n");
      break;

      case 2:
      printf("Jueves\n\n");
      printf ("\t[%d] 10:00 - 11:00 hrs\n\t[%d] 11:00 - 12:00 hrs\n\t[%d] 12:00 - 13:00 hrs\n\t[%d] 13:00 - 14:00 hrs\n\t[%d] 14:00 - 15:00 hrs\n", hjueves[0], hjueves[1], hjueves[2], hjueves[3], hjueves[4]);
      printf("\n");
      break;

      case 3:
      printf("Viernes\n\n");
      printf ("\t[%d] 10:00 - 11:00 hrs\n\t[%d] 11:00 - 12:00 hrs\n\t[%d] 12:00 - 13:00 hrs\n\t[%d] 13:00 - 14:00 hrs\n\t[%d] 14:00 - 15:00 hrs\n", hviernes[0], hviernes[1], hviernes[2], hviernes[3], hviernes[4]);
      printf("\n");
      break;

      case 4:
      printf("Sábado\n\n");
      printf ("\t[%d] 10:00 - 11:00 hrs\n\t[%d] 11:00 - 12:00 hrs\n\t[%d] 12:00 - 13:00 hrs\n\t[%d] 13:00 - 14:00 hrs\n\t[%d] 14:00 - 15:00 hrs\n", hsabado[0], hsabado[1], hsabado[2], hsabado[3], hsabado[4]);
      printf("\n");
      break;

      case 5:
      printf("Domingo\n\n");
      printf ("\t[%d] 10:00 - 11:00 hrs\n\t[%d] 11:00 - 12:00 hrs\n\t[%d] 12:00 - 13:00 hrs\n\t[%d] 13:00 - 14:00 hrs\n\t[%d] 14:00 - 15:00 hrs\n", hdomingo[0], hdomingo[1], hdomingo[2], hdomingo[3], hdomingo[4]);
      printf("\n");
      break;
    }
  printf("Si en la posicion del horario se encuentra un 1, significa que ya esta ocupado, si se encuentra un 0 significa que esta libre.\n");
  printf("\nPresiona la tecla 'ENTER' para continuar.");

  getchar();
  return;
}

/**
 *@fn Funcion que muestra el programa de lealtad.
 */

void mostrarProgramaLealtad(int numClientes, struct Datos* Clientes)
{
  int x, opcion;
  
  for(x = 0; x < numClientes; x++)
    {
      printf("\tEl número de cliente: %d,\n\tTiene: %d Puntos de lealtad\n",Clientes[x].ID, Clientes[x].numeroServicios);
      if(Clientes[x].numeroServicios >= 5)
	{
	  printf("\tTiene cupones disponibles!!\n\n");
	  printf("Desea gastar los cupones del cliente? ([1]Si! [2]No): ");
	  scanf(" %d", &opcion);
	  switch(opcion)
	    {
	    case 1:
	      printf("\tCupón válido por un lavado gratis en cualquiera de nuestros paquetes!!!!\n");
	      printf("\tPresente su cupón en caja. (UwU)\n");
	      Clientes[x].numeroServicios = Clientes[x].numeroServicios - 5;

	      printf("Presiona 'ENTER' para continuar.");

	      getchar();
	      break;

	    case 2:
	      break;

	    default:
	      printf("Opción inválida, por favor, intente de nuevo.\n");
	      break;
	      
	    }
	}
      else
	{
	  printf("\tAún no tienes cupones disponibles (UnU)\n\n");
	  printf("Presiona 'ENTER' para continuar");
	  
	  getchar();
	}
    }
  
  return;
}
