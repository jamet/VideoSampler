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
                if (playModes.vBuffer.getNextVideoFrame()!= NULL){
                    playModes.vBuffer.getNextVideoFrame().getTextureRef().draw(640 , 480, 960, 720);
                }else cout<<"nulllllllllllllllllllllllllllll"<<endl;

                cout<<"setframepos"<<playHead<<" framepos "<<playModes.vBuffer.framePos<<endl;
                playModes.vBuffer.iterFramePos();
                cout<<"iterframepos"<<playHead<<" framepos "<<playModes.vBuffer.framePos<<endl;


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
        //playHead=playStart;
cout<<"record position++"<<recordPosition<<" framepos "<<playModes.vBuffer.framePos<<endl;
        //playModes.update();
        if (bRecLiveInput){
            playModes.vBuffer.setFramePos(getRecordPostion()/100);
            playHead=playStart;
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
                playModes.vBuffer.setFramePos(playHead);

            }

        }else
        {

            playModes.vBuffer.stop();
            playModes.vBuffer.setFramePos(playHead);
            //playModes.vBuffer.draw();
            if (bPlayBuffer){
                //playModes.vBuffer.setFramePos(playHead);
              /*  if (playModes.vBuffer.getNextVideoFrame()!= NULL){
                    playModes.vBuffer.getNextVideoFrame().getTextureRef().draw(640 , 480, 960, 720);
                }else cout<<"nulllllllllllllllllllllllllllll"<<endl;

                cout<<"setframepos"<<playHead<<" framepos "<<playModes.vBuffer.framePos<<endl;
                playModes.vBuffer.iterFramePos();
                cout<<"iterframepos"<<playHead<<" framepos "<<playModes.vBuffer.framePos<<endl;*/

                updatePlayHead();
            }

        }

    cout<<"record position"<<getRecordPostion()<<endl;
    playModes.setSpeed(speed);


    playModes.update();

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
        cout<<"playhead++"<<playHead<<endl;
        //playModes.vBuffer.iterFramePos();
        //playModes.vRenderer.
    }else {
        playHead=playStart;
        //playModes.vBuffer.setFramePos(playHead);

        bRecLiveInput=false;
    }

    playModes.vBuffer.setFramePos(playHead);

    if(ofGetFrameNum()==100){
        speed = 1.0;
    }

    cout<<"playhead"<<playHead<<endl;
}

float VideoSampler::getRecordPostion(){
    return recordPosition;
}
