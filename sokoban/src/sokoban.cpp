#include "raylib.h"
#include "globals.h"
#include "level.h"
#include "graphics.h"
#include "images.h"
#include "sounds.h"
#include "iostream"

void update_game() {
    switch (game_state) {
        case MENU_STATE:
            SetExitKey(KEY_ESCAPE);
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = GAME_STATE;
            }
            break;
        case GAME_STATE:
            SetExitKey(0);
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                game_player.move(0, -1);
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                game_player.move(0, 1);
            } else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
                game_player.move(-1, 0);
            } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                game_player.move(1, 0);
            } else if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = RELOAD_REQ_STATE;
            }
            break;
        case RELOAD_REQ_STATE:
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER)) {
                game_state = GAME_STATE;
            } else if (IsKeyPressed(KEY_R)) {
                game_level.unload();
                level_index--;
                game_level.load_next();
                game_state = GAME_STATE;
            }
            break;
        case VICTORY_STATE:
            SetExitKey(KEY_ESCAPE);
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = MENU_STATE;
            }
            break;
    }
}

void draw_game() {
    ++game_frame;

    switch (game_state) {
        case MENU_STATE:
            draw_menu();
            break;
        case GAME_STATE:
            draw_loaded_level();
            draw_player();
            draw_player_level();
            break;
        case RELOAD_REQ_STATE:
            draw_reload_req_menu();
            break;
        case VICTORY_STATE:
            draw_victory_menu();
            break;
    }
}

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(1024, 480, "Sokoban");
    SetTargetFPS(60);
    HideCursor();

    load_fonts();
    load_images();
    load_sounds();

    game_level.load_next();

    while (!WindowShouldClose()) {
        BeginDrawing();

        try{
            update_game();
            draw_game();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        };

        EndDrawing();
    }
    CloseWindow();

    game_level.unload();
    unload_sounds();
    unload_images();
    unload_fonts();

    return 0;
}
