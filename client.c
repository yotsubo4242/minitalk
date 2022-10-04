/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:27:15 by yotsubo           #+#    #+#             */
/*   Updated: 2022/10/04 22:38:52 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	send_char(pid_t	pid, char c)
{
	int	base;

	base = 0;
	while (base < 8)
	{
		usleep(200);
		if (c & 1 << base)
		{
			if (-1 == kill(pid, SIGUSR1))
				return (-1);
		}
		else
		{
			if (-1 == kill(pid, SIGUSR2))
				return (-1);
		}
		base++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	size_t	i;
	pid_t	pid;
	int		res;

	if (argc != 3)
	{
		ft_printf("arguments error\n");
		exit(1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		exit(1);
	i = 0;
	while (argv[2][i])
	{
		res = send_char(pid, argv[2][i++]);
		if (res == -1)
		{
			ft_printf("kill error\n");
			exit(1);
		}
	}
	return (0);
}
