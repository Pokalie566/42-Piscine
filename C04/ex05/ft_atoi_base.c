/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:42:15 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/24 20:40:11 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_check_base(char *base)
{
	int	len_base;
	int	i;

	len_base = 0;
	while (base[len_base])
	{
		i = len_base + 1;
		while (base[i])
		{
			if (base[i] == base[len_base])
				return (0);
			i++;
		}
		if (base[len_base] == '+' || base[len_base] == '-')
			return (0);
		if (base[len_base] == ' ' || (base[len_base] >= 9
				&& base[len_base] <= 13))
			return (0);
		len_base++;
	}
	if (len_base < 2)
		return (0);
	return (len_base);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	negativ;
	int	len_base;

	i = 0;
	j = 0;
	negativ = 1;
	if (ft_check_base(base) == 0)
		return (0);
	len_base = ft_check_base(base);
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	while (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			negativ = negativ * -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		i = i * len_base + (str[j] - '0');
		j++;
	}
	return (i * negativ);
}
