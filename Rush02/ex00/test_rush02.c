/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rush02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledupont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:47:53 by ledupont          #+#    #+#             */
/*   Updated: 2024/07/27 11:13:18 by ledupont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*convert_arg(char *str)
{
	int	neg;
	int	i;
	int	j;

	i = 0;
	neg = 1;
	while (str[i] && str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i ++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg = -neg;
		i ++;
	}
	while (str[i] == '0')
		i++;
	if (str[i - 1] == '0' && !(str[i] >= '0' && str[i] <= '9'))
		return ("0");
	if (neg < 0)
		return (0);
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	str[i] = '\0';
	return (str + j);
}

char	*check_arg(int argc, char **argv)
{
	if (argc > 3 || argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (convert_arg(argv[argc - 1]) == 0 || argv[argc - 1][0] == '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (convert_arg(argv[argc - 1]));
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;

	str = check_arg(argc, argv);
	printf("%s", str);
}
