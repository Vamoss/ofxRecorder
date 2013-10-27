/*
 *  ofxRecorder.h
 *  Vamoss
 *
 *  Created by Vamoss on 23/10/13.
 *  Copyright 2013 vamoss.com.br. No rights reserved.
 *
 *  Objective:
 *  Create a simple way to save events and reproduce then in the equivalent time that it happened
 *
 * Adapted from Patricio González
 * https://github.com/patriciogonzalezvivo/ofxSubtitles/
 *
 */
#pragma once

#include "ofMain.h"

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
	
	/// add text to be saved
	/// if time is NULL, it will receive ofGetElapsedTimeMillis
	void				add(string text, double time=NULL);
	
	/// get saved data in a period time
	/// if _in is NULL, it will receive ofGetElapsedTimeMillis
	///		you will get all data until now
	/// if _out is NULL, it will receive the _in value and _in will receive the last value used as _in
	///		it works when you want access data in order of time
	///		you will get the data since the last function call
	vector<recordItem>	getItems(double _in=NULL, double _out=NULL);

	double lastOutTime;
};