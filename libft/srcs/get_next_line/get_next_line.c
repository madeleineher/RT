/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:45:47 by jebae             #+#    #+#             */
/*   Updated: 2019/04/18 16:09:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			preprocess(const int fd, char **line)
{
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (PREPROCESS_FAIL);
	*line = ft_strnew(0);
	if (*line == NULL)
		return (PREPROCESS_FAIL);
	return (PREPROCESS_SUCCESS);
}

int			handle_error(char **line)
{
	if (**line == '\0')
		ft_memdel((void **)line);
	return (GNL_ERROR);
}

int			write_line(t_bucket *bucket, char **line)
{
	char		*buf;
	char		*tmp_line;
	size_t		i;

	i = 0;
	buf = bucket->buf + bucket->loc;
	while (bucket->loc + i < BUFF_SIZE && buf[i] != '\n')
		i++;
	tmp_line = *line;
	buf[i] = '\0';
	*line = ft_strjoin(*line, buf);
	ft_memdel((void **)&tmp_line);
	if (*line == NULL)
		return (WRITE_LINE_FAIL);
	bucket->loc += i + 1;
	if (bucket->loc <= BUFF_SIZE)
		return (WRITE_LINE_SUCCESS);
	ft_bzero((void *)bucket->buf, BUFF_SIZE + 1);
	bucket->loc = 0;
	return (WRITE_LINE_SUCCESS);
}

int			get_next_line(const int fd, char **line)
{
	static t_bucket		bucket;
	int					ret;

	if (preprocess(fd, line) == PREPROCESS_FAIL)
		return (GNL_ERROR);
	if (bucket.loc != 0 && write_line(&bucket, line) == WRITE_LINE_FAIL)
		return (handle_error(line));
	while (bucket.loc == 0)
	{
		if ((ret = read(fd, bucket.buf, BUFF_SIZE)) == -1)
			return (handle_error(line));
		if (ret == 0)
		{
			if (**line != '\0')
				return (GNL_LINE_READ);
			ft_memdel((void **)line);
			return (GNL_READ_COMPLETE);
		}
		if (write_line(&bucket, line) == WRITE_LINE_FAIL)
			return (handle_error(line));
	}
	return (GNL_LINE_READ);
}
