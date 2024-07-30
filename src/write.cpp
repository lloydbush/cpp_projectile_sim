#include "header.h"

void write(
        double t,
        double x,
        double y,
        double vx,
        double vy,
        double ax,
        double ay,
        double maxX,
        double maxY,
        std::string file){

    static size_t loop=0;

	file+=".csv"; // make .csv file from file

    if(loop==0){
        std::ofstream writer(file);
        writer<<"t,x,y,vx,vy,ax,ay\n";
    }

	std::ofstream writer(file, std::ios::app); // create writer object

    writer
        <<t
        <<","
        <<x
        <<","
        <<y
        <<","
        <<vx
        <<","
        <<vy
        <<","
        <<ax
        <<","
        <<ay
        <<"\n";

    /*
    std::cout<<"t="<<t<<"\nmaxX="<<maxX<<"\nmaxY="<<maxY<<"\n-----"<<std::endl;

    if(loop%100==0){
        std::cout<<std::endl;
    }
    */

    writer.close();

    loop++;
}

/*
void printAndWrite(std::vector<double> listT,
        std::vector<double> listX,
        std::vector<double> listY,
        std::vector<double> listVx,
        std::vector<double> listVy,
        std::vector<double> listAx,
        std::vector<double> listAy,

        double maxX,
        double maxY,
        std::string file){

	file+=".csv"; // make .csv file from file

	std::ofstream writer(file); // create writer object

	std::string head="t,x,y,vx,vy,ax,ay\n"; // define head
	writer<<head; // write head to file
	std::cout<<head; // print head

    // write and print each time and corresponding variables
	for(size_t i=0;i<listT.size();i++){

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

	std::cout<<"maxX: "<<maxX<<"\nmaxY: "<<maxY<<std::endl; // print maximum x and y values (flight distance and apoapsis)
}
*/

