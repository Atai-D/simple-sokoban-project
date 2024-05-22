#include "globals.h"
#include "level.h"
#include "player.h"

const size_t LEVEL_COUNT = get_level_count();

size_t level_index = -1;

float screen_width;
float screen_height;
float screen_scale;
float cell_size;
float shift_to_center_cell_by_x;
float shift_to_center_cell_by_y;

Font menu_font;

sprite player_sprite;

Texture2D wall_image;
Texture2D floor_image;
Texture2D goal_image;
Texture2D box_image;
Texture2D box_on_goal_image;

/* Sounds */

Sound goal_sound;
Sound exit_sound;

/* Victory Menu Background */

victory_ball victory_balls[VICTORY_BALL_COUNT];

size_t game_frame = 0;

enum game_state game_state = MENU_STATE;

// global instances of classes level and player
level game_level;
player& game_player = player::get_instance();
