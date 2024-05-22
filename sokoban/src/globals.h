#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

#include <string>
#include <cstddef>

/* Game Elements */

constexpr char WALL = '#';
constexpr char FLOOR = '-';
constexpr char BOX = '$';
constexpr char BOX_ON_GOAL = '*';
constexpr char GOAL = '.';
constexpr char PLAYER = '@';
constexpr char PLAYER_ON_GOAL = '+';

/* Levels */

class level;
class player;

extern level game_level;
extern player& game_player;

//level game_level = level();
//
//player* game_player = player::get_instance();

//struct level {
//    size_t rows = 0, columns = 0;
//    char *data = nullptr;
//};
//
extern char LEVEL_1_DATA[];

//level LEVEL_1 = {
//    11, 19,
//    LEVEL_1_DATA
//};
//
//char LEVEL_2_DATA[] = {
//    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ',
//    '#', '.', '.', '-', '-', '#', '-', '-', '-', '-', '-', '#', '#', '#',
//    '#', '.', '.', '-', '-', '#', '-', '$', '-', '-', '$', '-', '-', '#',
//    '#', '.', '.', '-', '-', '#', '$', '#', '#', '#', '#', '-', '-', '#',
//    '#', '.', '.', '-', '-', '-', '-', '@', '-', '#', '#', '-', '-', '#',
//    '#', '.', '.', '-', '-', '#', '-', '#', '-', '-', '$', '-', '#', '#',
//    '#', '#', '#', '#', '#', '#', '-', '#', '#', '$', '-', '$', '-', '#',
//    ' ', ' ', '#', '-', '$', '-', '-', '$', '-', '$', '-', '$', '-', '#',
//    ' ', ' ', '#', '-', '-', '-', '-', '#', '-', '-', '-', '-', '-', '#',
//    ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
//};
//
//level LEVEL_2 = {
//    10, 14,
//    LEVEL_2_DATA
//};
//
//char LEVEL_3_DATA[] = {
//    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ',
//    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '-', '-', '-', '-', '-', '@', '#', ' ',
//    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '-', '$', '#', '$', '-', '#', '#', ' ',
//    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '-', '$', '-', '-', '$', '#', ' ', ' ',
//    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '$', '-', '$', '-', '#', ' ', ' ',
//    '#', '#', '#', '#', '#', '#', '#', '#', '#', '-', '$', '-', '#', '-', '#', '#', '#',
//    '#', '.', '.', '.', '.', '-', '-', '#', '#', '-', '$', '-', '-', '$', '-', '-', '#',
//    '#', '#', '.', '.', '.', '-', '-', '-', '-', '$', '-', '-', '$', '-', '-', '-', '#',
//    '#', '.', '.', '.', '.', '-', '-', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
//    '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
//};
//
//level LEVEL_3 = {
//    10, 17,
//    LEVEL_3_DATA
//};
//
const size_t LEVEL_COUNT = 3;
//level LEVELS[LEVEL_COUNT] = {
//    LEVEL_1,
//    LEVEL_2,
//    LEVEL_3
//};

/* Loaded Level Data */

//level level;
extern size_t level_index;
//
/* Player Data */
//
//size_t player_row;
//size_t player_column;

/* Graphics Metrics */

extern const float CELL_SCALE; // An aesthetic parameter to add some negative space around level
extern const float SCREEN_SCALE_DIVISOR; // The divisor was found through experimentation

extern float screen_width;
extern float screen_height;
extern float screen_scale; // Used to scale text/UI components size and displacements based on the screen size
extern float cell_size;
extern float shift_to_center_cell_by_x;
extern float shift_to_center_cell_by_y;

/* Fonts */

extern Font menu_font;

/* Menu Text Parameters */

extern const std::string MENU_TITLE;
extern const float MENU_TITLE_FONT_SIZE;
extern const float MENU_TITLE_Y_SHIFT;
extern const Color MENU_TITLE_COLOR;

extern const std::string MENU_SUBTITLE;
extern const float MENU_SUBTITLE_FONT_SIZE;
extern const float MENU_SUBTITLE_Y_SHIFT;
extern const Color MENU_SUBTITLE_COLOR;

/* Game Text Parameters */

extern const float GAME_LEVEL_FONT_SIZE;
extern const float GAME_LEVEL_Y_SHIFT;
extern const Color GAME_LEVEL_COLOR1;
extern const Color GAME_LEVEL_COLOR2;

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

extern const std::string RELOAD_REQ_TITLE;
extern const float RELOAD_REQ_TITLE_FONT_SIZE;
extern const float RELOAD_REQ_TITLE_Y_SHIFT;
extern const Color RELOAD_REQ_TITLE_COLOR ;

/* Victory Menu Background */

struct victory_ball {
    float x, y;
    float dx, dy;
    float radius;
};

const size_t VICTORY_BALL_COUNT = 2000;
extern const float VICTORY_BALL_MAX_SPEED;
extern const float VICTORY_BALL_MIN_RADIUS;
extern const float VICTORY_BALL_MAX_RADIUS;
extern const Color VICTORY_BALL_COLOR;
extern const unsigned char VICTORY_BALL_TRAIL_TRANSPARENCY;
extern victory_ball victory_balls[VICTORY_BALL_COUNT];

/* Victory Menu Text Parameters */

extern const std::string VICTORY_TITLE;
extern const float VICTORY_TITLE_FONT_SIZE;
extern const float VICTORY_TITLE_Y_SHIFT;
extern const Color VICTORY_TITLE_COLOR;

extern const std::string VICTORY_SUBTITLE;
extern const float VICTORY_SUBTITLE_FONT_SIZE;
extern const float VICTORY_SUBTITLE_Y_SHIFT;
extern const Color VICTORY_SUBTITLE_COLOR;

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

// LEVELS_H

//void load_next_level();
//void unload_level();
//bool is_cell_inside_level(int row, int column);
//char& get_level_cell(size_t row, size_t column);
//void set_level_cell(size_t row, size_t column, char cell);

// PLAYER_H

//void spawn_player(size_t row, size_t column);
//void move_player(int dx, int dy);

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
