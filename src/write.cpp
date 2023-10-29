#include "header.h"

void printAndWrite(std::vector<double> listT,std::vector<double> listX,std::vector<double> listY,std::vector<double> listVx,std::vector<double> listVy,std::vector<double> listAx,std::vector<double> listAy){

	std::cout<<"t\tx\ty\tvx\tvy\tax\tay\n---\n";
	for(int i=0;i<=listT.size();i++){

		std::cout
			<<listT.at(i)
			<<"\t"
			<<listX.at(i)
			<<"\t"
			<<listY.at(i)
			<<"\t"
			<<listVx.at(i)
			<<"\t"
			<<listVy.at(i)
			<<"\t"
			<<listAx.at(i)
			<<"\t"
			<<listAy.at(i)
			<<std::endl;
	}
}

