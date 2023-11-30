//Gaspard Gentil

#define MIN_INTENSITY 0
#define MAX_INTENSITY 255

class Pixel{
    private:

    int intensity;
    int flow[6];
    int capacity[6];
    int state;

    public:

    Pixel();
    Pixel(const int i);

    int getIntensity() const {return intensity;}
    void setIntensity(const int i) {intensity = i;}

    int getState() const { return state;}
    void setState(const int s) {state = s;}

    int getFlow(const int index) const;
    void setFlow(const int index, const int value);

    int getCapacity(const int index) const;
    void setCapacity(const int index, const int value);

};