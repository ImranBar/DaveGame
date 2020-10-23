#include "Virus.h"

Virus::Virus(sf::Vector2f& pos) : DynamicObject(pos) {}

void Virus::setBullet()
{
	std::unique_ptr<Bullet> m_bulletV = std::make_unique<Bullet>(sf::Vector2f(10, 5));
	m_bulletV->setFirstPos(sf::Vector2f(Virus::getPosition()));
	m_bulletVirus.push_back(std::move(m_bulletV));
}


void Virus::drawBullet(sf::RenderWindow& window)
{
	
	for (auto& i : m_bulletVirus)
		i->draw(window);
}

std::vector<std::unique_ptr<Bullet>> & Virus::getBulletVirus()
{
	return m_bulletVirus;
}


bool Virus::setFireOnObject(sf::RenderWindow& window)
{
	if (getLife()) {
		m_objectShape.setTexture(*m_inFire);
		m_ObjectAnim.makeObjectsAnimation(0.5f,window, m_objectShape, OBJECT_SIZE - 8);
		return true;
	}
	return false;
}