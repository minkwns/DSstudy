#include <stdio.h>
#include <stdlib.h>

typedef int	list_data;

typedef struct		s_node
{
	list_data		data;
	struct s_node	*next;
}					t_node;

typedef struct  s_list
{
    t_node      *head;
    t_node      *tail;
	t_node		*cur;
	t_node		*before;
}               t_list;



void	list_init(t_list *list)
{
	list->head = (t_node *)malloc(sizeof(t_node));  // make dummy head node
	list->tail = (t_node *)malloc(sizeof(t_node));  // make dummy tail node
	list->head->next = list->tail;\
}

void	list_insert_head(t_list *list, list_data data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;

	node->next = list->head->next;
	list->head->next = node;
}

void	show_list(t_list list)
{
	printf("----- show list -----\n");
	list.cur = list.head;
	while (list.cur->next != list.tail)
	{
		list.cur = list.cur->next;
		printf("current node address : %p, data : %d\n", list.cur, list.cur->data);
	}
}

void	free_all(t_list *list)
{
	list->cur = list->head;
	while (list->cur != list->tail)
	{
		list->before = list->cur;
		list->cur = list->cur->next;
		free(list->before);
	}
	free(list->cur);
}

void	invert(t_list *list)
{
	list->cur = list->tail;
	while (list->cur != list->head)
	{
		list->before = list->head;
		while (list->before->next != list->cur)  // find before node
			list->before = list->before->next;
		list->cur->next = list->before;
		list->cur = list->before;
	}

	// chane head and tail
	list->cur = list->head;
	list->head = list->tail;
	list->tail = list->cur;
}



int     main(void)
{
    t_list  list;  // single linked list
	int		i;

	list_init(&list);
	i = 0;
	while (++i <= 5)
		list_insert_head(&list, i);  //  data insert 1 ~ 5
	show_list(list);  // show node address and data
	invert(&list);
	show_list(list);  // show node address and data
	free_all(&list);
}