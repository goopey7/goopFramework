//Copyright Sam Collier 2022

#include "Actor.h"

Actor::Actor(Player& sounds, const TextureHolder& textures, World* currentWorld)
	: sfx(sounds),textures(textures), currentWorld(currentWorld)
{
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Red);
	box.setPosition(getPosition());
	box.setOutlineThickness(1.f);
}

Actor::~Actor()
{
}

void Actor::updateCurrent(const float dt)
{
}

void Actor::fixedUpdateCurrent(const float dt)
{
	move(velocity*dt);
	rotate(rotationSpeed*dt);
}

void Actor::drawCurrent(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(sprite,states);
	if(bDebugMode)
		target.draw(box,states);
}

unsigned int Actor::getCategory() const
{
	return category;
}

sf::FloatRect Actor::getCollisionBox() const
{
	return collisionBox;
}

void Actor::setCollisionBox(sf::FloatRect box)
{
	this->collisionBox = box;
	this->box.setPosition(box.left,box.top);
	this->box.setSize(sf::Vector2f(box.width,box.height));
}

void Actor::toggleDebugMode()
{
	bDebugMode = !bDebugMode;
}

void Actor::setTextureRect(sf::IntRect textureRect)
{
	sprite.setTextureRect(textureRect);
}

void Actor::setTexture(unsigned int texture)
{
	sprite.setTexture(textures.get(texture));
}

void Actor::scale(sf::Vector2f scaleFactor)
{
	sprite.setScale(scaleFactor);
	updateBox();
}

void Actor::scale(float scaleX, float scaleY)
{
	sprite.setScale(scaleX,scaleY);
	updateBox();
}

void Actor::updateBox()
{
	collisionBox.width *= sprite.getScale().x;
	collisionBox.height *= sprite.getScale().y;
	box.setSize(sf::Vector2f(collisionBox.width,collisionBox.height));
}

sf::Vector2u Actor::getTextureSize()
{
	sf::IntRect r = sprite.getTextureRect();
	return sf::Vector2u(r.width,r.height);
}

sf::Vector2f Actor::getCollisionBoxSize() const
{
	return sf::Vector2f(collisionBox.width,collisionBox.height);
}

sf::Vector2f Actor::getCollisionBoxPos() const
{
	return sf::Vector2f(collisionBox.left,collisionBox.top);
}

sf::Vector2f Actor::getVelocity() const
{
	return velocity;
}

void Actor::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

bool Actor::isDynamic() const
{
	return bIsDynamic;
}

void Actor::setIsDynamic(bool isDynamic)
{
	bIsDynamic = isDynamic;
}

bool Actor::collisionEnabled()
{
	return bCollisionEnabled;
}

void Actor::enableCollision(bool shouldCollide)
{
	bCollisionEnabled = shouldCollide;
}

void Actor::onCollisionEnter(Actor* other, sf::Vector2f& contactPoint, sf::Vector2f& contactNormal, float& hitTime, const float dt)
{
}

World* Actor::getWorld()
{
	return currentWorld;
}

const TextureHolder& Actor::getTextures() const
{
	return textures;
}

void Actor::applyDamage(float damage)
{
	health -= damage;
}

float Actor::getDamage() const
{
	return damage;
}

void Actor::onDynamicVsDynamicEnter(Actor* other)
{
}

void Actor::setCategory(unsigned int category)
{
	this->category = category;
}

Player& Actor::getSfx()
{
	return sfx;
}

float Actor::getHealth() const
{
	return health;
}

