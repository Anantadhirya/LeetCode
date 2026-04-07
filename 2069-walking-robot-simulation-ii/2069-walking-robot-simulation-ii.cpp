class Robot {
public:
    int dir = 0;
    int x = 0, y = 0;
    int dx, dy, tmp;
    int w, h;
    int p;
    Robot(int width, int height) {
        w = width;
        h = height;
        p = (w-1) + (h-1) + (w-1) + (h-1);
    }
    
    void step(int num) {
        num = (num-1) % p + 1;
        while(num > 0) {
            tmp = num;
            if(dir == 0) dx = 1, dy = 0, tmp = min(tmp, (w-1) - x);
            else if(dir == 1) dx = 0, dy = 1, tmp = min(tmp, (h-1) - y);
            else if(dir == 2) dx = -1, dy = 0, tmp = min(tmp, x);
            else if(dir == 3) dx = 0, dy = -1, tmp = min(tmp, y);
            if(tmp == 0) dir = (dir+1)%4;
            
            x += dx*tmp;
            y += dy*tmp;
            num -= tmp;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir == 0) return "East";
        else if(dir == 1) return "North";
        else if(dir == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */