  
#include <stdio.h>
#include <stdlib.h>

typedef	int	queue_data;

typedef struct	s_node
{
	queue_data		data;
	struct s_node	*next;
}					t_node;

typedef	struct	s_queue
{
	t_node		*front;
	t_node		*rear;
}				t_queue;



void	init(t_queue *q)
{
	q->front = NULL;
}

int			queue_is_empty(t_queue *q)
{
	if (q->front)
		return (0);
	return (1);
}

void	enqueue(t_queue *q, queue_data d)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node));
	node->data = d;
	node->next = NULL;
	
	if (q->front)
		q->rear->next = node;
	else
		q->front = node;
	q->rear = node;
}

void		print(t_queue q)
{
	t_node	*cur;

	printf("----- print -----\n");
	cur = q.front;
	while(cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n\n");
}

queue_data	dequeue(t_queue *q)
{
	t_node		*del_n;
	queue_data	del_d;
	
	del_n = q->front;
	del_d = q->front->data;
	
	q->front = q->front->next;
	free(del_n);
	return (del_d);
}



int		main(void)
{
	t_queue	q;
	int		i;
	
	init(&q);
	
	i = 0;
	while (++i < 5)
		enqueue(&q, i);
	print(q);
	while (!queue_is_empty(&q))
		printf("delete : %d\n", dequeue(&q));
	printf("\n");
}