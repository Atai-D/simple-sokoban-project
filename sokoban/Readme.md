# Implementation
## `player` class
### Methods and Variables
1. public:
   - `static player& get_instance()`
   - `move(int dx, int dy)`
   - `spawn(int row, int column)`
   - `get_row()`
   - `get_column()`
2. private:
   - constructor
   - destructor
   - `int player_row, player_column`
### Solutions:
I implemented Singleton design pattern because in current iteration of the project only one player can be created.
## `level` class
### Methods and Variables
1. public:
   - constructor
   - destructor
   - `load_next()`
   - `unload()`
   - `is_cell_inside(int row, int column)`
   - `get_cell(size_t row, size_t column)`
   - `set_cell(size_t row, size_t column, char cell)`
   - `get_rows()`
   - `get_columns()`
2. private:
   - `int rows, columns`
   - `char *data`
## Parser
### Solution
For reading the .sl file I used `fstream`. 
After getting the whole text from the file, 
I just divide it by rows and then parse them one by one.
Also, I handle different errors: when trying to read the file and when trying to get the level which is out of bounce.
## Challenges
### Linker error
Because I use `game_level` instance of class `level` and `game_player` instance of class `player`
and because I wanted to make them global (so graphics module can get the values of instances globally and without passing parameters to the graphics functions).
Therefore, I created `globals.cpp` file: to initialize the instances globally.
Because of that, I had a lot of troubles with linker because of forward declarations and multiple definitions. 
The solution for me was to use `extern` keyword. 
So, I wrote variables names with `extern` in `globals.h` and declared them in `globals.cpp`.
## Other
### Debugging and Testing
For faster testing purposes I rewrote `levels.sl` to move not 6+ boxes, but just one:
``` 
4 5#|4 #3-#|4 #$2-#|2 3#2-$2#|2 #2-$-$-#|3#-#-2#-#3-6#|#3-#-2#-5#2-#|#--$2-$10-#|5#-3#-#-2#-@$.#|4 #5-9#|4 7#
; Level 1
12#|###2-#5-3#|#2#2-#-$2-$2-#|#2#2-#$4#2-#|#2#4-@-2#2-#|##.$-#-#2-$-2#|6#-2#$-$-#|2 #-$2-$-$-$-#|2 #4-#5-#|2 12#
; Level 2
8 8#|8 #5-@#|8 #-$#$-2#|8 #-$2-$#|8 2#$-$-#|9#-$-#-3#|#4#2-2#-$2-$2-#|2#3#4-$2-$3-#|####.$@10#|8#
; Level 3 
```