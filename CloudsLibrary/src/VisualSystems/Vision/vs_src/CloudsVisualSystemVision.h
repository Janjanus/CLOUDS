//
//  emptyVisualSystem.h
//
//  Created by Patricio Gonzalez Vivo on 7/23/13.
//
//

#pragma once

#include "CloudsVisualSystem.h"
#include "ofxCv.h"
#include "MyTracker.h"

typedef enum{
    OpticalFlow =0,
    ContourTracking,
    HeatMap

}CVMode;

class CloudsVisualSystemVision : public CloudsVisualSystem {
public:
    
    string getSystemName();
    
    void selfSetup();
    void selfSetupGuis();
    
	void selfPresetLoaded(string presetPath);
	
    void selfAutoMode();
    void selfUpdate();
    void selfDrawBackground();
    void selfDrawDebug();
    void selfSceneTransformation();
    void selfDraw();
    void selfExit();
    void selfBegin();
	void selfEnd();
    ofRectangle window;
    void selfKeyPressed(ofKeyEventArgs & args);
    void selfKeyReleased(ofKeyEventArgs & args);
    
    void selfMouseDragged(ofMouseEventArgs& data);
    void selfMouseMoved(ofMouseEventArgs& data);
    void selfMousePressed(ofMouseEventArgs& data);
    void selfMouseReleased(ofMouseEventArgs& data);
    void resetFlowField();
    void selfSetupGui();
    void selfGuiEvent(ofxUIEventArgs &e);
    
    void selfSetupSystemGui();
    void guiSystemEvent(ofxUIEventArgs &e);
    void updateImagesForNewVideo();
    void updateOpticalFlowParameters();
    void updateHeatMap();
    void updateContourTracking();
    void selfSetupRenderGui();
    void guiRenderEvent(ofxUIEventArgs &e);
    void getTextures();

    ofxUISuperCanvas *opticalFlowGui;
    ofxUISuperCanvas *contourTrackingGui;
protected:

    //video player stuff        
    ofPtr<ofVideoPlayer> player;
    ofPixels resizeToPixels;
    int skipFrames;
//    ofVideoPlayer* player;
    int playerIndex;
    int movieIndex;
    bool frameIsNew;
    vector<string> movieStrings;

    CVMode currentMode;
    int scale;
    vector<ofRectangle> flowRegions;
    void populateOpticalFlowRegions();
    vector<ofVec2f> flowMotion;

    float colorRange;
    float contourLifetimeColorRange;
    ofImage accumulation;
    ofImage diff;

    ofImage previousHeatMap;
    ofImage flowImage;
    ofImage previousFlowImage;

    bool bContourTracking;
    bool bOpticalFlow;
    bool bDrawBoxes;
    bool bDrawLines;
    bool bLifeTime;
    bool bNumbers;
    bool bColor;
    
    //Contour tracking stuff
    ofxCv::ContourFinder contourFinder;
	ofxCv::RectTrackerFollower<MyTracker> tracker;
    void updateCVParameters();
    ofImage thresholded;
    ofxCv::RunningBackground background;
    cv::Rect accumRegion;
    //vector<ParkedCar> parked;

    //Optical flow types
    ofxCv::FlowFarneback farneback;
	ofxCv::FlowPyrLK pyrLk;
	ofxCv::Flow* curFlow;
    void updateOpticalFlow();
    void clearAccumulation();
    void drawFlowHeatMap(int x, int y);

    ofVboMesh flowMesh;
    float windowWidth;
    float windowHeight;
    
    bool drawPlayer;
    bool drawThresholded;
    bool drawDiff;
    bool flowFirstFrame;
    float videoAlpha;
    float thresholdAlpha;
    float diffAlpha;
    bool drawFlowWindow;


    ofVec2f averageFlow;
    int mouseX;
    int mouseY;
    

    
    void loadCurrentMovie();
    void loadMovieAtIndex(int movieIndex);
    
    void setMode(CVMode mode);
    int accumulationCount;
    cv::Scalar diffMean;
    
    //OPTICAL FLOW PARAMETERS
    float pyrScale;
    float levels;
    float winsize;
    float iterations;
    float polyN;
    float polySigma;
    bool useFarneback;
    float winSize;
    float maxLevel;
    float maxFeatures;
    float qualityLevel;
    float minDistance;
    float flowLineMultiplier;
    float windowAlpha;
    
    //CONTOUR PARAMETERS
    float cvPersistance;
    float cvMaxDistance;
    float cvMinAreaRadius;
    float cvMaxAreaRadius;
    float cvThresholdValue;
    bool cvUpdateParameters;
    float lineWidth;
    float flowColorMapRange;
    float flowLineWidth;
    float learningTime;
    float thresholdValue;
    
    
    
};