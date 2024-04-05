/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:46:37 by joana             #+#    #+#             */
/*   Updated: 2024/03/28 20:51:56 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	something(int signal)
{
	static int	b;
	static int	c;

	if (signal == SIGUSR1)
		c += (1 << b);
	if (b++ == 7)
	{
		write(1, &c, 1);
		b = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, something);
	signal(SIGUSR2, something);
	while (1)
		sleep(1);
}