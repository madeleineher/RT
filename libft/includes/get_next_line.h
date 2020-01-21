/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:20:43 by jebae             #+#    #+#             */
/*   Updated: 2019/06/18 18:15:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 10
# define WRITE_LINE_FAIL -1
# define WRITE_LINE_SUCCESS 0
# define PREPROCESS_FAIL -1
# define PREPROCESS_SUCCESS 1
# define BUCKET_EMPTY -1
# define BUCKET_REMAINED 0
# define BUCKET_FULL 1
# define GNL_ERROR -1
# define GNL_READ_COMPLETE 0
# define GNL_LINE_READ 1

typedef struct	s_bucket
{
	char		buf[BUFF_SIZE + 1];
	size_t		loc;
}				t_bucket;

int				get_next_line(const int fd, char **line);

#endif
