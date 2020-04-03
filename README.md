# Listas - Funciones principales

Las listas son una estructura de datos que nos permite almacenar una coleccion 
de elementos, sin conocer previamente el numero total de ellos.
Se recomienda cuando es necesario trabajar con un conjunto de elementos a los 
cuales estamos añadiendo y eliminando elementos de forma continua.
La estructura que nos permitira trabajar con la lista seria la siguiente:
``` c
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
```
La estructura contiene 2 apuntadores (*pointer*), uno para indicar el siguiente 
elemento de la lista: *next*, y el otro es un apuntador sin tipo *(void *)*, que
nos permitira almacenar cualquier elemento en esta lista sin necesidad de
redefinir el tipo de la variable utilizada.
A cada elemento de una lista se le suele denominar **node**, para indicar que es
una estructura de datos que contiene la informacion necesaria para trabajar con
las distintas funciones de listas.

## Inicializacion

Para el manejo de la lista utilizaremos un apuntador de tipo *t_list*, el cual 
debe ser inicializado en **NULL**. No es necesario reservar memoria con *malloc*
o crear una estructura adicional para manejar la lista

``` c
t_list	*list;

list = NULL;
```

## Data

Para agregar nuevos elementos a la lista debemos crear un nuevo nodo por medio
de la funcion *ft_lstnew*, a la cual pasaremos un apuntador al dato que deseamos
almacenar. El prototipo de la funcion seria el siguiente:

``` c
t_list	*ft_lstnew(void *content);
```

Una vez tenemos el nodo con la informacion requerida, procedemos a agregarlo a
la lista con cualquiera de estas funciones: **ft_lstadd_front** para agregar
elementos al inicio de la lista y **ft_lstadd_back** para agregar elementos al
final de la lista.


``` c
void	ft_lstadd_front(t_list **alist, t_list *newc);
void	ft_lstadd_back(t_list **alst, t_list *newc);
```

### Extracto de codigo para inicializar y agregar un nuevo nodo
``` c
char	*data;
t_list	*list;
t_list	*node;

data = strdup("Hello World");
list = NULL;
node = ft_lstnew(data);
ft_lstadd_front(&list, node);
```

**NOTA:** Se omite la verificacion del retorno de las funciones para simplicar
el ejemplo, siempre se debe verificar que los valores devueltos contengan algun 
valor valido, y en caso de error tratarlo de manera adecuada.

## Borrado de un elemento de la lista.
Para eliminar un nodo de la lista debemos proveer una funcion que sea capaz de
liberar de manera adecuada todas las reservas de memoria utilizadas por el
apuntador *content*.

Teniendo la siguiente estructura y funcion de borrado

``` c
typedef struct	s_user
{
	char	*first_name;
	char	*last_name;
}				t_user;

void	ft_delete_user(void *data)
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
void	ft_lstdelone(t_list *lst, void (*del)(void *));
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
Para eliminar de la lista se utilizan otros metodos y funciones que veremos a 
continuacion.

## Borrar una lista

Para eliminar todos los elementos de una lista de manera segura y confiable
haremos uso de la funcion *ft_lstclear*, la cual se encargarra de iterar por
cada uno de nodos de la lista e invocara la funcion que le pasemos como
segundo argumento, liberando la reserva del nodo y colocando a **NULL** el
contenido de la lista


``` c
void	ft_lstclear(t_list **lst, void (*del)(void *));
```

> El archivo *delete.c* contiene un ejemplo mas completo de todas las funciones
descritas hasta ahora.

``` c
```