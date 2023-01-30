#include <unistd.h>

int	to_power(int nb, int power)
{
	if (!power)
		return (1);
	else
	{
		power--;
		return ((nb * to_power(nb, power)));
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	value;
	
	i = 0;
	j = 0;
	value = 5000;
	while (to_power(2, i) < value)
		i++;
	while (j < i)
	{
		if (value & 0x01)
			write(1, &"1", sizeof(char));
		else
			write(1, &"0", sizeof(char));
		value >>= 1;
		j++;
	}
	return (0);
}

/*
int	*pos_check(int *num, int pos, int values)
{
	int	i;
	int	*cmd;

	i = 0;
	cmd = malloc(sizeof(int) * (values * values));
	while (i < values)
	{
		if (num[i] >> pos & 0x01)
			cmd[i] = 2;
		else
			cmd[i] = 3;
		i++;
	}
}
*/

/*
stop = 0
pa = 1 *
pb = 2 *
sa = 3
sb = 4
ss = 5
ra = 6 *
rb = 7
rr = 8
rra = 9
rrb = 10
rrr = 11
*/