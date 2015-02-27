#include "VideoSampler.h"

void VideoSampler::setup(){
        bufferSize=512;
        playStart=0;
        playEnd=1.0;
        fps=30;

        //setup grabber
        vGrabber.initGrabber(640,480);
        vGrabber.setVerbose(true);

        //setup Buffer
        vRate.setup(vGrabber,fps);
        vBuffer.setup(vRate,NUM_FRAMES,true);

}

void VideoSampler::draw(){
    //playModes.draw();
    //playModes.drawPlayerData(playHead);

        //draw player videoframe

    if ((vBuffer.getVideoFrame(playHead)!= NULL)&&(bPlayBuffer)){

        ofSetColor(255,255,255);

        vBuffer.getVideoFrame((int)playHead).getTextureRef().draw(640 , 0, 320, 240);
                    cout<<"timestamp "<<vBuffer.getVideoFrame((int)playHead).getTimestamp().epochMicroseconds()<<endl;

    }cout<<"null"<<endl;


    ofDrawBitmapString("FPS: " + ofToString(int(ofGetFrameRate()))
                       + " || cameraBuffer FPS " + ofToString(vBuffer.getRealFPS())
                       //+ " || videoframes pool size: " + ofToString(VideoFrame::getPoolSize(VideoFormat(640,480,3)))
                       + " || total frames: " +ofToString(NUM_FRAMES),20,ofGetHeight()-40);


    drawPlayerData(playHead/NUM_FRAMES);

}


void VideoSampler::update(){
    vGrabber.update();

    if (bRecLiveInput){
        //playModes.vBuffer.clear();
        vBuffer.resume();
        cout<<"buffer resume"<<endl;
        vBuffer.setFramePos((int)recordPosition);
        cout<<"setframepos "<<recordPosition<<endl;

            //increment recordPosition
        if (recordPosition<NUM_FRAMES-1){
                //vBuffer.setFramePos((int)recordPosition);
                recordPosition++;
                cout<<"record position++"<<recordPosition<<"playhead "<<playHead<<" framepos "<<vBuffer.framePos<<endl;



            }else {

                //recordPosition=0;
                //playHead=playStart;
                bRecLiveInput=false;
                bPlayBuffer=true;
                recordPosition=0;
                //vBuffer.setFramePos(playHead);

            }

    }
    else{

        vBuffer.stop();

        if (bPlayBuffer){

                updatePlayHead();

            }

    }

    //vRate.setSpeed(speed);


}

void VideoSampler::updatePlayHead(){

    if (playHead/NUM_FRAMES<playEnd){

        playHead++;

    }else {

        playHead=playStart*NUM_FRAMES;

        bRecLiveInput=false;
    }


    if(ofGetFrameNum()==100){
        speed = 1.0;
    }



    cout<<"playhead updated==========================="<<playHead<<"buffer framepos"<<vBuffer.getFramePos()<<endl;
}

float VideoSampler::getRecordPostion(){
    return recordPosition;
}

void VideoSampler::drawPlayerData(float _playheadPerc){



    const float waveformWidth  = ofGetWidth() - 40;
    const float waveformHeight = 300;

    float top = ofGetHeight() - waveformHeight - 20;
    float left = 20;
    float framePosPerc;

    ////////// Video Header Play Pos ///////////////////////
    ofSetColor(255,0,0);
    ofDrawBitmapString("Video Header Play Pos", left, top-10);
  //  ofLine(left, top, waveformWidth, top);

    // frame pos
    ofSetColor(0,0,255);
    framePosPerc = (float)vBuffer.getFramePos() / (float)NUM_FRAMES;
    ofLine(left+ (framePosPerc * (waveformWidth-left)), top, left+ (framePosPerc * (waveformWidth-left)), top+waveformHeight);
    ofDrawBitmapString("FramePos", left + framePosPerc * waveformWidth-76, top+45);

    ofCircle(left+(framePosPerc*(waveformWidth-left)), top, 10);

    // player frame pos
    ofSetColor(0,255,255);
    framePosPerc = _playheadPerc ;
    ofLine(left+ (framePosPerc * (waveformWidth-left)), top, left+ (framePosPerc * (waveformWidth-left)), top+waveformHeight);
    ofDrawBitmapString("PlayheadPos", left + framePosPerc * waveformWidth-76, top+45);

    ofCircle(left+(framePosPerc*(waveformWidth-left)), top, 10);
}

