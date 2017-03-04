/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_get_right_kernel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 04:55:16 by jplevy            #+#    #+#             */
/*   Updated: 2017/03/04 04:57:36 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libocl.h"

t_ocl_kernel	*ocl_get_right_kernel(t_list *start, char *kernel)
{
	t_list			*tmp;

	tmp = start;
	while (tmp)
	{
		if (ft_strcmp(((t_ocl_kernel *)(tmp->content))->name, kernel) == 0)
			return ((t_ocl_kernel *)tmp->content);
		tmp = tmp->next;
	}
	ft_putendl("wrong kernel enqueued");
	return (NULL);
}
