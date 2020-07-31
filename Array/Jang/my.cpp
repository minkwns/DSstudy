#include <stdio.h>
#include <stdlib.h>

// try to implement memcpy function directly.
void* ft_memcpy(void* des, const void* src, size_t len)
{
	const char* s;
	char* d;
	size_t		i;

	if (!des || !src)  // when any NULL value is received, exit the function.
		return (NULL);
	d = (char*)des;
	s = (const char*)src;
	i = -1;
	while (++i < len)  // copy any data type in 1-byte increments.
		d[i] = s[i];
	return(d);
}

// create a swap function that changes values regardless of data type using memcpy function
void	ft_swap(void* a, void* b, size_t len)
{
	void* temp;  // use void pointer

	if (!(temp = malloc(len)))  // if memory allocation fails, exit function
		return;
	ft_memcpy(temp, a, len);
	ft_memcpy(a, b, len);
	ft_memcpy(b, temp, len);
	free(temp);
}


int		main(void)
{
	char	c1;
	char	c2;
	int		i1;
	int		i2;
	double	d1;
	double	d2;

	c1 = 'A';
	c2 = 'B';
	i1 = 42;
	i2 = 24;
	d1 = 42.42;
	d2 = 24.24;

	printf("c1 : %c, c2 : %c\n", c1, c2);
	printf("i1 : %d, i2 : %d\n", i1, i2);
	printf("d1 : %lf, d2 : %lf\n", d1, d2);

	ft_swap(&c2, &c1, sizeof(char));
	ft_swap(&i2, &i1, sizeof(int));
	ft_swap(&d2, &d1, sizeof(double));

	printf("----------\n");
	printf("c1 : %c, c2 : %c\n", c1, c2);
	printf("i1 : %d, i2 : %d\n", i1, i2);
	printf("d1 : %lf, d2 : %lf\n", d1, d2);
}