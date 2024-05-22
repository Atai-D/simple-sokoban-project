#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

#include <string>
#include <cstddef>

/* Game Elements */

const char WALL = '#';
const char FLOOR = '-';
const char BOX = '$';
const char BOX_ON_GOAL = '*';
const char GOAL = '.';
const char PLAYER = '@';
const char PLAYER_ON_GOAL = '+';

/* Levels */

class level;
class player;

extern level game_level;
extern player& game_player;

extern const size_t LEVEL_COUNT;

extern size_t level_index;

/* Graphics Metrics */

const float CELL_SCALE = 0.6f;
const float SCREEN_SCALE_DIVISOR = 700.0f;

extern float screen_width;
extern float screen_height;
extern float screen_scale;
extern float cell_size;
extern float shift_to_center_cell_by_x;
extern float shift_to_center_cell_by_y;

/* Fonts */

extern Font menu_font;

/* Menu Text Parameters */

const std::string MENU_TITLE     = "Sokoban";
const float MENU_TITLE_FONT_SIZE = 200.0f;
const float MENU_TITLE_Y_SHIFT   = 10.0f;
const Color MENU_TITLE_COLOR     = RED;

const std::string MENU_SUBTITLE     = "Press Enter to start the game";
const float MENU_SUBTITLE_FONT_SIZE = 30.0f;
const float MENU_SUBTITLE_Y_SHIFT   = 80.0f;
const Color MENU_SUBTITLE_COLOR     = WHITE;

/* Game Text Parameters */

const float GAME_LEVEL_FONT_SIZE = 70.0f;
const float GAME_LEVEL_Y_SHIFT   = 30.0f;
const Color GAME_LEVEL_COLOR1    = GRAY;
const Color GAME_LEVEL_COLOR2    = WHITE;

/* Images and Sprites */

extern Texture2D wall_image;
extern Texture2D floor_image;
extern Texture2D goal_image;
extern Texture2D box_image;
extern Texture2D box_on_goal_image;

struct sprite {
    size_t frame_count    = 0;
    size_t frames_to_skip = 3;
    size_t frames_skipped = 0;
    size_t frame_index    = 0;
    bool loop = true;
    size_t prev_game_frame = 0;
    Texture2D *frames = nullptr;
};

extern sprite player_sprite;

/* Sounds */

extern Sound goal_sound;
extern Sound exit_sound;

/* Reload Request Text Parameters */

const std::string RELOAD_REQ_TITLE     = "Press R to restart the level";
const float RELOAD_REQ_TITLE_FONT_SIZE = 30.0f;
const float RELOAD_REQ_TITLE_Y_SHIFT   = 0.0f;
const Color RELOAD_REQ_TITLE_COLOR     = WHITE;

/* Victory Menu Background */

struct victory_ball {
    float x, y;
    float dx, dy;
    float radius;
};

const size_t VICTORY_BALL_COUNT = 2000;
const float VICTORY_BALL_MAX_SPEED  = 2.0f;
const float VICTORY_BALL_MIN_RADIUS = 2.0f;
const float VICTORY_BALL_MAX_RADIUS = 3.0f;
const Color VICTORY_BALL_COLOR      = { 180, 180, 180, 255 };
const unsigned char VICTORY_BALL_TRAIL_TRANSPARENCY = 10;
extern victory_ball victory_balls[VICTORY_BALL_COUNT];

/* Victory Menu Text Parameters */
const std::string VICTORY_TITLE     = "You Won!";
const float VICTORY_TITLE_FONT_SIZE = 200.0f;
const float VICTORY_TITLE_Y_SHIFT   = 10.0f;
const Color VICTORY_TITLE_COLOR     = RED;

const std::string VICTORY_SUBTITLE     = "Press Enter to go back to menu";
const float VICTORY_SUBTITLE_FONT_SIZE = 30.0f;
const float VICTORY_SUBTITLE_Y_SHIFT   = 80.0f;
const Color VICTORY_SUBTITLE_COLOR     = WHITE;

/* Frame Counter */

extern size_t game_frame;

/* Game State */

enum game_state {
    MENU_STATE,
    GAME_STATE,
    RELOAD_REQ_STATE,
    VICTORY_STATE
};

extern game_state game_state;

/* Forward Declarations */
// GRAPHICS_H

void draw_menu();
void draw_player_level();
void derive_graphics_metrics_from_loaded_level();
void draw_loaded_level();
void draw_player();
void draw_reload_req_menu();
void create_victory_menu_background();
void animate_victory_menu_background();
void draw_victory_menu_background();
void draw_victory_menu();

// IMAGES_H

void load_fonts();
void unload_fonts();

void load_images();
void unload_images();
void draw_image(Texture2D image, float x, float y, float width, float height);
void draw_image(Texture2D image, float x, float y, float size);

sprite load_sprite(
    const std::string &file_name_prefix,
    const std::string &file_name_suffix,
    size_t frame_count = 1,
    bool loop = true,
    size_t frames_to_skip = 3
);
void unload_sprite(sprite &sprite);
void draw_sprite(sprite &sprite, float x, float y, float width, float height);
void draw_sprite(sprite &sprite, float x, float y, float size);

// SOUNDS_H

void load_sounds();
void unload_sounds();
void play_sound(Sound sound);

#endif // GLOBALS_H
