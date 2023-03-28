#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_answer.c"

typedef struct
{
    char nombre[30];
    char apellido[30];
    int edad;
    int telefono;
    char direccion[30];
    char numeroSocial[30];
    char listaMedicos[30];
}Datos;

void registrarPaciente(List* lista)
{
    Datos* paciente = (Datos*)malloc(sizeof(Datos));
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", paciente->nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", paciente->apellido);
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &paciente->edad);
    printf("Ingrese el telefono del paciente: ");
    scanf("%d", &paciente->telefono);
    printf("Ingrese la direccion del paciente: ");
    scanf("%s", paciente->direccion);
    printf("Ingrese el numero de seguro social del paciente: ");
    scanf("%s", paciente->numeroSocial);
    printf("Ingrese el nombre del medico asignado al paciente: ");
    scanf("%s", paciente->listaMedicos);

    pushBack(lista, paciente);
}

void mostrarPaciente(List* lista, Datos* paciente)
{
    char nombre[30];
    char apellido[30];
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellido);

    Datos* aux = firstList(lista);
    
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, nombre) == 0 && strcmp(aux->apellido, apellido) == 0)
        {
            printf("Nombre: %s\n", aux->nombre);
            printf("Apellido: %s\n", aux->apellido);
            printf("Edad: %d\n", aux->edad);
            printf("Telefono: %d\n", aux->telefono);
            printf("Direccion: %s\n", aux->direccion);
            printf("Numero de seguro social: %s\n", aux->numeroSocial);
            printf("Medico asignado: %s\n", aux->listaMedicos);
            break;
        }

        else if (aux != lista->tail)
        {
            aux = nextList(lista);
        }
        else
        {
            printf("No se encontro el paciente\n");
            break;
        }
    }

}

int main()
{
    List* lista = createList();
    Datos *p = (Datos*)malloc(sizeof(Datos));

    int opcion = 1;

    while (opcion != 0)
    {
        printf("Que desea hacer?\n");
        printf("1. Registrar un paciente\n");
        printf("2. Mostrar datos de un paciente\n");
        printf("3. Eliminar paciente");
        printf("4. Mostrar todos los pacientes\n");
        printf("5. Mostrar todos los pacientes sin un medico asignado\n");
        printf("6. Asignar medico a paciente\n");
        printf("7. Desasignar medico de paciente\n");
        printf("9. Importar pacientes desde un archivo CSV\n");
        printf("10. Exportar pacientes a un archivo CSV\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                registrarPaciente(lista);
                break;
            }
            case 2:
            {
                mostrarPaciente(lista, p);
                break;
            }
        }
    }



}
