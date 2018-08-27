#include "../libft.h"

int			divide_nb_ubase(uintmax_t nb, int base)
{
	int		ret;

	ret = 0;
	while (nb != 0)
	{
		nb /= base;
		ret++;
	}
	return (ret);
}

char		*ft_itoa_base(unsigned int n, int base)
{
	int		i;
	int		nb;
	char	*str;
	char	tab[17];

	if (n == 0)
		return (ft_strdup("0"));
	i = 1;
	nb = divide_nb_ubase(n, base);
	ft_strcpy(tab, "0123456789abcdef");
	if ((str = (char*)malloc(sizeof(char) * (nb + 1))) == NULL)
		return (NULL);
	str[nb] = '\0';
	while (n != 0)
	{
		str[nb - i] = tab[n % base];
		n /= base;
		i++;
	}
	return (str);
}

char		*ft_itoa_base_up(unsigned int n, int base)
{
	int		i;
	int		nb;
	char	*str;
	char	tab[17];

	if (n == 0)
		return (ft_strdup("0"));
	i = 1;
	nb = divide_nb_ubase(n, base);
	ft_strcpy(tab, "0123456789ABCDEF");
	if ((str = (char*)malloc(sizeof(char) * (nb + 1))) == NULL)
		return (NULL);
	str[nb] = '\0';
	while (n != 0)
	{
		str[nb - i] = tab[n % base];
		n /= base;
		i++;
	}
	return (str);
}

char		*ft_itoa_base_u(uintmax_t n, int base)
{
	int		i;
	uintmax_t	nb;
	char	*str;
	char	tab[17];

	if (n == 0)
		return (ft_strdup("0"));
	i = 1;
	nb = divide_nb_ubase(n, base);
	ft_strcpy(tab, "0123456789abcdef");
	if ((str = (char*)malloc(sizeof(char) * (nb + 1))) == NULL)
		return (NULL);
	str[nb] = '\0';
	while (n != 0)
	{
		str[nb - i] = tab[n % base];
		n /= base;
		i++;
	}
	return (str);
}
