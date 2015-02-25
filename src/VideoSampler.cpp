#include "VideoSampler.h"

void VideoSampler::setup(){
        bufferSize=512;
        playStart=0;
        playEnd=1.0;
        playModes.setup();

}

void VideoSampler::draw(){
    cout<<"draw"<<endl;
        playModes.draw();
        playModes.drawData();
                if (playModes.vBuffer.getVideoFrame(playHead)!= NULL){

                    playModes.vBuffer.getVideoFrame(playHead).getTextureRef().draw(640 , 0, 320, 240);
                    cout<<"timestamp "<<playModes.vBuffer.getVideoFrame(playHead).getTimestamp().epochMicroseconds()<<endl;

                }

                cout<<"setframepos"<<playHead<<" framepos "<<playModes.vBuffer.framePos<<endl;
                //playModes.vBuffer.iterFramePos();
                cout<<"iterframepos"<<playHead<<" framepos "<<playModes.vBuffer.framePos<<endl;


}


void VideoSampler::update(){
        cout<<"update"<<endl;
        //playHead=playStart;
cout<<"record position u"<<recordPosition<<" framepos "<<playModes.vBuffer.framePos<<endl;
        //playModes.update();
        if (bRecLiveInput){
            playModes.vBuffer.resume();
            playModes.vBuffer.setFramePos(getRecordPostion()/100);
            //playHead=playStart;

            //increment recordPosition
            if (recordPosition<100){
                //playEnd=recordPosition/100;
                recordPosition++;
                cout<<"record position++"<<recordPosition<<" framepos "<<playModes.vBuffer.framePos<<endl;


            }else {

                recordPosition=0;
                //playHead=playStart;
                bRecLiveInput=false;
                bPlayBuffer=true;
                //playModes.vBuffer.setFramePos(playHead);

            }

        }else
        {

            playModes.vBuffer.stop();
            //playModes.vBuffer.setFramePos(playHead);
            //playModes.vBuffer.draw();
            if (bPlayBuffer){

                updatePlayHead();

            }

        }

    cout<<"record position"<<getRecordPostion()<<endl;
    //playModes.setSpeed(speed);


    playModes.update();
    cout<<"header loop"<<playModes.vHeader.getLoopMode()<< " header is playing "<<playModes.vHeader.isPlaying()<<endl;


}

void VideoSampler::updatePlayHead(){

    if (playHead<playEnd){

        playHead+=0.01;
        cout<<"playhead++"<<playHead<<endl;

    }else {

        playHead=playStart;

        bRecLiveInput=false;
    }


    if(ofGetFrameNum()==100){
        speed = 1.0;
    }



    cout<<"playhead updated==========================="<<playHead<<"buffer framepos"<<playModes.vBuffer.getFramePos()<<endl;
}

float VideoSampler::getRecordPostion(){
    return recordPosition;
}
