
//-----------------------------------------------------------
// Huovilainen New Moog (HNM) model as per CMJ jun 2006
// Implemented as Teensy Audio Library compatible object
// Richard van Hoesel, Feb. 9 2021
// v.1.01 now includes FC "CV" modulation input
// please retain this header if you use this code.
//-----------------------------------------------------------

// https://forum.pjrc.com/threads/60488?p=269609&viewfull=1#post269609

#ifndef filter_ladder_h_
#define filter_ladder_h_

#include "Arduino.h"
#include "AudioStream.h"

class HNMoog : public AudioStream
{
public:
	HNMoog() : AudioStream(2,inputQueueArray) {};
	void SetCutoff(float FC);
	void SetResonance(float reson);
	float LPF(float s, int i);
	void compute_coeffs(float fc);
	virtual void update(void);
private:
	float alpha = 1.0;
	float beta[4] = {0};
	float z0[4] = {0};
	float z1[4] = {0};
	float K;
	float Fbase = 1000;
	float overdrive = 1.0;
	audio_block_t *inputQueueArray[2];
};

#endif