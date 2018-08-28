#include "../include/fdf.h"
#include "../include/get_next_line.h"

int		retrieve_data(int fd, t_data data)
{
	char	*line;
	char	**values;
	int		content;
	int		count;
	int		*numbers;
	int		i;

	count = 0;
	i = 0;
	while ((content = get_next_line(fd, &line)) == 1)
	{
		values = ft_strsplit(line, ' ');
		while (values[i] != 0)
			i++;
		numbers = (int *)malloc(sizeof(int) * i + 1);
		count = i;
		i = -1;
		while (++i < count)
			if ((numbers[i] = ft_atoi(values[i])))
				return (1);


	}
	if (content == -1)
		return (1);
	return (0);
}
