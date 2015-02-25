#include "VideoSampler.h"

void VideoSampler::setup(){
        bufferSize=512;
        playStart=0;
        playEnd=1.0;
        playModes.setup();

}

void VideoSampler::draw(){
    playModes.draw();
    playModes.drawPlayerData(playHead);

        //draw player videoframe
    if (playModes.vBuffer.getVideoFrame(playHead)!= NULL){

        ofSetColor(255,255,255);

        playModes.vBuffer.getVideoFrame(playHead).getTextureRef().draw(640 , 0, 320, 240);
                    cout<<"timestamp "<<playModes.vBuffer.getVideoFrame(playHead).getTimestamp().epochMicroseconds()<<endl;

    }

}


void VideoSampler::update(){
    if (bRecLiveInput){
        //playModes.vBuffer.clear();
        playModes.vBuffer.resume();
        playModes.vBuffer.setFramePos(getRecordPostion()/100);

            //increment recordPosition
        if (recordPosition<100){

                recordPosition++;
                cout<<"record position++"<<recordPosition<<" framepos "<<playModes.vBuffer.framePos<<endl;


            }else {

                recordPosition=0;
                //playHead=playStart;
                bRecLiveInput=false;
                bPlayBuffer=true;
                //playModes.vBuffer.setFramePos(playHead);

            }

    }
    else{

        playModes.vBuffer.stop();

        if (bPlayBuffer){

                updatePlayHead();

            }

    }

    //playModes.setSpeed(speed);
    playModes.update();

}

void VideoSampler::updatePlayHead(){

    if (playHead<playEnd){

        playHead+=0.01;

    }else {

        playHead=playStart;

        bRecLiveInput=false;
    }


   /* if(ofGetFrameNum()==100){
        speed = 1.0;
    }*/



    cout<<"playhead updated==========================="<<playHead<<"buffer framepos"<<playModes.vBuffer.getFramePos()<<endl;
}

float VideoSampler::getRecordPostion(){
    return recordPosition;
}
