#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"


//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofAppGlutWindow window;
    //ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
    ofSetOpenGLVersion(1,4);
    ofSetupOpenGL(&window, 1024, 768, OF_FULLSCREEN);
	ofRunApp(new ofApp());

}
