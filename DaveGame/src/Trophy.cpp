#include "Trophy.h"
#include "GameFactoryPattern.h"


Trophy::Trophy(sf::Vector2f& pos) : CatchAbleObject(pos){m_objectTexture = LoadFromFile::getInstance().getTexture(o_trophy);
	setTrophy();
}

void Trophy::setTrophy()
{
	m_cell.setTexture(*m_objectTexture);
	m_cell.setOrigin(sf::Vector2f{ 50 / 2, 50 / 2 });
	m_cell.move(50 / 2, 50 / 2);
}


static bool m_instance = GameFactoryPattern<CatchAbleObject>::registerit(Textures::T_trophy,
	[](sf::Vector2f& place) -> std::unique_ptr<CatchAbleObject> { return std::make_unique<Trophy>(place); });
