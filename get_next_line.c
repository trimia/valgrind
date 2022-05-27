/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:56:30 by mmariani          #+#    #+#             */
/*   Updated: 2022/05/27 18:15:15 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

char *fdread(int fd, char *ret)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// exit(0);
	if(!buffer)
		return(NULL);
	i = 1;
	while (!ft_newline(ret, '\n') && i != 0)
	{
		memset(buffer, '\0', BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			if (ret)
				free(ret);
			return (NULL);
		}
		buffer[i] = '\0';
		ret = ft_strjoin(ret, buffer);
	}
	free(buffer);
	return (ret);
}

char	*ft_copy(char *ret)
{
	int	i;
	char *temp;

	i = 0;
	if(!ret || !ret[i])
		return(NULL);
	while (ret[i] != '\n' && ret[i] != '\0')
		i++;
	if (ret[i] == '\0')
		temp = malloc(sizeof(char) * (i + 1));
	else
		temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i=0;
	while(ret[i] && ret[i] != '\n')
	{
		temp[i] = ret[i];
		i++;
	}
	if (ret[i] == '\n')
	{
		temp[i] = ret[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_trimstr(char *ret)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (ret[i]!='\n' && ret[i] != 0)
		i++;
	if (!ret[i])
	{
		free(ret);
		return(NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(ret) - i + 1));
	if(!temp)
		return (NULL);
	i++;
	j = 0;
	while (ret[i])
		temp[j++] = ret[i++];
	temp[j] = '\0';
	free(ret);
	return (temp);
}
// #include <stdlib.h>
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*ret;
	char		*temp;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = fdread(fd, ret);
	if(!ret || *ret == '\0')
	{
		// if(ret)
		// 	free(ret);
		return (NULL);
	}
	// sleep(1);
	// printf("HERERERER\n");
	// exit(0);
	temp = ft_copy(ret);
	// if ()
	ret = ft_trimstr(ret);
	// printf("%s\n",temp);
	return (temp);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("42_with_nl", O_CREAT | O_RDWR);
// 	line = get_next_line(fd);
// 	printf("line: %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("line: %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("line: %s\n", line);
// 	free(line);
// 	return 0;
// }



// #include <fcntl.h>
// #include <stdio.h>

// int main ()
// {
// 	int fd;
// 	fd = open("1-brouette.txt", O_RDONLY);
// 	// // fd = open("1-brouette.txt", O_RDONLY);
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// 		// printf("%s",get_next_line(fd));
// 	// 		// 	printf("%s",get_next_line(fd));
// 	// 		// 		printf("%s",get_next_line(fd));
// 	// 		// 			printf("%s",get_next_line(fd));
// 	// 		// 				printf("%s",get_next_line(fd));
// 	// 		// 					printf("%s",get_next_line(fd));
// 	// 		// 						printf("%s",get_next_line(fd));
// 	// 		// 						printf("%s",get_next_line(fd));
// 	// 		// 						printf("%s",get_next_line(fd));
// 	// 		// 						printf("%s",get_next_line(fd));

	
// 	int i =0;
// 	while (i<84)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
	
// }


// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }