/*
** command_ennemy.c for  in /home/hajem_s/3semaine/colle/malong_a/quete1
** 
** Made by HAJEM Souheil
** Login   <hajem_s@etna-alternance.net>
** 
** Started on  Fri Oct 31 09:58:39 2014 HAJEM Souheil
** Last update Sat Nov  1 11:20:27 2014 MALONGA Alan
*/

#include "characters.h"
#include "my.h"

int	bite(t_heros *heros, t_ennemy *ennemy)
{
  int dmg;

  dmg = 6;
  (void)ennemy;
  heros->pv -= dmg;
  my_putstr("-- BITE\n");
  my_putstr("-- 6PV ENLEVE A TON PERSO !!!\n");
  return (42);
}

int	earthquake(t_heros *heros, t_ennemy *ennemy)
{
  int hdmg;
  int edmg;

  hdmg = 15;
  edmg = 3;
  heros->pv -= hdmg;
  ennemy->pv -= edmg;
  my_putstr("-- EARTHQUAKE\n");
  my_putstr("-- 15PV ENLEVE A TON PERSO !!!\n");
  my_putstr("-- 3PV ENLEVER A L'ENNEMI ;-) \n");
  return (42);
}

int	doom(t_heros *heros, t_ennemy *ennemy)
{
  int hdmg;

  hdmg = 11;
  if (ennemy->pm < 5)
    return (0);
  heros->pv -= hdmg;
  ennemy->pm -= 5;
  my_putstr("-- DOOM\n");
  my_putstr("-- 11PV ENLEVE A TON PERSO !!!\n");
  my_putstr("-- 5PM ENLEVE A L'ENNEMI ;-) \n");
  return (42);
}
