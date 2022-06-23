#include "libft.h"

static int	calc_flag(int *i, char *flag, int x)
{
	if (*i < 0)
	{
		*flag = '-';
		if (*i == -2147483648)
		{
			*flag = 'M';
			*i = *i + 1;
		}
		*i = *i * -1;
		x++;
	}
	return (x);
}

static char	*populate_nbr(char *new, int x, int n, char *flag)
{
	int	i;

	if (*flag == '-')
		n = n * -1;
	while (x > 0)
	{
		if (*flag == 'M')
		{
			new[x - 1] = 8 + '0';
			x--;
			n = n / 10;
			n = -1 * n;
			*flag = 1;
		}
		i = n % 10;
		n = n / 10;
		new[x - 1] = (char)i + '0';
		x--;
	}
	return (new);
}

char	*ft_itoa_base(int n, int base)
{
	char	*new;
	int		i;
	char	flag;
	int		x;

	flag = ' ';
	x = 1;
	i = n;
	x = calc_flag(&i, &flag, x);
	while (i > 9)
	{
		i = i / base;
		x++;
	}
	new = ft_strnew((size_t)x);
	if (!new)
		return (NULL);
	new = populate_nbr(new, x, n, &flag);
	if (flag == '-' || flag == 1)
		new[0] = '-';
	return (new);
}
