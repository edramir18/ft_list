# Listas - Funciones principales

Las listas son una estructura de datos que nos permite almacenar una coleccion 
de elementos, sin conocer previamente el numero total de ellos.
Se recomienda cuando es necesario trabajar con un conjunto de elementos a los 
cuales estamos añadiendo y elementos de forma continua.
La estructura que nos permitira trabajar con la lista seria la siguiente:
``` c
typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;
```
La estructura contiene 2 apuntadores (*pointer*), uno para indicar el siguiente 
elemento de la lista: *next*, y el otro es un apuntador sin tipo, que nos 
permitira almacenar cualquier elemento en esta lista sin necesidad de redifinir 
el tipo de la variable.

## Inicializacion

Para el manejo de la lista utilizaremos un apuntador de tipo *t_list*, el cual 
debe ser inicializado en **NULL**. No es necesario reservar memoria con *malloc*
o crear una estructura adicional para manejar la lista

``` c
t_list	*list;

list = NULL;
```

## Data

Para agregar nuevos elementos a la lista debemos crearn nuevo nodo por medio de
la funcion *ft_lstnew*, a la cual pasaremos un apuntador al tipo de datos que
deseamos almacenar. El prototipo de la funcion seria el siguiente:

``` c
t_list	*ft_lstnew(void *content);
```
Al tener el nodo con la informacion requerida, procedemos a agregarlo a la lista
por medio de dos funciones: **ft_lstadd_front** para agregar elementos al inicio
de la lista y **ft_lstadd_back** para agregar elementos al final de la lista.


``` c
void	ft_lstadd_front(t_list **alist, t_list *newc);
void	ft_lstadd_back(t_list **alst, t_list *newc);
```
``` c
```
