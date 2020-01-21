/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:50:23 by jebae             #+#    #+#             */
/*   Updated: 2019/05/08 13:50:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			split(t_list *head, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*front = head;
	*back = slow->next;
	slow->next = NULL;
}

static t_list		*sorted_merge(t_list *front, t_list *back,\
		int (*compare)(t_list *, t_list *))
{
	t_list	*res;

	res = NULL;
	if (front == NULL)
		return (back);
	else if (back == NULL)
		return (front);
	if (compare(front, back) > 0)
	{
		res = back;
		res->next = sorted_merge(front, back->next, compare);
	}
	else
	{
		res = front;
		res->next = sorted_merge(front->next, back, compare);
	}
	return (res);
}

static void			merge_sort(t_list **head,\
		int (*compare)(t_list *, t_list *))
{
	t_list	*front;
	t_list	*back;

	if (head == NULL)
		return ;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	split(*head, &front, &back);
	merge_sort(&front, compare);
	merge_sort(&back, compare);
	*head = sorted_merge(front, back, compare);
}

void				ft_lstsort(t_list **alst,\
		int (*compare)(t_list *, t_list *))
{
	merge_sort(alst, compare);
}
