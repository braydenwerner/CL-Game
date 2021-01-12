#include <iostream>
#include <termbox.h>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctype.h>
#include <algorithm> 
#include <cstdio>
#include "Player.hpp"

using namespace std;
using namespace chrono;

const int screen_width = tb_width(), screen_height = tb_width();
int current_theme = 0;

void render_player() {

}

int main(int argc, char *argv[]) {
    tb_event e;
    tb_init();
    tb_select_output_mode(TB_OUTPUT_256);

    bool running = true;
    
    Player player(screen_width,screen_height);
    
    while (running) {
        tb_set_clear_attributes();
        tb_clear();
        
        player.update();
        render_player();

        tb_present();
        
        bool input = tb_poll_event(&e);

        if (input) {
            switch (e.type) {
            case TB_EVENT_KEY:
                switch (e.key) {
                case TB_KEY_CTRL_C:
                case TB_KEY_ESC:
                    running = false;
                    break;
                case TB_KEY_SPACE:
                    player.jump();
                    break;
                }

            }
        }
    }
    
    tb_shutdown();
}