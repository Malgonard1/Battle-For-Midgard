/*
** command_hero2.c for  in /home/hajem_s/3semaine/colle/malong_a/quete1
** 
** Made by HAJEM Souheil
** Login   <hajem_s@etna-alternance.net>
** 
** Started on  Fri Oct 31 10:07:29 2014 HAJEM Souheil
** Last update Sat Nov  1 13:56:58 2014 MALONGA Alan
*/

#include "characters.h"
#include "my.h"

int	attack(t_heros *heros, t_ennemy *ennemy)
{
  int	edmg;
  int	critic;

  critic = critical();
  edmg = 7;
  if (critic == 1)
    {
    edmg *= 1.2;
    }
  (void)heros;
  my_putstr(" ATTACK\n");
  my_put_nbr(edmg);
  my_putstr(" PV POUR TON PERSO\n");
  ennemy->pv -= edmg;
  return (42);
}

int	slash(t_heros *heros, t_ennemy *ennemy)
{
  int edmg;
  int hdmg;

  edmg = 10;
  hdmg = 2;
  if (critical() == 1)
    {
      hdmg *= 1.2;
      edmg *= 1.2;
    }
  my_putstr(" SLASH\n");
  my_put_nbr(hdmg);
  my_putstr(" PV POUR TON PERSO\n");
  my_put_nbr(edmg);
  my_putstr(" PV A L'ENNEMI\n");
  ennemy->pv -= edmg;
  heros->pv -= hdmg;
  return (42);
}

int	fire(t_heros *heros, t_ennemy *ennemy)
{
  int edmg;

  edmg = 10;
  if (critical() == 1)
    {
      edmg *= 1.2;
    }
  if (heros->pm < 3)
    {
      my_putstr("PERSO -> PAS ASSEZ DE PM\n");
      return (0);
    }
  my_putstr(" FIRE\n");
  my_putstr(" 3PM A TON PERO\n");
  my_put_nbr(edmg);
  my_putstr(" PV A L'ENNEMI\n");
  heros->pm -= 3;
  ennemy->pv -= edmg;
  return (42);
}

int	thunder(t_heros *heros, t_ennemy *ennemy)
{
  int edmg;

  edmg = 15;
  if (critical() == 1)
        edmg *= 1.2;
    if (heros->pm < 5)
    {
      my_putstr("PERSO -> PAS ASSEZ DE PM\n");
      return (0);
    }
  my_putstr(" THUNDER\n");
  my_putstr(" 5PM A TON PERSO\n");
  my_put_nbr(edmg);
  my_putstr(" PV A L'ENNEMI\n");
  heros->pm -= 5;
  ennemy->pv -= edmg;
  return (42);
}

int Potion(t_heros *heros, t_ennemy *ennemy)
{
  int hdmg;

  hdmg = 30;
  (void)ennemy;
  if (critical() == 1)
    hdmg *= 1.2;
  if ((heros->Potion) > 0)
    {
      if (((heros->pv) > 0) && ((heros->pv) <= 70))
	{
	  heros->pv += hdmg;
	  heros->Potion--;
	  my_putstr("-- POTION\n");
	  my_put_nbr(hdmg);
	  my_putstr("-- PV AJOUTE A TON PERSO !!!\n");
	  return (42);
	}
      else if ((heros->pv) < 100)
	{
	  heros->pv = 100;
	  heros->Potion--;
	  return (42);
	}
    }
  return (0);
}

int Ether(t_heros *heros, t_ennemy *ennemy)
{
  (void)ennemy;
  if ((heros->Ether) > 0)
    {
      if (((heros->pm) > 0) && ((heros->pm) <= 18))
	{
	  heros->pm += 12;
	  heros->Ether--;
	  my_putstr("-- ETHER\n");
	  my_putstr("-- 12PM AJOUTE A TON PERSO !!!\n");
	  return (42);
	}
      else if ((heros->pm) < 30)
	{
	  heros->pm= 30;
	  heros->Ether--;
	  return (42);
	}
    }
  return (0);
}

int heal_pm(int heropm)
{
  int hdmg;

  hdmg = 3;
  if ((heropm) >= 3)
    heropm -= hdmg;
  else if (heropm > 0)
    heropm = 0;
  return (heropm);
}

int heal(t_heros *heros, t_ennemy *ennemy)
{
  int tmp;
  int result;
  
  (void)ennemy;
  tmp = ((heros->pv) * 25) / 100;
  if (critical() == 1)
    tmp *= 1.2;
  result = (heros->pv) + tmp;
  if ((((heros->pv) > 0) && result <= 100))
    {
      heros->pv += tmp;
      heros->pm = heal_pm(heros->pm);
      my_putstr("-- HEAL\n");
      my_put_nbr(tmp);
      my_putstr("-- 25%PV AJOUTE A TON PERSO !!!\n");
      return (42);
    }
  else if (result < 100)
    {
      heros->pv = 100;
      heros->pm = heal_pm(heros->pm);
      return (42);
    }
  return (0);
}
