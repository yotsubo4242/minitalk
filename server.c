/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:40:05 by yotsubo           #+#    #+#             */
/*   Updated: 2022/10/04 22:41:29 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct sigaction	g_sa;

void	signal_handler(int signum)
{
	static int	res;
	static int	base;

	if (signum == SIGUSR1)
	{
		res = res | 1 << base;
		sigaction(SIGUSR1, &g_sa, NULL);
	}
	else if (signum == SIGUSR2)
		sigaction(SIGUSR2, &g_sa, NULL);
	base++;
	if (base == 8)
	{
		write(1, &res, 1);
		res = 0;
		base = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	ft_memset(&g_sa, 0, sizeof(g_sa));
	g_sa.sa_handler = signal_handler;
	if (-1 == (sigaction(SIGUSR1, &g_sa, NULL)))
	{
		ft_printf("sigaction error\n");
		exit(1);
	}
	if (-1 == (sigaction(SIGUSR2, &g_sa, NULL)))
	{
		ft_printf("sigaction error\n");
		exit(1);
	}
	while (1)
		;
}
