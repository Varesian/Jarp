/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINPROCESSOR_H_7FE1B233__
#define __PLUGINPROCESSOR_H_7FE1B233__

#include "../JuceLibraryCode/JuceHeader.h"
#include "../JuceLibraryCode/JucePluginCharacteristics.h"
#include <vector>
#include "Cell.h"
using std::vector;

//==============================================================================
/**
*/
class FirstVstAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    FirstVstAudioProcessor();
    ~FirstVstAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
	AudioPlayHead::CurrentPositionInfo lastPosInfo;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

	vector<vector<Cell> > getGrid();

	int getLastPlayheadCol() const;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FirstVstAudioProcessor);
	int speed;
	//int totalRows;
	//int totalCols;
	int lastPlayheadCol;
	double sampleRate;
	int noteToPlay;
	double maxPlayheadColPrecise; //only used if totalCols is set to 1. Needed to know when moves to next col

	//members related to MidiKeyboardState
	MidiKeyboardState keyboardState;
	MidiKeyboardComponent* keyboardComponent;
	MidiBuffer incomingMidi;
	MidiMessageCollector midiCollector;

	bool isNoteOn[127];
	bool notePlayedLastPlayheadCol[127];  //used to determine which notes to send MIDI offs to

	vector<vector<Cell> > grid;
	int getNumNotesOn();
	bool updateGrid;

	//methods
	bool bufferSpansNextBeat(AudioSampleBuffer& buffer, AudioPlayHead::CurrentPositionInfo currentPosInfo);
	int convertPpqToSamples(double ppq, AudioPlayHead::CurrentPositionInfo currentPosInfo);
	int getSamplesPerBeat();
	int getSamplesPerBeat(AudioPlayHead::CurrentPositionInfo currentPosInfo);
	bool updateNoteOns(MidiBuffer midiBuffer);//, bool noteOn[]);
	//bool updateNoteOns(MidiBuffer midiBuffer);
};

#endif  // __PLUGINPROCESSOR_H_7FE1B233__
