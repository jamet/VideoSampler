#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofSetVerticalSync(true);
	ofEnableAlphaBlending();
    ofSetFrameRate(30);

    VS.setup();

    //GUI
    gui = new ofxUICanvas();
    gui->addLabel("Video Sampler");
   //    gui->setFont("GUI/Fett.ttf");
    gui->addSpacer();


    gui->addToggle("Record Input", false);
    //gui->addToggle("Set Position", &avgs.grainPlayer.bSetPosition);
    gui->addSlider("Position", 0.0, 1.0, 1.0);
    gui->addSpacer();
    gui->addSlider("Current Buffer", 0.0, 4.0, 0.0);
    gui->addSlider("Play Start", 0.0, 1.0, 0.0);
    gui->addSlider("Play End", 0.0, 1.0, 1.0);
    gui->addToggle("Play Buffer", false);
    gui->addToggle("Pause Buffer", false);
    gui->addSpacer();
    gui->addToggle("Buffer 0", false);
    gui->addToggle("Buffer 1", false);
    gui->addToggle("Buffer 2", false);
    gui->addToggle("Buffer 3", false);

 //   gui->addSlider("Loop ESize", 0.0 ,1.0, 0.0);

    gui->autoSizeToFitWidgets();

    gui->loadSettings("GUI/guiSettings.xml");
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

    VS.update();

    //update gui
    ofxUILabelToggle *Play = (ofxUILabelToggle*)gui->getWidget("Play Buffer");
    Play->setValue(VS.bPlayAnyBuffer);

    ofxUILabelToggle *Rec = (ofxUILabelToggle*)gui->getWidget("Record Input");
    Rec->setValue(VS.bRecLiveInput);

        //update playbuffer <numbuffer> toggle
    ofxUILabelToggle *buff0 = (ofxUILabelToggle*)gui->getWidget("Buffer 0");
    buff0->setValue(VS.bPlayBuffer[0]);

    ofxUILabelToggle *buff1 = (ofxUILabelToggle*)gui->getWidget("Buffer 1");
    buff1->setValue(VS.bPlayBuffer[1]);

    ofxUILabelToggle *buff2 = (ofxUILabelToggle*)gui->getWidget("Buffer 2");
    buff2->setValue(VS.bPlayBuffer[2]);

    ofxUILabelToggle *buff3 = (ofxUILabelToggle*)gui->getWidget("Buffer 3");
    buff3->setValue(VS.bPlayBuffer[3]);
}

//--------------------------------------------------------------
void ofApp::draw(){
    VS.draw();
}

void ofApp::guiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
	int kind = e.widget->getKind();

    if(name == "Position")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;

        VS.vBuffer[VS.currentBufferNum]->setFramePos(slider->getScaledValue());
      //  VS.recordPosition = (int)(slider->getScaledValue()/NUM_FRAMES);
      //  cout<<VS.recordPosition<<endl;
	}
	else  if(name == "Current Buffer")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;

        VS.currentBufferNum = (int)slider->getScaledValue();
	}
	else  if(name == "Play Start")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;

        VS.playStart = slider->getScaledValue();


	}
	else  if(name == "Play End")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;

        VS.playEnd = slider->getScaledValue();
	}

    else if(name == "Record Input"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue()==true){
            VS.bRecLiveInput = true;
            //VS.playModes.vBuffer.setFramePos((float)0);
            //VS.vBuffer.clear();
        } else {

            VS.bRecLiveInput = false;

        }
    }
    else if(name == "Play Buffer"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue()==true){
            VS.bPlayAnyBuffer = true;
        } else {
            VS.bPlayAnyBuffer=false;
        }
    }
    else if(name == "Pause Buffer"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue()==true){
            VS.bPauseBuffer = true;
        } else {
            VS.bPauseBuffer=false;
        }
    }
    else if(name == "Buffer 0"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue()==true){
            VS.bPlayBuffer[0] = true;
        } else {
            VS.bPlayBuffer[0]=false;
        }
    }
    else if(name == "Buffer 1"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue()==true){
            VS.bPlayBuffer[1] = true;
        } else {
            VS.bPlayBuffer[1]=false;
        }
    }
    else if(name == "Buffer 2"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue()==true){
            VS.bPlayBuffer[2] = true;
        } else {
            VS.bPlayBuffer[2]=false;
        }
    }
    else if(name == "Buffer 3"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(toggle->getValue()==true){
            VS.bPlayBuffer[3] = true;
        } else {
            VS.bPlayBuffer[3]=false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
