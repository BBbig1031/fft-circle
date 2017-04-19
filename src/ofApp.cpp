#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    song.load("song.mp3");
    while (! song.isLoaded()); // spin wheels till loaded
    song.play();
    nBandsToGet = 512;  // up to 512
    
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
}

float *val;
//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    // update the sound playing system:
    // ofSoundUpdate();
    
    val = ofSoundGetSpectrum(nBandsToGet);  // get array of floats (1 for each band)
  
    
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        cout << ofToString(fftSmoothed[0]*20) << endl;
    }
    
     ofBackground(219,200-fftSmoothed[1]*60,fftSmoothed[0]*10);
}




//float getX (int deg, int radius) {
//    float x = radius * cos(ofDegToRad(deg)) + ofGetWidth()/2;
//    return (x);
//}
//
//float getY (int deg, int radius) {
//    float y = radius * sin(ofDegToRad(deg)) + ofGetHeight()/2;
//    return (y);
//}

//--------------------------------------------------------------
void ofApp::draw(){
    

    
    for (int i = 0; i < nBandsToGet; i++){
        //(we use negative height here, because we want to flip them
        //because the top corner is 0,0)
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
        ofRotateZ(i-80);
    
        ofSetColor(255);
        ofDrawCircle(0, 0, val[i]*100);
        
        ofNoFill();
        
 
        ofSetColor(143, 15, 108);
        ofDrawTriangle(0, 0, 100+(1*val[i])*500,val[i]*800,0,0);
        ofPopMatrix();
    }
    
    
//    int r = 100;  // radius
//    
//    // draw the fft results:
//
//    
//    // cos & sin take RADIANS.
//    // 2pi radians would be 2 x 57.2958 x 3.1416 = 360 degrees
//    // Therefore to draw a whole circle you would use 0-TWO_PI to draw a whole circle
//    
//    for (int i = 0;i < nBandsToGet; i++){
//        float x1 = getX(i, r);
//        float y1 = getY(i, r);
//        float x2 = getX(i, r + 2000 * val[i/8]);  // up to 2k larger (theoretically) but it will never get even close
//        float y2 = getY(i, r + 2000 * val[i/8]);
//        
//        ofDrawLine (x2, y2, x1, y1);  // we only care about bottom 8th of the spectrum
//        
//        ofSetColor(ofRandom(val[i/4],255),ofRandom(val[i/4],150),ofRandom(val[i/4],100));
//        
//          
//    }
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
