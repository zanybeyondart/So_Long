#include "game.h"

void free_animation(animation *anim) {
    if (anim) {
		free_animation(anim->next);
        free(anim->img);
        free(anim);
        }
    }

void free_player(player *p) {
    if (p) {
		free_animation(p->idle);
		free(p);
		}
}

void free_vars(t_vars *vars) {
    if (vars)
	{
		free_player(vars->p1);
        free(vars);
	}
}