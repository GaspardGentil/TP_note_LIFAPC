//Gaspard Gentil

#define MIN_INTENSITY 0
#define MAX_INTENSITY 255

class Pixel{
    private:

    int intensity; //intensity on the pixel (between 0 and 255)
    int state; //state of the pixel (visited or not)
    int sourceFlow; //flow of the source pixel
    int sinkFlow; //flow of the sink pixel
    int sourceCapacity; //capacity of the source pixel
    int sinkCapacity; //capacity of the sink pixel

    public:

    int flow[4]; //store the flow of the 4 neighbors
    int capacity[4]; //store the capacities of the 4 neighbors

    //default constructor
    Pixel() : intensity(0), state(0), sourceFlow(0), sinkFlow(0), sourceCapacity(0), sinkCapacity(0) {}
    Pixel(const int i); //constructor by value

    /****************/
    /*  Accessors   */
    /****************/

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