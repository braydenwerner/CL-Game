#ifndef PLAYER_H
#define PLAYER_H
class Player {
private:
    int row, col;
    int current_height_diff = 0, max_height_diff = 5, update_count = 0;
    const int update_interval = 70;
    bool jumping = false, falling = false;
public:
    Player(int row, int col);
    void update();
    void jump();
    int getRow();
    int getCol();
};
#endif