#include <allegro.h>
#define MAXROWS 20
#define MAXCOLS 30
BITMAP *buffer;
BITMAP *rock;
BITMAP *food;


char map[MAXROWS][MAXCOLS] = {
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X          XXXXXXX          X",
    "X XXX XXXX XXXXXXX XXXX XXX X",
    "X XXX XXXX XXXXXXX XXXX XXX X",
    "X                           X",
    "X XXX XX XXXXXXXXXXX XX XXX X",
    "X                           X",
    "X XXX XXXXXX XXX XXXXXX XXX X",
    "X XXX XX             XX XXX X",
    "X     XX XXXXXXXXXXX XX     X",
    "X XXX XX XXXXXXXXXXX XX XXX X",
    "X XXX XX             XX XXX X",
    "X XXX XXXXXX XXX XXXXXX XXX X",
    "X     XX     XXX     XX     X",
    "X XXX XX XXXXXXXXXXX XX XXX X",
    "X XXX                   XXX X",
    "X XXX XX XXXXXXXXXXX XX XXX X",
    "X XXX XX             XX XXX X",
    "X        XXXXXXXXXXX        X",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};


void draw_map() {
    int row, col;


   for(row = 0; row < MAXROWS; row++){
        for(col = 0; col < MAXCOLS; col++){
            if(map[row][col] == 'X') {
                draw_sprite(buffer, rock, col*30, row*30);
            }
            else {
                draw_sprite(buffer, food, col*30, row*30);
            }
        }
    }
}


void show_screen(){
    blit(buffer, screen, 0,0,0,0, 876,600);
}


int main()
{
    allegro_init();
    install_keyboard();


   set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 876, 600, 0, 0);


   buffer = create_bitmap(876,600);
   rock = load_bitmap("roca.bmp", NULL);
   food = load_bitmap("Comida.bmp", NULL);


   while(!key[KEY_ESC]){
        draw_map();
        show_screen();
    }

    delete buffer, rock, food;
}
END_OF_MAIN();
