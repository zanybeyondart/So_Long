#include "game.h"

void free_animation(animation *anim)
{
    if (anim) {
		free_animation(anim->next);
        free(anim->img);
        free(anim);
        }
    }

void free_player(player *p) {
    if (p) {
		free_animation(p->idle);
		free_animation(p->run);
		free(p);
		}
}

void free_portal(portal *p) {
    if (p) {
		free_animation(p->disabled);
		free_animation(p->enabled);
		free(p);
		}
}

void free_game(game *game) {
    if (game) {
        free(game->img);
        free(game);
        }
    }

void free_map(map *map) {
    if (map) {
        free(map->mat);
        free(map);
        }
    }


void free_vars(t_vars *vars) {
    if (vars)
	{
		free_player(vars->p1);
		free_portal(vars->exit);
		free_animation(vars->wall);
		free_map(vars->map);
		free_animation(vars->food);
        free(vars);
	}
}