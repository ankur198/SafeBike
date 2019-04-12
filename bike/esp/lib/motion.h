class motion
{
  private:
    int motionPin;

  public:
    //motion(){};
    motion(int Pin);
    ~motion();
    bool isMotion();
    void init();
};

void motion::init()
{
    pinMode(motionPin, INPUT);
}
bool motion::isMotion()
{
    return digitalRead(motionPin) == 1 ? true : false;
}

motion::motion(int Pin)
{
    motionPin = Pin;
}

motion::~motion()
{
}
