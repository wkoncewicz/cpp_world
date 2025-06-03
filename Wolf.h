#pragma once
#include "Animal.h"

using namespace std;

class Wolf : public Animal
{
	public:
		Wolf(Position position, World world);
		Wolf();

		void initParams();
};