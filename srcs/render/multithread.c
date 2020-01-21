/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:51 by jebae             #+#    #+#             */
/*   Updated: 2019/12/17 21:22:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		handle_thread_err(pthread_t *thread, const char *msg)
{
	unsigned int	i;

	i = 0;
	while (i < RT_NUM_THREADS)
	{
		pthread_cancel(thread[i]);
		i++;
	}
	return (handle_fail(msg));
}

int				multi_thread(t_env *e)
{
	int			i;
	t_env		env[RT_NUM_THREADS];
	pthread_t	thread[RT_NUM_THREADS];

	i = 0;
	while (i < RT_NUM_THREADS)
	{
		ft_memcpy((void *)&env[i], (void *)e, sizeof(t_env));
		env[i].y_min = i * e->height / RT_NUM_THREADS;
		env[i].y_max = (i + 1) * e->height / RT_NUM_THREADS;
		if (pthread_create(&thread[i], NULL, (void *)raytrace, &env[i]) != 0)
			return (handle_thread_err(thread, "multi_thread : pthread_create"));
		i++;
	}
	while (i--)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return (handle_thread_err(thread, "multi_thread : pthread_join"));
	}
	return (RT_SUCCESS);
}
