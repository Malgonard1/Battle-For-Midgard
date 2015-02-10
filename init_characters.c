/*
** init_characters.c for  in /home/hajem_s/3semaine/colle/malong_a/quete1
** 
** Made by HAJEM Souheil
** Login   <hajem_s@etna-alternance.net>
** 
** Started on  Fri Oct 31 09:43:30 2014 HAJEM Souheil
** Last update Sat Nov  1 16:37:25 2014 MALONGA Alan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "characters.h"
#include "my.h"

static void	init_characters(t_heros *heros,
			   t_ennemy *ennemy, char *name)
{
  ennemy->nb = rand() % 3;
  heros->name = name;
  heros->pv = 100;
  heros->pm = 30;
  heros->Ether = 5;
  heros->Potion = 5;
  ennemy->name = "MONSTER";
  ennemy->pv = 75;
  ennemy->pm = 20;
}

int	create_heros(t_heros **heros, t_ennemy **ennemy, char *name)
{
  if ((*heros = malloc(sizeof(*heros))) == NULL)
    return (0);
  if ((*ennemy = malloc(sizeof(*ennemy))) == NULL)
    return (0);
  if (my_strlen(name) == 0)
    {
      write(2, "Syntax Error : ./ragnarok -n [-name]\n", 37);
      return (-1);
    }
  init_characters(*heros, *ennemy, name);
  return (0);
}
