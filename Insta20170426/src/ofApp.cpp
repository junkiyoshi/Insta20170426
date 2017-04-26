#include "ofApp.h"

ofApp::~ofApp() {
	for (ofxBulletBox* tmp : this->boxes) { delete tmp;	}
	this->boxes.clear();
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofEnableDepthTest();
	ofBackground(0);
	ofSetWindowTitle("box shot!");

	this->world.setup();
	this->world.setGravity(ofVec3f(0.0, -64.0, 0));

	this->ground.create(this->world.world, ofVec3f(0.0, 0.0, 0.0), 0.0, 350.0, 350.0, 15.0);
	this->ground.setProperties(0.8, 0.5);
	this->ground.add();
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetKeyPressed()) {
		ofxBulletBox* box = new ofxBulletBox();
		float size = ofRandom(10.0, 20.0);
		box->create(this->world.world, this->cam.getPosition() * ofRandom(0.8, 0.9), 1.0, size, size, size);
		box->setRestitution(1.0);
		box->applyCentralForce(this->cam.getPosition() * -100);
		box->add();

		this->boxes.push_back(box);

		ofColor color;
		color.setHsb(ofRandom(255), 255, 255);
		this->box_colors.push_back(color);
	}

	this->world.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	for (int i = 0; i < this->boxes.size(); i++) {
		ofSetColor(this->box_colors[i]);
		this->boxes[i]->draw();
	}

	ofSetColor(128);
	this->ground.draw();

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}