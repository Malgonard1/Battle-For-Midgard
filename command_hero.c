/*
** command_hero.c for  in /home/hajem_s/3semaine/colle/malong_a/quete1
** 
** Made by HAJEM Souheil
** Login   <hajem_s@etna-alternance.net>
** 
** Started on  Fri Oct 31 10:03:11 2014 HAJEM Souheil
** Last update Tue Feb 10 20:57:04 2015 MALONGA alan
*/

#include "characters.h"
#include "my.h"

int     stat(t_heros *heros, t_ennemy *ennemy)
{
  (void)ennemy;
  my_putstr(GREEN);
  my_putstr("STAT DE TON PERSO\n");
  my_putstr(RESET);
  my_putstr(heros->name);
  my_putstr(": ");
  my_put_nbr(heros->pv);
  my_putstr("pv, ");
  my_put_nbr(heros->pm);
  my_putstr("pm.");
  my_putchar('\n');
  return (0);
}

int     libra(t_heros *heros, t_ennemy *ennemy)
{
  if (heros->pm < 1)
    {
      my_putstr(RED);
      my_putstr("TON PERSO -> PLUS DE PM\n");
      my_putstr(RESET);
      return (0);
    }
  heros->pm -= 1;
  my_putstr(GREEN);
  my_putstr("LIBRA (stat ennemie)\n");
  my_putstr(RESET);
  my_putstr(" 1PM ENLEVE A TON PERSO\n");
  my_putstr(ennemy->name);
  my_putstr(": ");
  my_put_nbr(ennemy->pv);
  my_putstr("pv, ");
  my_put_nbr(ennemy->pm);
  my_putstr("pm.");
  my_putchar('\n');
  return (42);
}
