#include "Batcher.h"

void KGLGE::Batcher::addToBatcher(Vertex pos)
{
	m_values[m_pointer] = pos.position.x;
	m_values[m_pointer + 1] = pos.position.y;
	m_values[m_pointer + 2] = pos.texPos.x;
	m_values[m_pointer + 3] = pos.texPos.y;
	m_pointer+=4;
}

void KGLGE::Batcher::addByCount(int count)
{
	m_pointer += count;
}

void KGLGE::Batcher::resetCount()
{
	m_pointer = 0;
}
