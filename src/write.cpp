#include "header.h"

void printAndWrite(std::vector<double> listT,std::vector<double> listX,std::vector<double> listY,std::vector<double> listVx,std::vector<double> listVy,std::vector<double> listAx,std::vector<double> listAy,double maxX,double maxY,std::string file){
	file+=".csv";

	std::ofstream writer(file);

	std::string head="t,x,y,vx,vy,ax,ay\n";
	writer<<head;
	std::cout<<head;

	for(int i=0;i<listT.size();i++){

		std::cout
			<<listT.at(i)
			<<","
			<<listX.at(i)
			<<","
			<<listX.at(i)
			<<","
			<<listY.at(i)
			<<","
			<<listVx.at(i)
			<<","
			<<listVy.at(i)
			<<","
			<<listAx.at(i)
			<<","
			<<listAy.at(i)
			<<std::endl;

		writer
			<<listT.at(i)
			<<","
			<<listX.at(i)
			<<","
			<<listX.at(i)
			<<","
			<<listY.at(i)
			<<","
			<<listVx.at(i)
			<<","
			<<listVy.at(i)
			<<","
			<<listAx.at(i)
			<<","
			<<listAy.at(i)
			<<"\n";
	}
	std::cout<<"maxX: "<<maxX<<"\nmaxY: "<<maxY<<std::endl;
}

