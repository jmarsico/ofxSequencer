#pragma once

#include "ofMain.h"
#include "ofxBpm.h"


class ofxSequencer
{
public:
    ~ofxSequencer();
    
    void setup(int rows, int cols, bool discrete=false, int beatsPerMinute=120, int beatsPerBar=4);
    void setSize(int rows, int cols);
    void setBpm(int beatsPerMinute, int beatsPerBar=4);
    void setDiscrete(bool discrete);
    void setRange(float minValue, float maxValue);
    
    void start();
    void advance();
    void stop();
    void reset();
    void randomize();
    
    void draw();
    
    void setPosition(int x, int y, int width, int height);
    void setVisible(bool visible);
    void toggleVisible();
    void setMouseActive(bool active);
    
    int getNumberRows() {return rows;}
    int getNumberColumns() {return cols;}

    void setValue(int row, int col, float val);
    
    int getColumn() {return column;}
    float getValue(int row, int col) {return value[col][row];}
    vector<float> getRow(int row);
    vector<float> getColumn(int col);
    
    ofEvent<vector<float> > sequencerEvent;
    
    
private:
    
    void play(void);
    void redraw();
    
    void mousePressed(ofMouseEventArgs &evt);
    void mouseDragged(ofMouseEventArgs &evt);
    void mouseReleased(ofMouseEventArgs &evt);
    
    vector<vector<float> > value;
    int column;
    ofxBpm bpm;
    bool discrete;
    float minValue, maxValue;

    int rows, cols;
    int x, y, width, height;
    float cellWidth, cellHeight;
    
    bool visible;
    ofPoint mousePos, activeCell;
    bool draggingCell;
    int draggingFrames;
    
    ofFbo fbo;
};