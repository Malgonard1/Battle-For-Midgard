/*
** command_check.c for  in /home/hajem_s/3semaine/colle/malong_a/quete1
** 
** Made by HAJEM Souheil
** Login   <hajem_s@etna-alternance.net>
** 
** Started on  Fri Oct 31 09:51:22 2014 HAJEM Souheil
** Last update Sat Nov  1 15:52:51 2014 MALONGA Alan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "characters.h"
#include "my.h"

int		tour_ennemy(t_heros *heros, t_ennemy *ennemy)
{
  int		nb;
  int		ret;
  t_eattack	tab[]=
    {
      {0, bite},
      {1, earthquake},
      {2, doom},
      {0, 0},
    };

  ret = 0;
  while (ret == 0)
    {
      nb = (rand() % (2 - 0 + 1)) + 0;
      ret = tab[nb].t(heros, ennemy);
    }
  return (0);
}

int		check_command(t_heros *heros, t_ennemy *ennemy, char *command)
{
  int		i;
  int		nb;
  t_command	tab[]=
    {
      {"attack", attack},
      {"slash", slash}, {"fire", fire},
      {"thunder", thunder}, {"stat", stat},
      {"libra", libra}, {"Potion", Potion},
      {"Ether", Ether}, {"heal", heal},
      {0, 0}
    };

  i = -1;
  while (tab[++i].command != NULL)
    {
      if (my_strcmp(tab[i].command, command) == 0)
	{
	  nb = tab[i].f(heros, ennemy);
	  return (nb);
	}
      if (my_strcmp("quit", command) == 0)
	return (20);
    }
  return (0);
}

int critical()
{
  int i;

  i = rand() % 10;
  if (i==1)
    {
      my_putstr("CRITICAL");
      return (1);
    }
  else
    return (0);
}
