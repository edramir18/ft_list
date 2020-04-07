# Listas - Funciones principales

Las listas son una estructura de datos que nos permite almacenar una coleccion 
de elementos, sin conocer previamente el numero total de ellos.
Se recomienda cuando es necesario trabajar con un conjunto de elementos a los 
cuales estamos añadiendo y eliminando elementos de forma continua.
La estructura que nos permitira trabajar con la lista seria la siguiente:
``` c
typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}               t_list;
```
La estructura contiene 2 apuntadores (*pointer*), uno para indicar el siguiente 
elemento de la lista: *next*, y el otro es un apuntador sin tipo *(void *)*, que
nos permitira almacenar cualquier elemento en esta lista sin necesidad de
redefinir el tipo de la variable utilizada.
A cada elemento de una lista se le suele denominar **node**, para indicar que es
una estructura de datos que contiene la informacion necesaria para trabajar con
las distintas funciones de listas.

>**DISCLAIMER**: La implementacion de las funciones descritas en las siguientes
secciones, son asignaciones de la academia y **PERSONALMENTE** no considero
adecuardo incluir mi implementacion en este proyecto. Se recomienda el uso de la
libreria **libft** a fin de verificar los ejemplos descritos en este proyecto.

## Inicializacion

Para el manejo de la lista utilizaremos un apuntador de tipo *t_list*, el cual 
debe ser inicializado en **NULL**. No es necesario reservar memoria con *malloc*
o crear una estructura adicional para manejar la lista

``` c
t_list  *list;

list = NULL;
```

## Data

Para agregar nuevos elementos a la lista debemos crear un nuevo nodo por medio
de la funcion *ft_lstnew*, a la cual pasaremos un apuntador al dato que deseamos
almacenar. El prototipo de la funcion seria el siguiente:

``` c
t_list  *ft_lstnew(void *content);
```

Una vez tenemos el nodo con la informacion requerida, procedemos a agregarlo a
la lista con cualquiera de estas funciones: **ft_lstadd_front** para agregar
elementos al inicio de la lista y **ft_lstadd_back** para agregar elementos al
final de la lista.


``` c
void    ft_lstadd_front(t_list **alist, t_list *newc);
void    ft_lstadd_back(t_list **alst, t_list *newc);
```

### Extracto de codigo para inicializar y agregar un nuevo nodo
``` c
char    *data;
t_list  *list;
t_list  *node;

data = strdup("Hello World");
list = NULL;
node = ft_lstnew(data);
ft_lstadd_front(&list, node);
```

>**NOTA:** Se omite la verificacion del retorno de las funciones para simplicar
el ejemplo, siempre se debe verificar que los valores devueltos contengan algun 
valor valido, y en caso de error tratarlo de manera adecuada.

## Borrado de un elemento de la lista.
Para eliminar un nodo de la lista debemos proveer una funcion que sea capaz de
liberar de manera adecuada todas las reservas de memoria utilizadas por el
apuntador *content*.

Teniendo la siguiente estructura y funcion de borrado

``` c
typedef struct  s_user
{
    char    *first_name;
    char    *last_name;
}               t_user;

void    ft_delete_user(void *data)
{
    t_user	*user;
    user = (t_user *)data;
    free(user->first_name);
    free(user->last_name);
    free(user);
}
```

Al momento de liberar una nodo con este tipo de datos podemos invocar la
funcion *ft_lstdelone* para realizar la accion de limpieza. Esto nos permite
ahorrarnos trabajo y concentrar nuestro esfuerzo en el caso que nos interese
resolver.
La funcion de limpieza utiliza un apuntador de tipo *void*, debido a que es
requerido por la siguienete funcion

``` c
void    ft_lstdelone(t_list *lst, void (*del)(void *));
```

### Extracto de codigo para eliminar un nodo.

``` c
t_user	*user;
t_list	*node;

user = malloc(sizeof(t_user));
user->first_name = ft_strdup("Eduardo");
user->last_name = ft_strdup("Ramirez");
node = ft_lstnew(user);
ft_lstdelone(node, ft_delete_user);
```

Como puede verse en el codigo precedente no se necesita acceso a la lista, para
realizar esta operacion ya que solo se trata de liberar el contenido del nodo.
Para eliminar de la lista se utilizan otra funcion que veremos a continuacion.

### Eliminar nodos en una lista.

La funcion precedente es util para asegurarnos que eliminamos adecuadamente un
nodo que aun no ha sido agregado a una lista o ya no es parte de la lista.
Cuando queremos eliminar un nodo perteneciente a una lista debemos peocuparnos
por eliminar la referencias utilizados en otro nodos, y ajustar la lista de 
acuerdo a los nuevos elementos.

Pongamos por ejemplo la funcion *ft_lstdel_front*, la cual se encargara de
borrar el primer nodo de la lista y ajustar los apuntadores de modo que la lista
siga siendo funncional.

