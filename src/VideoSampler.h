#pragma once

#include "ofMain.h"
#include "PlayModes.h"



class VideoSampler : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    PlayModes playModes;

};
