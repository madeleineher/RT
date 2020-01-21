/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:56:04 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:56:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*queue_pop(t_queue *queue)
{
	void		*res;
	t_list		*temp;

	if (queue == NULL)
		return (NULL);
	if (queue->front == NULL)
		return (NULL);
	else
	{
		temp = queue->front->next;
		res = queue->front->content;
		ft_lstdelone(&(queue->front), NULL);
		queue->front = temp;
		if (queue->front == NULL)
			queue->rear = NULL;
	}
	return (res);
}
