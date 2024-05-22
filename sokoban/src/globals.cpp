#include "globals.h"
#include "level.h"
#include "player.h"

char LEVEL_1_DATA[] = {
        ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', '#', '-', '-', '-', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', '#', '$', '-', '-', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', '#', '#', '#', '-', '-', '$', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', '#', '-', '-', '$', '-', '$', '-', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        '#', '#', '#', '-', '#', '-', '#', '#', '-', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#',
        '#', '-', '-', '-', '#', '-', '#', '#', '-', '#', '#', '#', '#', '#', '-', '-', '.', '.', '#',
        '#', '-', '$', '-', '-', '$', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '.', '. ', '#',
        '#', '#', '#', '#', '#', '-', '#', '#', '#', '-', '#', '@', '#', '#', '-', '-', '.', '.', '#',
        ' ', ' ', ' ', ' ', '#', '-', '-', '-', '-', '-', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
};

size_t level_index = -1;


const float CELL_SCALE = 0.6f; // An aesthetic parameter to add some negative space around level
const float SCREEN_SCALE_DIVISOR = 700.0f; // The divisor was found through experimentation
// to scale things accordingly to look pleasant.

float screen_width;
float screen_height;
float screen_scale; // Used to scale text/UI components size and displacements based on the screen size
float cell_size;
float shift_to_center_cell_by_x;
float shift_to_center_cell_by_y;

Font menu_font;

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

sprite player_sprite;


Texture2D wall_image;
Texture2D floor_image;
Texture2D goal_image;
Texture2D box_image;
Texture2D box_on_goal_image;



/* Sounds */

Sound goal_sound;
Sound exit_sound;

/* Reload Request Text Parameters */

const std::string RELOAD_REQ_TITLE     = "Press R to restart the level";
const float RELOAD_REQ_TITLE_FONT_SIZE = 30.0f;
const float RELOAD_REQ_TITLE_Y_SHIFT   = 0.0f;
const Color RELOAD_REQ_TITLE_COLOR     = WHITE;

/* Victory Menu Background */

//const size_t VICTORY_BALL_COUNT     = 2000;
const float VICTORY_BALL_MAX_SPEED  = 2.0f;
const float VICTORY_BALL_MIN_RADIUS = 2.0f;
const float VICTORY_BALL_MAX_RADIUS = 3.0f;
const Color VICTORY_BALL_COLOR      = { 180, 180, 180, 255 };
const unsigned char VICTORY_BALL_TRAIL_TRANSPARENCY = 10;
victory_ball victory_balls[VICTORY_BALL_COUNT];


/* Victory Menu Text Parameters */
const std::string VICTORY_TITLE     = "You Won!";
const float VICTORY_TITLE_FONT_SIZE = 200.0f;
const float VICTORY_TITLE_Y_SHIFT   = 10.0f;
const Color VICTORY_TITLE_COLOR     = RED;

const std::string VICTORY_SUBTITLE     = "Press Enter to go back to menu";
const float VICTORY_SUBTITLE_FONT_SIZE = 30.0f;
const float VICTORY_SUBTITLE_Y_SHIFT   = 80.0f;
const Color VICTORY_SUBTITLE_COLOR     = WHITE;

size_t game_frame = 0;

enum game_state game_state = MENU_STATE;

// Define global instances of Level and Player
level game_level;
player& game_player = player::get_instance();
