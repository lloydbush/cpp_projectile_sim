#include "header.h"
#include "environment.h"
#include "projectile.h"

int setVar(char target,std::string var,std::string num){
	double numDbl=std::stod(num); // convert string num to double numDbl
	std::cout << "setVar(" << target << "," << var << "," << num << ")\n";
	
	if(target=='e'){
		if(var=="g"){e.g=numDbl;}
		else if(var=="rho"){e.rho=numDbl;}
		else if(var=="dt"){e.dt=numDbl;}
		else{std::cout << "ERROR: invalid var in function setVar\n"; return 1;}
	}
	else if(target=='p'){
		if(var=="m"){p.m=numDbl;}
		else if(var=="cd"){p.cd=numDbl;}
		else if(var=="ar"){p.ar=numDbl;}
		else if(var=="v0x"){p.v0x=numDbl;}
		else if(var=="v0y"){p.v0y=numDbl;}
		else{std::cout << "ERROR: invalid var in function setVar\n"; return 1;}
	}
	else{
		std::cout << "ERROR: invalid target option in function setVar\n";
		return 1;
	}

	return 0;
}

// READ ENVIRONMENT
int readEnv(){
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
		// std::cout << envStr << "\n";
		envVec.push_back(envStr);
	}

	env.close(); // close file "environment.cfg"

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
					// std::cout << j << " + " << k << " = " << num << "\n";
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

	return 0;
}

// READ PROJECTILE
int readProj(){
	std::ifstream proj("projectile.cfg");

	// check for proj
	if(!proj){
		std::cout << "ERROR: can\'t open file \"projectile.cfg\"\n";
		return 1;
	}

	std::string projStr;
	std::vector<std::string> projVec;

	// read file and push to vector
	while(getline(proj,projStr)){
		// std::cout << projStr << "\n";
		projVec.push_back(projStr);
	}

	proj.close(); // close file "projectile.cfg"

	// remove comments from .cfg file
	std::string text;

	for(int i=0;i<projVec.size();i++){ // for text in projVec
		text=projVec.at(i);

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
					// std::cout << j << " + " << k << " = " << num << "\n";
					k++;
				}

				setVar('p',var,num); // char target ('e' for env and 'p' for projectile)
						     // std::string var (variable name)
						     // std::string num (number value will be converted)

				// std::cout << j << ": " << var << " = " << num << "\n";
			}

		}

		projVec.at(i)=text; // replace old text (eith comment) with new text (without comment)
	}
	
	/*
	// print out new vector
	for(int i=0;i<projVec.size();i++){
		std::cout << projVec.at(i) << "\n";
	}
	*/

	return 0;
}

/*
int main(){
	readEnv();
	readProj();

	std::cout
		<< "g=\t" << e.g << "\n"
		<< "rho=\t" << e.rho << "\n"
		<< "dt=\t" << e.dt << "\n"

		<< "m=\t" << p.m << "\n"
		<< "cd=\t" << p.cd << "\n"
		<< "ar=\t" << p.ar << "\n"
		<< "v0x=\t" << p.v0x << "\n"
		<< "v0y=\t" << p.v0y << "\n";

	return 0;
}
*/

