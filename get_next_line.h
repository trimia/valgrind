/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:01:04 by mmariani          #+#    #+#             */
/*   Updated: 2022/05/25 18:20:12 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif


char	*fdread(int fd, char *ret);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_trimstr(char *ret);
char	*ft_newline(char *str, int c);
int		ft_count(char *str);
int		ft_strlen(const char *str);
char	*ft_copy(char *ret);



#endif

