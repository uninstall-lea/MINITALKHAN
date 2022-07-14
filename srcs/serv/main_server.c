/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:43 by lea               #+#    #+#             */
/*   Updated: 2022/07/14 15:22:53 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

char	*g_str = NULL;

static char	bin_to_char(char *given_bin)
{
	char	c;
	int		i;
	int		pow;

	c = 0;
	i = 0;
	pow = 128;
	while (given_bin[i])
	{	
		if (given_bin[i] != '0')
			c += pow;
		i++;
		pow /= 2;
	}
	return (c);
}

void	*ft_charjoin(char *s1, const char c)
{
	size_t	i;
	size_t	s1_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	new_str = malloc(sizeof(char) * (s1_len + 2));
	if (new_str == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[s1_len] = c;
	new_str[s1_len + 1] = '\0';
	free(s1);
	return (new_str);
}

void	sighandler(int sigid, siginfo_t *data, void *whatev)
{
	static int	i = 0;
	static char	value[9];

	(void)whatev;
	if (sigid == SIGUSR1)
		value[i] = '0';
	else if (sigid == SIGUSR2)
		value[i] = '1';
	i++;
	if (i == 8 && !value[i])
	{
		i = 0;
		g_str = ft_charjoin(g_str, bin_to_char(value));
		if (bin_to_char(value) == '\0')
		{
			if (!g_str)
				error_exit(3);
			ft_printf("%s", g_str);
			free(g_str);
			g_str = NULL;
		}
	}
	if (kill(data->si_pid, SIGUSR1) == -1)
		error_exit(5);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Server PID : %d\n", getpid());
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &sighandler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (1);
}
