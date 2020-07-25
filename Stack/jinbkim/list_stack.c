  
#include <stdio.h>
#include <stdlib.h>

typedef	int	stack_data;

typedef struct		s_node
{
	stack_data		data;
	struct s_node	*next;
}					t_node;

typedef struct	s_stack
{
	t_node		*head;
}				t_stack;



void		init(t_stack *s)
{
	s->head = NULL;
}

void		push(t_stack *s, stack_data d)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node));
	node->data = d;
	
	node->next = s->head;
	s->head = node;
}

void		print(t_stack s)
{
	t_node	*cur;

	printf("----- print -----\n");
	cur = s.head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n\n");
}

int			stack_is_empty(t_stack *s)
{
	if (s->head)
		return (0);
	return (1);
}

stack_data	pop(t_stack *s)
{
	t_node		*del_n;
	stack_data	del_d;
	
	del_n = s->head;
	del_d = s->head->data;
	
	s->head = s->head->next;
	free(del_n);
	return (del_d);
}



int			main(void)
{
	t_stack	stack;
	int		i;
	
	init(&stack);
	i = 0;
	while (++i < 5)
		push(&stack, i);
	print(stack);
	while (!stack_is_empty(&stack))
		printf("pop : %d\n", pop(&stack));
	printf("\n");
}