//Gaspard Gentil

#define MIN_INTENSITY 0
#define MAX_INTENSITY 255

class Pixel{
    private:

    int intensity;
    int flow[4];
    int capacity[4];
    int state;
    int sourceFlow;
    int sinkFlow;
    int sourceCapacity;
    int sinkCapacity;

    public:

    Pixel() : intensity(0), flow(), capacity(), state(0), sourceFlow(0), sinkFlow(0), sourceCapacity(0), sinkCapacity(0) {}
    Pixel(const int i);

    int getIntensity() const {return intensity;}
    void setIntensity(const int i) {intensity = i;}

    int getState() const { return state;}
    void setState(const int s) {state = s;}

    int getSourceFlow() const {return sourceFlow;}
    void setSourceFlow(const int value) {sourceFlow = value;}

    int getSinkFlow() const {return sinkFlow;}
    void setSinkFlow(const int value) {sinkFlow = value;}

    int getSourceCapacity() const {return sourceCapacity;}
    void setSourceCapacity(const int value) {sourceCapacity = value;}

    int getSinkCapacity() const {return sinkCapacity;}
    void setSinkCapacity(const int value) {sinkCapacity = value;}
};