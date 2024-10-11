#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>

int	ft_get_size(char *name)
{
	int		ft;
	int		num;
	int		i;
	char	buf[60000];

	ft = open(name, O_RDONLY);
	if (ft == -1)
		return (-1);
	i = 0;
	num = 1;
	while (num == 1)
	{
		num = read(ft, buf, 1);
		i++;
	}
	if (close(ft) == -1)
		return (-1);
	return (i);
}

char	*ft_read(char *name)
{
	char	*str;
	int		ft;
	int		i;

	i = ft_get_size(name);
	if (i == -1)
		return (0);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	ft = open(name, O_RDONLY);
	if (ft == -1 || read(ft, str, i - 1) == -1)
	{
		free(str);
		return (0);
	}
	str[i] = '\0';
	return (str);
}
