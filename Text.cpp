//Copyright Sam Collier 2022

#include "Text.h"
#include <iostream>

Text::Text(sf::RenderWindow& window, sf::Vector2f pos, sf::Font& font,std::string text)
	: window(&window),font(font)
{
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setCharacterSize(5);
}

Text::Text(sf::RenderWindow& window,sf::Font& font)
	: window(&window), font(font)
{
	this->text.setFont(font);
	this->text.setCharacterSize(5);
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text,states);
}

void Text::setText(std::string text)
{
	this->text.setString(text);
}

void Text::anchorTo(Anchor anchor)
{
	this->anchor = anchor;
}

void Text::updatePosFromAnchor()
{
	sf::Vector2f tL,bL,tR,bR,c;
	switch(anchor)
	{
		case BottomLeft:
			{
				bL = window->mapPixelToCoords(sf::Vector2i(0,window->getSize().y));
				bL += sf::Vector2f(5.f,-5.f);
				text.setOrigin(0.f,text.getGlobalBounds().height);
				text.setPosition(bL);
			}
			break;
		case BottomRight:
			{
				bR = window->mapPixelToCoords(sf::Vector2i(window->getSize()));
				bR -= sf::Vector2f(5.f,5.f);
				text.setOrigin(text.getGlobalBounds().width,text.getGlobalBounds().height);
				text.setPosition(bR);
			}
			break;
		case TopLeft:
			{
				tL = window->mapPixelToCoords(sf::Vector2i(0,0));
				tL += sf::Vector2f(5.f,5.f);
				text.setOrigin(0.f,0.f);
				text.setPosition(tL);
			}
			break;
		case TopRight:
			{
				tR = window->mapPixelToCoords(sf::Vector2i(window->getSize().x,0));
				tR += sf::Vector2f(-5.f,5.f);
				text.setOrigin(text.getGlobalBounds().width,0.f);
				text.setPosition(tR);
			}
			break;
		case Center:
			{
				c = window->mapPixelToCoords(sf::Vector2i(window->getSize().x/2,window->getSize().y/2));
				text.setOrigin(text.getGlobalBounds().width/2.f,text.getGlobalBounds().height/2.f);
				text.setPosition(c);
			}
			break;
	}
}

void Text::setPosition(sf::Vector2f pos)
{
	text.setPosition(pos);
}

void Text::setFontSize(unsigned int size)
{
	text.setCharacterSize(size);
}

