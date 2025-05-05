namespace targets {
class Alien{
    public:
        Alien(int x, int y){
            this->x_coordinate  = x;
            this->y_coordinate  = y;
        }
        int x_coordinate = 0;
        int y_coordinate = 0;

        int get_health(){
            return health;
        }
        bool hit(){
            if (this->health > 0)
                this->health -= 1;
            else
                this->health = 0;
            return true;
        }
        bool is_alive(){
            if (this->health > 0)
                return true;
            else
                return false;
        }
        bool teleport(int x, int y){
            this->x_coordinate = x;
            this->y_coordinate = y;
            return true;
        }

        bool collision_detection(Alien other_alien){
            if (this->x_coordinate == other_alien.x_coordinate && this->y_coordinate == other_alien.y_coordinate)
                return true;
            else
                return false;
        }
    private:
        int health = 3;
};
}  // namespace targets