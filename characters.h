/*
** characters.h for characters.h in /home/hajem_s/3semaine/colle/malong_a/quete1
** 
** Made by HAJEM Souheil
** Login   <hajem_s@etna-alternance.net>
** 
** Started on  Fri Oct 31 09:34:31 2014 HAJEM Souheil
** Last update Sat Nov  1 16:29:23 2014 MALONGA Alan
*/

#ifndef CHARACTERS_H_
# define CHARACTERS_H_

typedef struct	s_heros
{
  char		*name;
  int		pv;
  int		pm;
  int           Ether;
  int           Potion;
}		t_heros;

typedef struct	s_ennemy
{
  char		*name;
  int		pv;
  int		pm;
  int           nb;
}		t_ennemy;

typedef struct	s_command
{
  char		*command;
  int		(*f)(t_heros *, t_ennemy *);
}		t_command;

typedef struct	s_eattack
{
  int		i;
  int		(*t)(t_heros *, t_ennemy *);
}		t_eattack;
int	attack(t_heros *heros, t_ennemy *ennemy);
int	slash(t_heros *heros, t_ennemy *ennemy);
int	fire(t_heros *heros, t_ennemy *ennemy);
int	thunder(t_heros *heros, t_ennemy *ennemy);
int	stat(t_heros *heros, t_ennemy *ennemy);
int	libra(t_heros *heros, t_ennemy *ennemy);
int	bite(t_heros *heros, t_ennemy *ennemy);
int	earthquake(t_heros *heros, t_ennemy *ennemy);
int	doom(t_heros *heros, t_ennemy *ennemy);
int	tour_ennemy(t_heros *heros, t_ennemy *ennemy);
int	check_command(t_heros *heros, t_ennemy *ennemy, char *command);
int	create_heros(t_heros **heros, t_ennemy **ennemy, char *name);
int     Potion(t_heros *heros, t_ennemy *ennemy);
int     Ether(t_heros *heros, t_ennemy *ennemy);
int     heal(t_heros *heros, t_ennemy *ennemy);
int     critical();
char	*readLine();

#endif
