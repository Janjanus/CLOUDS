//
// CLOUDS Interactive Documentary
//
// VISUAL SYSTEMS
//
// Welcome to the Chromogram CloudsVisualSystem
//
//
//

#pragma once

#include "CloudsVisualSystem.h"

//TODO: rename this to your own visual system
class CloudsVisualSystemChromogram : public CloudsVisualSystem {
  public:
    
	//TODO: Change this to the name of your visual system
	//This determines your data path so name it at first!
	//ie getVisualSystemDataPath() uses this
    string getSystemName(){
		return "Chromogram";
	}

	//These methods let us add custom GUI parameters and respond to their events
    void selfSetupGui();
    void selfGuiEvent(ofxUIEventArgs &e);
    
	//Use system gui for global or logical settings, for exmpl
    void selfSetupSystemGui();
    void guiSystemEvent(ofxUIEventArgs &e);
    
	//use render gui for display settings, like changing colors
    void selfSetupRenderGui();
    void guiRenderEvent(ofxUIEventArgs &e);

	void selfSetDefaults();

	// selfSetup is called when the visual system is first instantiated
	// This will be called during a "loading" screen, so any big images or
	// geometry should be loaded here
    void selfSetup();

	// selfBegin is called when the system is ready to be shown
	// this is a good time to prepare for transitions
	// but try to keep it light weight as to not cause stuttering
    void selfBegin();

	// selfPresetLoaded is called whenever a new preset is triggered
	// it'll be called right before selfBegin() and you may wish to
	// refresh anything that a preset may offset, such as stored colors or particles
	void selfPresetLoaded(string presetPath);
    
	//do things like ofRotate/ofTranslate here
	//any type of transformation that doesn't have to do with the camera
    void selfSceneTransformation();
	
	//normal update call
	void selfUpdate();

	// selfDraw draws in 3D using the default ofEasyCamera
	// you can change the camera by returning getCameraRef()
    void selfDraw();
		
    // draw any debug stuff here
	void selfDrawDebug();

	// or you can use selfDrawBackground to do 2D drawings that don't use the 3D camera
	void selfDrawBackground();

	// this is called when your system is no longer drawing.
	// Right after this selfUpdate() and selfDraw() won't be called any more
	void selfEnd();

	// this is called when you should clear all the memory and delet anything you made in setup
    void selfExit();

	//events are called when the system is active
	//Feel free to make things interactive for you, and for the user!
    void selfKeyPressed(ofKeyEventArgs & args);
    void selfKeyReleased(ofKeyEventArgs & args);
    
    void selfMouseDragged(ofMouseEventArgs& data);
    void selfMouseMoved(ofMouseEventArgs& data);
    void selfMousePressed(ofMouseEventArgs& data);
    void selfMouseReleased(ofMouseEventArgs& data);
	
    // generate random colors    
    void generateRandomColors();

protected:
    
    //  Your Stuff
    //
	
	ofxUISuperCanvas* customGui;
	    
    int seed;
    int stepSize;
    int noiseHue;
    int noiseSaturation;
    int noiseBrightness;
    
    int n;
    
    bool filled;
    bool drawn;
    
	vector <ofColor> randomColors;
    ofMesh chromogram;
    int numRandomColors;
    ofColor color1;
    ofColor color2;
    ofColor color3;
    float newHue;
    int sporadicColorChanger;
    int sporadicSaturationChanger;
    int sporadicBrightnessChanger;
    
    float xpos;
    float ypos;
    float yoffset;
    
    float t; //time
    
    
    ////////// Slider Paramters
    
    float rectHeight;
    float rectWidth;
    
    float HueMin;
    float HueMax;
    float hRangeMin;
    float hRangeMax;
    
    float SatMin;
    float SatMax;
    float sRangeMin;
    float sRangeMax;
    
    float BrightMin;
    float BrightMax;
    float bRangeMin;
    float bRangeMax;
    
    float HueNoiseStep;
    float SatNoiseStep;
    float BrightNoiseStep;
    
    float hNoiseSpeed;
    float sNoiseSpeed;
    float bNoiseSpeed;

    
    float HueStochasticity;
    float SatStochasticity;
    float BrightnessStochasticity;
    
    //
    bool oscillateColor;
    bool stochasticity; 
    int oscillationPeriod;
    
    
};
