/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mathis <Mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:48:52 by Mathis            #+#    #+#             */
/*   Updated: 2020/10/12 13:36:18 by Mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell g_shell;
extern t_printf g_printf;

void    signal_quit(int signal)
{
    if(g_shell.pid && !g_shell.d)
    {
        kill(g_shell.pid, signal);
        g_shell.status = 131;
        ft_printf("Quit: %d\n", g_shell.pid);
    }
}

void    signal_interrupt(int signal)
{
    ft_printf("\n");
    if (!g_shell.pid)
    {
           	ft_printf("\e[1m" "bash-42$ " "\e[0m", 25);
            g_shell.status = 130;
    }
    else
        kill(g_shell.pid, signal);
}

void    signals(void)
{
    if(signal(SIGINT, &signal_interrupt) == SIG_ERR)
        ft_printf("Signal interrupt error\n");
    if(signal(SIGQUIT, &signal_quit) == SIG_ERR)
        ft_printf("Signal quit error\n");
}
