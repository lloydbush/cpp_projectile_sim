#include <iostream>

#include "projectile.h"
#include "header.h"

int main(){
	proj p;
	std::cout << p.m << "\n";
	p.m=2.0;
	change(p);
	std::cout << p.m << "\n";
	return 0;
}
