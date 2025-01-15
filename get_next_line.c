#include "get_next_line.h"


static void	read_from_fd(int fd, char **pointing, char *buff)
{
	int		bytes_read;
	char 	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && *pointing)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*pointing);
			*pointing = NULL;
			break ;
		}
		buff[bytes_read] = '\0';
		temp = *pointing;
		*pointing = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
}


static void	get_line(char *pointing, char **line)
{
	char	*temp;
	size_t	index;
	
	index = 0;
	if (!pointing || !pointing[index])
		return ;
	while (pointing[index] && pointing[index] != '\n')
		index++;
	temp = ft_substr(pointing, 0, index + (pointing[index] == '\n'));
	if (temp)
	{
		*line = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		if (!*line)
		{
			free(temp);
			return ;
		}
	}
	ft_strlcpy(*line, temp, ft_strlen(temp) + 1);
	free(temp);
}

static void	next_pointer(char **pointing, char *line)
{
	char	*temp;

	temp = NULL;
	if (*pointing && line)
		temp = ft_strdup(*pointing + ft_strlen(line));
	free(*pointing);
	*pointing = temp;
}

char	*get_next_line(int fd)
{
	static char	*pointing;
	char		*line;
	char 		*buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!pointing)
		pointing = ft_strdup("");// зачем так если можно просто pointing = NULL;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(pointing), pointing = NULL, NULL);
	read_from_fd(fd, &pointing, buff);
	get_line(pointing, &line);
	next_pointer(&pointing, line);
	return (line);
}