#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "environment.h"
#include "projectile.h"

int setVar(char target,std::string var,std::string num){
	double numDbl=std::stod(num);
	
	if(target=='e'){
		switch(var){
			case "g":
				e.g=numDbl;
				break;
			case "rho":
				e.rho=numDbl;
				break;
			case "dt":
				e.dt=numDbl;
				break;
			default:
				std::cout << "ERROR: invalid var in function setVar\n";
		}
	}
	else if(target=='p'){
		switch(var){
			case "m":
				p.m=numDbl;
				break;
			case "cd":
				p.cd=numDbl;
				break;
			case "ar":
				p.ar=numDbl;
				break;
			case "v0x":
				p.v0x=numDbl;
				break;
			case "v0y":
				p.v0y=numDbl;
				break;
			default:
				std::cout << "ERROR: invalid var in function setVar\n";
		}
	}
	else{
		std::cout << "ERROR: invalid target option in function setVar\n";
		return 1;
	}

	return 0;
}

int read(){
	// READ env
	std::ifstream env("environment.cfg");

	// check for env
	if(!env){
		std::cout << "ERROR: can\'t open file \"environment.cfg\"\n";
		return 1;
	}

	std::string envStr;
	std::vector<std::string> envVec;

	// read file and push to vector
	while(getline(env,envStr)){
		std::cout << envStr << "\n";
		envVec.push_back(envStr);
	}

	// remove comments from .cfg file
	std::string text;

	for(int i=0;i<envVec.size();i++){ // for text in envVec
		text=envVec.at(i);

		// check for the '#' character as a comment delimiter
		for(int j=0;j<text.size();j++){ // for char in text
			if(text[j]=='#'){
				text.erase(j); // erase chars after and including comment delimeter
			}
		}

		// check for the '=' char and read number till ' ' character
		for(int j=0;j<text.size();j++){ // for char in text
			if(text[j]=='='){ // check for '=' char
				std::string var;

				// add chars from 0 to '=' to var
				for(int k=0;k<j;k++){
					var+=text[k];
				}

				std::string num;
				int k=1;

				// add chars from after '=' to ' ' or eol to num
				while(text[j+k]!=' ' && j+k<text.size()){
					num+=text[j+k];
					std::cout << j << " + " << k << " = " << num << "\n";
					k++;
				}

				setVar('e',var,num); // char target ('e' for env and 'p' for projectile)
						     // std::string var (variable name)
						     // std::string num (number value will be converted)

				// std::cout << j << ": " << var << " = " << num << "\n";
			}

		}

		envVec.at(i)=text; // replace old text (eith comment) with new text (without comment)
	}
	
	/*
	// print out new vector
	for(int i=0;i<envVec.size();i++){
		std::cout << envVec.at(i) << "\n";
	}
	*/

	// READ proj

	return 0;
}

int main(){
	int x=read();
	std::cout << x << "\n";
	return 0;
}

