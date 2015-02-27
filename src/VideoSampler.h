#pragma once

#include "ofMain.h"
//#include "PlayModes.h"
#include "VideoBuffer.h"
#include "VideoGrabber.h"
#include "VideoRate.h"

#define NUM_FRAMES 515


class VideoSampler : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();


    float getRecordPostion();
    void drawPlayerData(float _playhead);
    //PlayModes playModes;
    // Grabber and Buffer
    ofxPm::VideoGrabber vGrabber;
    //ofVideoGrabber vGrabber;
    ofxPm::VideoBuffer vBuffer;
    ofxPm::VideoRate vRate;

    int fps;
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
    bool bPauseBuffer;
    float playStart;
    float playEnd;
    int bufferSize;
	int	sampleRate;

	//Drawing
    int curXpos, curYpos;
    int prevXpos, prevYpos;


};
