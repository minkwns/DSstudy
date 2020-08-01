#include <stdio.h>

#define	PQ_SIZE	100

typedef	char	*pq_data;
typedef	int		(*priority_comp)(pq_data, pq_data);

typedef	struct		s_p_queue
{
	int				data_num;
	pq_data			pq_arr[PQ_SIZE];	
	priority_comp	f;
}					t_p_queue;



int		ft_strcmp(char *s1, char *s2)
{
	int i;
	
	i = -1;
	while(s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (s1[i] - s2[i]);
}

int		comp_func(pq_data a, pq_data b)
{
	return (ft_strcmp(a, b));
}



void	p_queue_init(t_p_queue *pq, priority_comp f)
{
	pq->data_num = 0;
	pq->f = f;
}

void	enter_p_queue(t_p_queue *pq, pq_data data)
{
	int	i;

	i = ++(pq->data_num);
	while (i != 1)
	{
		if (pq->f(pq->pq_arr[i / 2], data) < 0)
			break ;
		else
		{
			pq->pq_arr[i] = pq->pq_arr[i / 2];
			i /= 2;
		}
	}
	pq->pq_arr[i] = data;
}

int		p_queue_is_empty(t_p_queue *pq)
{
	if (pq->data_num)
		return (0);
	return (1);
}

int		get_high_priority_child_i(t_p_queue *pq, int i)
{
		if (pq->data_num < i * 2)
			return (0);
		else if (pq->data_num == i * 2)
			return (i * 2);
		else
		{
			if (pq->f(pq->pq_arr[i * 2], pq->pq_arr[i * 2 + 1]) < 0)
				return (i * 2);
			else
				return (i * 2 + 1);
		}
		
}

pq_data	delete_p_queue(t_p_queue *pq)
{
	pq_data		remem_data;
	pq_data		last_data;
	int			parent_i;
	int			child_i;

	remem_data = pq->pq_arr[1];
	last_data = pq->pq_arr[(pq->data_num)--];
	parent_i = 1;
	while ((child_i = get_high_priority_child_i(pq, parent_i)))
	{
		if (pq->f(last_data, pq->pq_arr[child_i]) >= 0)
			break ;
		pq->pq_arr[parent_i] = pq->pq_arr[child_i];
		parent_i = child_i;
	}
	
	pq->pq_arr[parent_i] = last_data;
	return (remem_data);

}



int		main(void)
{
	t_p_queue pq;

	p_queue_init(&pq, comp_func);

	enter_p_queue(&pq, "ab");
	enter_p_queue(&pq, "jk");
	enter_p_queue(&pq, "cd");
	enter_p_queue(&pq, "gh");
	enter_p_queue(&pq, "ef");

	while (!p_queue_is_empty(&pq))
		printf("%s \n", delete_p_queue(&pq));
}