``` c
void    ft_lstdel_front(t_list **list, void del(void *))
{
    t_list  *node;

    if (list == NULL || *list == NULL)
        return ;
    node = *list;
    *list = (*list)->next;
    ft_lstdelone(node, del);
}
```

### Buscar y eliminar un nodo

Cuando necesitamos eliminar un nodo de la lista, y este no se encuentra en la
posicion inicial o final de la lista, necesitamos de un mecanismo para
identificar cual es el nodo en cuestion y luego ajustar los demas nodos para
que la lista siga operativa.

La siguiente funcion nos permite eliminar el primer elemento que coincida con un
criterio de busqueda.

``` c
void    ft_lstdel_one(t_list **list, void *data, int cmp(void *, void*), void del(void *))
{
    t_list  *node;
    t_list  *prev;

    prev = NULL;
    if (list == NULL || *list == NULL)
        return ;
    node = *list;
    while (node != NULL)
    {
        if (cmp(data, node->content) == 0)
        {
            if (prev == NULL)
                *list = node->next;
            else
                prev->next = node->next;
            ft_lstdelone(node, del);
            break;
        }
        prev = node;
        node = node->next;
    }
}
```

## Borrar una lista

Para eliminar todos los elementos de una lista de manera segura y confiable
haremos uso de la funcion *ft_lstclear*, la cual se encargara de iterar por
cada uno de nodos de la lista e invocara la funcion que le pasemos como
segundo argumento, liberando la reserva del nodo y colocando a **NULL** el
contenido de la lista

``` c
void    ft_lstclear(t_list **lst, void (*del)(void *));
```

> El archivo *delete.c* contiene un ejemplo mas completo de todas las funciones
descritas hasta ahora.

## Longitud de la lista

Cuando estamos trabajando con lista es necesario conocer el numero de elementos
que componen la lista en un momento determinado, por lo cual utilizaremos una
funcion que se encarga de iterar por toda la lista y contar el numero de nodos
que contiene. El unico parametro que requiere es el apuntador al inicio de la
lista.

``` c
int     ft_lstsize(t_list *lst);
```

>Debido a como interactuamos con la lista realmente podemos pasar como parametro
cualquier elemento de la lista y desde esa posicion determinar cuantos elementos
existen desde alli.

## Iteracion de una lista

Al momento de trabajar con una lista existen dos modos de recorrerla y obtener
cada elemento a fin de ejecutar alguna operacion con cada uno de ellos.

### Utilizando un bucle While

Este es la manera mas sencilla y facil de manejar, dependiendo si nos interesa
conservar el apuntador a la posicion inicial o no, podemos hacer uso de una 
variable auxiliar para realizar la iteracion

``` c
void    ft_print_content(t_list *list)
{
    t_list  *aux;

    aux = list;
    while (aux != NULL)
    {
        printf("%d\n", *((int *)aux->content));
        aux = aux->next;
    }
    printf("The list has %d element\n", ft_lstsize(list));
}
```
### Utilizando la funcion ft_lstiter

El proyecto libft nos recomienda implementar una funcion que nos permite iterar
uno a uno los elementos de la lista, necesitando como primer parametro un
puntero a la lista que nos interesa recorrer y como segundo parametro una
funcion que recibe un parametro sin tipo *(void *)*, para ejecutar la operacion
que nos interesa en cada elemento de la lista.

``` c
void	ft_lstiter(t_list *lst, void (*f)(void *));
```

#### Extracto de codigo que utiliza la funcion ft_lstiter
``` c
void	ft_print_number(void *data)
{
    int     *number;

    number = (int *)data;
    printf("%d\n", number);
}

> Dentro de la funcion donde estemos usando la lista hacemos el llamado

ft_lstiter(list, ft_print_number);
```

## Duplicar una lista

En algunas ocasiones nos interesa generar una lista a partir de otra, o aplicar
alguna operacion en cada elemento de la lista y generar una lista con los
resultados de esa operacion. En estos casos usamos la siguiente funcion:

``` c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
Esta funcion utiliza tres parametros y retorna un apuntador a la nueva lista,
el primer parametro es el apuntador a la lista; el segundo parametro la funcion
que deseamos aplicar para obtener un nuevo elemento de la lista; y el ultimo
parametro es un funcion de borrado para los nuevos elementos de la lista.

Es importar aclarar que el contenido que tendra la lista nueva no tiene que ser
del mismo tipo que la lista original, dependera de nuestra funcion **f** el tipo
de dato que retornemos y almacenemos en la lista nueva.

###
``` c
void    *ft_pow_number(void *data)
{
    int     nb;
    void    *pw;

    nb = *((int *) data);
    pw = malloc(sizeof(long));
    if (pw == NULL)
        return (NULL);
    *((long int *)pw) = nb * nb;
    return (pw);
}

> En la funcion que nos interesa la lista nueva
lstnew = ft_lstmap(lst, ft_pow_number, free);
```

> En el archivo iterar.c podremos observar un ejemplo mas extenso de las
funciones descritas hasta ahora.