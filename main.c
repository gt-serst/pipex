/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:27:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/05 15:19:40 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    printf("Fork ici.\n");
    pid = fork();
    if (pid == -1)
    {
        // Si fork renvoie -1, il y a eu une erreur !
        return (1);
    }
    printf("\nFork reussi !\n");
    if (pid == 0)
    {
        // La valeur de retour de fork
        // est 0, ce qui veut dire qu'on est
        // dans le processus fils
        printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
    }
    else if (pid > 0)
    {
        // La valeur de retour de fork 
        // est différente de 0, ce qui veut dire
        // qu'on est dans le processus père
        printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
    }
    return(0);
}
