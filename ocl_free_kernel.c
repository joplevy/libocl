/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_free_kernel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 05:03:14 by jplevy            #+#    #+#             */
/*   Updated: 2017/03/04 05:05:59 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libocl.h"

int		ocl_free_kernel(t_ocl_prog p)
{
	t_list	*tmp;
	t_list	*f;
	cl_int	ret;
	int		i;

	tmp = p.kernel;
	while (tmp)
	{
		if ((ret = clReleaseKernel(((t_ocl_kernel*)(tmp->content))->kernel))
			< 0)
			return (ocl_error(ret, __func__));
		i = -1;
		while (++i < (int)(((t_ocl_kernel*)(tmp->content))->nb_obj))
			if ((ret = clReleaseMemObject(((t_ocl_kernel*)(tmp->content))->
			memobj[i])) < 0)
				return (ocl_error(ret, __func__));
		free(((t_ocl_kernel*)(tmp->content))->obj_size);
		free(((t_ocl_kernel*)(tmp->content))->write);
		free(((t_ocl_kernel*)(tmp->content))->read);
		f = tmp;
		tmp = f->next;
		free(f);
	}
	return (1);
}
