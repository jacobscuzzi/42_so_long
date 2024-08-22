/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaumfal <jbaumfal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:34:22 by jbaumfal          #+#    #+#             */
/*   Updated: 2024/08/17 09:38:31 by jbaumfal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trim_mem(char *mem, int finder)
{
	char	*new;

	if (finder == -1 || finder == 0)
	{
		free (mem);
		return (NULL);
	}
	if ((int)ft_strlen(mem) > finder)
	{
		new = ft_strdup(mem + finder);
	}
	else
		new = ft_strdup("");
	free(mem);
	if (!new)
		return (NULL);
	return (new);
}

int	fill_mem(int fd, int *finder, char **mem)
{
	char	*buf;
	int		cursor;
	char	*temp;

	cursor = -1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	while (*finder == -1 && cursor != 0)
	{
		cursor = read(fd, buf, BUFFER_SIZE);
		if (cursor == 0)
		{
			*finder = ft_strlen(*mem);
			break ;
		}
		buf[cursor] = '\0';
		temp = ft_strjoin(*mem, buf);
		if (!temp)
			return (free(buf), -1);
		*mem = temp;
		*finder = ft_strchr_pos(*mem, '\n');
	}
	free(buf);
	return (*finder);
}

char	*free_str(char **str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

char	*fill_line(int finder, char **mem)
{
	char		*line;

	line = ft_substr(*mem, 0, finder);
	if (!line)
		return (NULL);
	*mem = trim_mem(*mem, finder);
	if (!*mem)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem[1024];
	int			finder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (mem[fd])
		{
			free (mem[fd]);
			mem[fd] = NULL;
		}
		return (NULL);
	}
	if (!mem[fd])
		mem[fd] = ft_strdup("");
	if (!mem[fd])
		return (NULL);
	finder = ft_strchr_pos(mem[fd], '\n');
	if (fill_mem(fd, &finder, &mem[fd]) == -1)
		return (free_str(&mem[fd]));
	if (ft_strlen(mem[fd]) == 0)
		return (free_str(&mem[fd]));
	return (fill_line(finder, &mem[fd]));
}

// int	main(void)
// {
// 	int	fd;
// 	// char *line;

// 	//fd = open("./files/multiple_nl.txt", O_RDONLY);
// 	fd = open("test.txt", O_RDONLY);

// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	printf("Return: |%s|", get_next_line(fd));
// 	printf("Return: |%s|", get_next_line(fd));
// 	close(fd);
// 	fd = open("test.txt", O_RDONLY);
// 	printf("Return: |%s|", get_next_line(fd));
// 	printf("Return: |%s|", get_next_line(fd));

// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("Return: |%s|", line);
// 	// 	free(line);
// 	//	}
// 	close(fd);
// 	return (0);
// }
