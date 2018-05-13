/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_build_prog.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyplevy <joeyplevy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 04:33:10 by jplevy            #+#    #+#             */
/*   Updated: 2018/05/13 13:34:49 by joeyplevy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libocl.h"

static inline void  console_log_compilation(cl_program prog, cl_device_id
        device_id, cl_program_build_info type)
{
    size_t  size;
    char    *str;

    clGetProgramBuildInfo(prog, device_id, type, 0, NULL, &size);
    if (!(str = ft_memalloc(sizeof(char) * size + 1)))
        ft_putstr_fd("ERROR: malloc error", 1);
    clGetProgramBuildInfo(prog, device_id, type, size, str, NULL);
    ft_putstr_fd(str, 1);
}


int		ocl_build_prog(char *filename, size_t max_src_size, t_ocl_prog *p)
{
	char		*src_str;
	size_t		src_size;
	int			fd;
	cl_int		ret;

	fd = open(filename, O_RDONLY);
	if (!fd)
		return (0);
	src_str = (char*)malloc(max_src_size);
	src_size = read(fd, src_str, max_src_size);
	close(fd);
	p->program = clCreateProgramWithSource(p->context, 1,
		(const char **)&src_str, (const size_t *)&src_size, &ret);
	if (ret < 0)
		return (ocl_error(ret, __func__));
	ret = clBuildProgram(p->program, 1, &(p->device_id), NULL, NULL, NULL);
	if (ret < 0)
	{

        console_log_compilation(p->program, p->device_id, CL_PROGRAM_BUILD_LOG);
		return (ocl_error(ret, __func__));
	}
	free(src_str);
	return (1);
}
