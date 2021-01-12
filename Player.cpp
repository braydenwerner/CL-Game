#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player(int row, int col) {
    this->row = row;
    this->col = col;
}

void Player:: update() {
    if (update_count == update_interval) {
        update_count = 0;
        
        cout << "row: " << row << endl;
        
        if (jumping) {
            current_height_diff++;

            if (current_height_diff < max_height_diff) {
                row--;
            } else {
                jumping = false;
                falling = true;
            }
        } else if (falling) {
            current_height_diff--;

            if (current_height_diff > 0) {
                row++;
            } else {
                falling = false;
            }
        }
    }
    
    update_count++;
}

void Player::jump() {
    if (!falling) {
        jumping = true;
    }
}

int Player::getRow() {
    return row;
}

int Player::getCol() {
    return col;
}
