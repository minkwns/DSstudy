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

}




int		main(void)
{
	t_p_queue pq;

	p_queue_init(&pq, comp_func);
	
	enter_p_queue(&pq, "kim");
	enter_p_queue(&pq, "jin");
	enter_p_queue(&pq, "bum");
}