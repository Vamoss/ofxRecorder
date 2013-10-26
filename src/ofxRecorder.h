/*
 *  ofxRecorder.h
 *  Vamoss
 *
 *  Created by Vamoss on 23/10/13.
 *  Copyright 2013 vamoss.com.br. No rights reserved.
 *
 * Adapted from Patricio González
 * https://github.com/patriciogonzalezvivo/ofxSubtitles/
 *
 */
#pragma once

#include "ofMain.h"

#include <iomanip>
#include <strstream>

#include <iostream>
#include <fstream>
#include <vector>

typedef struct {
	double	time;
	string	text;
} recordItem;

class ofxRecorder{
public:
	vector<recordItem>	itens;

	ofxRecorder();
        
	void				load(string filePath);
	void				save(string filePath);
	
	void				add(string text, double time=NULL);
	vector<recordItem>	getItems(double _in=NULL, double _out=NULL);

	double lastOutTime;
};