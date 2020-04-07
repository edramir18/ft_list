# Apuntadores a Funciones (Function Pointer)

Una caracteristica del lenguaje C es la posibilidad de pasar como argumentos de
una funcion un apuntador a otra funcion. pudiendo asi alterar o ampliar el
comportamiento de una funcion sin modificar el codigo principal.

Haciendo uso de apuntadores sin tipo *(void *)* podemos realizar operaciones
que de otra forma necesitarian repetir codigo modificando solo el tipo de datos.

Esta capacidad tambien nos permita ajustar el funcionamiento de una funcion,
haciendo que de acuerdo a la funcion que le pasemos esta se comporte de una
manera u otra.

El nombre con el que designaremos la funcion como argumento de otra, es solo un
alias y sirve para identificarla en nuestro codigo. Es de vital importancia
prestar atencion al retorno y tipo de datos que recibe la funcion, ya que estos
deben coincidir con la funcion que deseamos utilizar.

## Definicion de una funcion
El siguiente programa muestra el funcionamiento basico de funciones como
argumentos:
``` c
#include <stdio.h>

int     ft_add_int(int a, int b)
{
    return (a + b);
}

void    ft_print_result(int a, int b, int (*op)(int, int)))
{
    printf("Operadores: %d %d, Resultado: %d", a, b, op(a, b));
}

int     main(void)
{
    ft_print_result(4, 5, ft_add_int);
}
```
> Ver archivo operadores.c para el codigo completo.

En la funcion *ft_print_result* hemos utilizado la declaracion de una funcion
que retorna un entero y recibe dos argumentos de tipo entero. La sintaxis
estandar indica que utilizemos el alias de la funcion entre parentesis y
precedido por un asterisco para indicar que estamos utilizando un apuntador:
*(* op)*, esta sintaxis puede prestarse a confuciones cuando el tipo de retorno
es un apuntador, por ejemplo *void *(*funct)(int, int0)*, por lo que otra
forma de escribir el prototipo de la funcion seria la siguiente:

``` c
void    ft_print_result(int a, int b, int op(int, int));
```

## Usando varias funciones
El progama anterior solo utiliza una funcion y no nos muestra con claridad la
potencia de los apuntadores de funciones. Vamos a ampliar el ejemplo incluyendo
dos funciones adicionales para ver mas claro este punto:

``` c
void    ft_sub_int(int a, int b)
{
    return (a - b);
}

void    ft_mult_int(int a, int b)
{
    return (a * b);
}

int     main(void)
{
    ft_print_result(5, 4, ft_sum_int);
    ft_print_result(5, 4, ft_sub_int);
    ft_print_result(5, 4, ft_mult_int);
}
```

> Ver archivo operadores.c para el codigo completo.

Al utilizar un apuntador de funcion como argumento para la funcion 
*ft_print_result* hemos podido reutilizarla sin necesidad de realizar ningun
ajuste, pudiendo seguir ampliando su utilidad usando nuevas funciones de la
forma *int (* op)(int, int)*

## Utilizando apuntadores sin tipo

Para ilustrar el funcionamiento de los apuntadores de funciones, con apuntadores
sin tipo implementare una funcion sencilla de ordenamiento, que de acuerdo a la
funcion de comparacion que utilizemos podemos ordenar un tipo de dato u otro.

El prototipo de la funcion seria el siguiente:
``` c
void    ft_sort(int n, void *arr, int cmp(void *, void *), size_t bytes);
```

El primer argumento indica el numero de elementos del arreglo, el segundo
argumento indica un apuntador a un arreglo de datos que nos interesa ordenar,
el tercer argumento la funcion de comparacion que utilizaremos para ordenar los
datos. Debido a que no podemos movernos sin conocer el tipo de datos en un
arreglo *(void *)* debemos proporcionar el tamaño en bytes del tipo de datos que
estemos utilizando como ultimo argumento a la funcion.

Al momento de ordenar los datos podemos realizar el 
``` c

```
