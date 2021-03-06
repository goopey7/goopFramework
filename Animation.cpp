//Copyright Sam Collier 2022

#include "Animation.h"
#include <iostream>

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::addFrame(sf::IntRect frame)
{
	frames.push_back(frame);
}

size_t Animation::getNumFrames()
{
	return frames.size();
}

void Animation::animate(const float dt)
{
	if(bIsPlaying)
	{
		frameTimeElapsed += dt;
		if(frameTimeElapsed >= frameSpeed)
		{
			if(currentFrameIdx+1 >= frames.size())
			{
				if(bIsLooping)
					currentFrameIdx = 0;
				else
					bIsPlaying = false;
			}
			else currentFrameIdx++;
			frameTimeElapsed = 0;
		}
	}
}

sf::IntRect Animation::getCurrentFrame()
{
	sf::IntRect frame = frames[currentFrameIdx];
	if(!bIsFlipped)
		return frame;
	// if we are flipped then read right-to-left
	return sf::IntRect(frame.left + frame.width,frame.top,-frame.width,frame.height);
}

void Animation::setFlipped(bool flip)
{
	bIsFlipped = flip;
}

void Animation::setFrameSpeed(float frameSpeed)
{
	this->frameSpeed = frameSpeed;
}

void Animation::pause()
{
	bIsPlaying = false;
}

void Animation::play()
{
	bIsPlaying = true;
}

void Animation::setIsLooping(bool loop)
{
	bIsLooping = loop;
}

void Animation::setToInitialFrame()
{
	currentFrameIdx = 0;
}

