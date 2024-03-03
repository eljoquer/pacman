#include <allegro.h>
#define MAXROWS 20
#define MAXCOLS 30
BITMAP *buffer;
BITMAP *rock;
BITMAP *pacbmp;
BITMAP *pacman;
BITMAP *food;

int dir = 0;
int px = 30*10, py = 30*10;

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

void crear_personaje() {
    blit(pacbmp,pacman, dir*33,0,0,0,33,33);
    draw_sprite(buffer, pacman, px,py);
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
   pacbmp = load_bitmap("pacman.bmp",NULL);
   pacman = create_bitmap(33,33);



   while(!key[KEY_ESC]){
        if(key[KEY_RIGHT]) dir = 1; //When dir = 0 move to right
        else if(key[KEY_LEFT]) dir = 0;
        else if(key[KEY_UP]) dir = 2;
        else if(key[KEY_DOWN]) dir = 3;

        //asociarle las dirreciones para mover a pacman
        if(dir == 0) px -= 30; //Fotogramas ->
        if(dir == 1) px += 30; //componente en x
        if(dir == 2) py -= 30;
        if(dir == 3) py += 30;

        clear(buffer);
        draw_map();
        crear_personaje();
        show_screen();
        rest(70);

        clear(pacman);
        blit(pacbmp,pacman, 4*33,0,0,0,33,33);
        draw_sprite(buffer, pacman, px,py);
        show_screen();
        rest(70);
    }
}
END_OF_MAIN();
