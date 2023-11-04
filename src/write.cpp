#include "header.h"

void printAndWrite(std::vector<double> listT,std::vector<double> listX,std::vector<double> listY,std::vector<double> listVx,std::vector<double> listVy,std::vector<double> listAx,std::vector<double> listAy,double maxX,double maxY){

	std::cout<<"t\tx\ty\tvx\tvy\tax\tay\n---\n";
	for(int i=0;i<listT.size();i++){

		std::cout
			<<listT.at(i)
			<<"\t\t"
			<<listX.at(i)
			<<"\t\t"
			<<listX.at(i)
			<<listY.at(i)
			<<"\t\t"
			<<listVx.at(i)
			<<"\t\t"
			<<listVy.at(i)
			<<"\t\t"
			<<listAx.at(i)
			<<"\t\t"
			<<listAy.at(i)
			<<std::endl;
	}
	std::cout<<"maxX: "<<maxX<<"\nmaxY: "<<maxY<<std::endl;
}

