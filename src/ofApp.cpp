#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofSetVerticalSync(true);
	ofEnableAlphaBlending();
    ofSetFrameRate(60);

    VS.setup();

    //GUI
    gui = new ofxUICanvas();
    gui->addLabel("Video Sampler");
    gui->setFont("GUI/Fett.ttf");
    gui->addSpacer();

    /*gui->addSlider("Speed", -1.2, 1.8, &avgs.grainPlayer.speed);
    gui->addSlider("Pitch", 0.0, 10.0, &avgs.grainPlayer.pitch);
    gui->addSlider("GrainSize", 0.025, 0.45, &avgs.grainPlayer.grainSize);
    gui->addSlider("Overlaps", 1, 5, &avgs.grainPlayer.overlaps);
    gui->addSpacer();*/
    gui->addToggle("Record Input", true);
    //gui->addToggle("Set Position", &avgs.grainPlayer.bSetPosition);
    gui->addSlider("Position", 0.0, 1.0, 1.0);
 //   gui->addSlider("Loop Size", 0.0 ,1.0, 0.0);
    //gui->addSlider("Volume", 0.0, 1.0, &avgs.grainPlayer.volume);


    gui->autoSizeToFitWidgets();

    gui->loadSettings("GUI/guiSettings.xml");
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

    VS.update();
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

        VS.playModes.setDelay(slider->getScaledValue());
	}
   /* else if(name == "Loop Size")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		avgs.grainPlayer.loopSize = slider->getScaledValue();
	}*/
    else if(name == "Record Input"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
       // avgs.grainPlayer.bRecLiveInput = toggle->getValue();
        if(toggle->getValue()==true){
            VS.playModes.bRecord = true;
        } else {
            VS.playModes.bRecord = false;
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
