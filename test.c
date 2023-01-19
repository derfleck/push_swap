#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	if (!dest && !src)
		return (0);
	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}

void	swap(int (*a), int (*b))
{
	int	temp[3];

	ft_memcpy(temp, a, sizeof(temp));
	ft_memcpy(a, b, sizeof(*a));
	ft_memcpy(b, temp, sizeof(*b));
}

void printarr(int **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("index: %i index sort: %i, value: %i\n", arr[i][2], arr[i][1], arr[i][0]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	**arr;

	i = 1;
	if (argc == 1)
		return (0);
	arr = malloc(sizeof(int *) * (argc - 1));
	while (argv[i])
	{
		*(arr + i - 1) = malloc(sizeof(int) * 3);
		arr[i - 1][0] = atoi(argv[i]);
		arr[i - 1][1] = i;
		arr[i - 1][2] = i;
		i++;
	}
	swap(arr[0], arr[argc - 1]);
	printarr(arr, argc - 1);
	return (0);
}