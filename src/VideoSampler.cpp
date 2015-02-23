#include "VideoSampler.h"

void VideoSampler::setup(){
        bufferSize=512;
        playStart=0;
        playEnd=0;
        playModes.setup();

}

void VideoSampler::draw(){
    cout<<"draw"<<endl;
        playModes.draw();
        playModes.drawData();

 /*       // draw a playhead over the waveform
    ofSetColor(ofColor::white);
    ofLine(left + ps->getNormalisedPosition() * waveformWidth, top, left + ps->getNormalisedPosition() * waveformWidth, top + waveformHeight);
    ofDrawBitmapString("PlayHead", left + ps->getNormalisedPosition() * waveformWidth-69, top+30);

    // Draw Current Recording Position
    ofSetColor(ofColor::red);
    ofLine(left + getRecordPostion() * waveformWidth, top, left + getRecordPostion() * waveformWidth, top + waveformHeight);
    ofDrawBitmapString("RecPos", left + getRecordPostion() * waveformWidth-52, top+15);

    // draw a frame around the whole thing
    ofSetColor(ofColor::white);
    ofNoFill();
    ofRect(left, top, waveformWidth, waveformHeight);*/
}


void VideoSampler::update(){
        cout<<"update"<<endl;

        playModes.update();
        if (bRecLiveInput){
            playModes.vBuffer.setFramePos(getRecordPostion()/100);
        }else
        {
            playModes.vBuffer.stop();
            //playModes.vBuffer.draw();
            if (bPlayBuffer){
                playModes.vBuffer.setFramePos(playHead);
                updatePlayHead();
            }

        }

    cout<<"record position"<<getRecordPostion()<<endl;
    playModes.setSpeed(speed);

    //increment recordPosition
    if (recordPosition<100){
        recordPosition++;
    }else {
        recordPosition=0;
        playHead=0;
        bRecLiveInput=false;
        bPlayBuffer=true;
    }


   /* if(bRecLiveInput==false){
        if(!grainPlayer.bSetPosition==true){
            playModes.setDelay(grainPlayer.ps->getNormalisedPosition());
        }
    }
    else if(grainPlayer.bRecLiveInput==true){
        playModes.setDelay(grainPlayer.ps->getNormalisedPosition());
    }*/
}

void VideoSampler::updatePlayHead(){
    /*if(!bSetPosition) {
        if(bUpdatePlayheadEvent==true){
            ps->setPosition(ofMap(samp.recordPosition,0,LENGTH,0.0,1.0));
        }
        bUpdatePlayheadEvent = false;
    } else {
        bUpdatePlayheadEvent = true;
    }
*/
    if (playHead<playEnd){

        playHead+=0.01;
        //playModes.vBuffer.iterFramePos();
        //playModes.vRenderer.
    }else {
        playHead=playStart;
        bRecLiveInput=false;
    }
    if(ofGetFrameNum()==100){
        speed = 1.0;
    }

    cout<<"playhead"<<playHead<<endl;
}

float VideoSampler::getRecordPostion(){
    return recordPosition;
}
