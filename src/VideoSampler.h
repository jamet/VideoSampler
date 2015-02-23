#pragma once

#include "ofMain.h"
#include "PlayModes.h"



class VideoSampler : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    //void updatePlayHead();
    float getRecordPostion();

    PlayModes playModes;

	float speed;
	float playHead;
	float loopSize;
	//Bool event for Recording Toggle/ resets play position relative to current Rec position
    void updatePlayHead();
    bool bUpdatePlayheadEvent;

    //Recording
    bool bSetPosition;
    bool bRecLiveInput;
    float recMix;
    float recordPosition;

    //Playing
    bool bPlayBuffer;
    float playStart;
    float playEnd;
    int bufferSize;
	int	sampleRate;

	//Drawing
    int curXpos, curYpos;
    int prevXpos, prevYpos;


};
