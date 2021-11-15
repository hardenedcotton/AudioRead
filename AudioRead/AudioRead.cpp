#include <iostream>
#include <AudioFile.h>

using namespace std;

AudioFile<double> audioFile;
AudioFile<double> altAudio;

float volume = 1.3;
float speed = 5 / 4.0;
int sample;

int main()
{
    //get main file
    audioFile.load("C:/Users/HardenedCotton/source/repos/AudioRead/Sounds/bruh.wav");
    audioFile.summary();													//test
	sample = audioFile.getNumSamplesPerChannel();
	altAudio.setBitDepth(8);
	
	//create buffer
	AudioFile<double>::AudioBuffer buffer;
	buffer.resize(1);
	buffer[0].resize(sample);
	int sizeBuffer = buffer.size();
	
	cout << volume << endl << speed << endl;								//test

	//copy samples to buffer
	for (int i = 0; i < sample; i++)
	{
			buffer[0][i] = audioFile.samples[0][i] * volume;
	}

	//write buffer
	bool ok = altAudio.setAudioBuffer(buffer);

	//pitchshift
	altAudio.setSampleRate((audioFile.getSampleRate() * speed));
	altAudio.summary();														//test

	altAudio.save("C:/Users/HardenedCotton/source/repos/AudioRead/Sounds/altAudio.wav");  
}