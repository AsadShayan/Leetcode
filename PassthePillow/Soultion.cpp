class Solution {
public:
    int passThePillow(int n, int time) {
        int pillowPos = 1;
        bool reachedn = false;

        for (int i = 0; i < time; ++i) {
            if (pillowPos == n) {
                reachedn = true;
            } else if (pillowPos == 1) {
                reachedn = false;
            }

            if (reachedn) {
                pillowPos--;
            } else {
                pillowPos++;
            }
        }

        return pillowPos;
    }
};
