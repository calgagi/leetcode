class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction = 0;
        int move[4] = {0, 0, 0, 0};
        for (int i = 0; i < instructions.length(); i++) {
            if (instructions[i] == 'L') {
                if (--direction < 0) direction = 3;
            }
            if (instructions[i] == 'R') direction = (direction + 1) % 4;
            if (instructions[i] == 'G') move[direction]++;
        }
        if (move[0] - move[2] == 0 && move[1] - move[3] == 0) return true;
        return direction;
    }
};
