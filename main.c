/*
** main.c for  in /home/hajem_s/3semaine/colle/malong_a/quete1
** 
** Made by HAJEM Souheil
** Login   <hajem_s@etna-alternance.net>
** 
** Started on  Fri Oct 31 10:11:46 2014 HAJEM Souheil
** Last update Sat Nov  1 18:01:53 2014 HAJEM Souheil
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "characters.h"
#include "my.h"

static int	check_status(t_heros *heros, t_ennemy *ennemy)
{
  if (heros->pv <= 0 && ennemy->pv <= 0)
    {
      my_putstr("TU ES MORT ET L'ENNEMI AUSSI !\nTA MORT A SAUVER LA PLANETE\n");
      return (-1);
    }
  if (heros->pv <= 0)
    {
      my_putstr("TU ES MOOOOOORT !\nREPOSE EN PAIX\n");
      return (-1);
    }
  if (ennemy->pv <= 0)
    while ((ennemy->nb) > 0)
      {
	ennemy->pv = 75;
	ennemy->pm = 20;
	my_putstr("NOUVEAU MONSTRE \nLA PARTIE N'EST PAS TERMINE!!\n");
	ennemy->nb--;
	return (0);
      }
  if (ennemy->pv <= 0)
    {
      my_putstr("L'ENNEMI EST MOOOOORT !\nBIEN JOUER !!!\n");
      return (-1);
    }
  return (0);
}

int		start(char *name)
{
  t_heros	*heros;
  t_ennemy	*ennemy;
  char		*command;
  int		count;

  count = 0;
  if (create_heros(&heros, &ennemy, name) == -1)
    return (0);
  while (count != -1)
    {
      my_putstr("Votre tour> ");
      command = readLine();
      if (command[0] == '\0')
        my_putchar('\n');
      if(my_strcmp(command, "quit") == 0)
	return (-1);
      if (command != NULL)
	if ((count = check_command(heros, ennemy, command)) == 42)
	    tour_ennemy(heros, ennemy);	
      count = check_status(heros, ennemy);
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      if (my_strcmp(av[1], "-n") == 0)
	start(av[2]);
      else
	write(2, "Syntax Error : ./ragnarok -n [-name]\n", 37);
    }
  else
    write(2, "Syntax Error : ./ragnarok -n [-name]\n", 37);
  return (0);
}
