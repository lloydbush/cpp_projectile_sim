/*
 *
 * (c) Lloyd Bush 2024
 * This Project is distributed under the MIT-License.
 * A copy of the License should have been delivered with the Software.
 * If not it can be found at https://mit-license.org.
 *
 * projectile_sim is a simple projectile simulator, which is capable of calculating the trajectory
 * of a projectile through the air given starting parameters.
 * This being a personal project there is no guarantee for it's accuracy.
 *
 */

#include "header.h"
#include <math.h>

int main(int argc,char *argv[]){
	std::string file=argv[1]; // get filename from first command line argument

	logo(); // print logo

	projectile p; // make projectile
	environment e; // make environment
	readEnv(e); // read the "environment.cfg" file
	readProj(p); // read the "projectile.cfg" file

    // initialise all the variables
	double g=e.g, // gravitational acceleration
	       m=p.m, // projectile mass
	       rho=e.rho, // air density
	       cd=p.cd, // projectile coefficient of drag
	       ar=p.ar, // projectile cross sectional area
	       dt=e.dt, // timestep

	       v0x=p.v0x, // x velocity change
	       v0y=p.v0y, // y velocity change

	       x0=0.0, // x position change
	       y0=0.0, // y position change

	       t=0.0, // current time

	       x=x0, // current x position
	       y=y0, // current y position

	       vx=v0x,
	       vy=v0y,

	       ax=0.0, // current x acceleration
	       ay=0.0, // current y acceleration

	       fx=0.0, // current x force
	       fy=0.0, // current y force

	       fg=0.0, // current gravitational force

	       fdx=0.0, // current x drag force
	       fdy=0.0, // current y drag force

	       maxX=0.0, // current maximum x position (flight distance)
	       maxY=0.0; // current maximum y position (maximum height)

    // initialise all the lists
	std::vector<double> 
		listT, // time list

		listX, // x position list
		listY, // y position list

		listVx, // x velocity list
		listVy, // y velocity list

		listAx, // x acceleration list
		listAy; // y acceleration list

	// std::cout<<"hello world"<<std::endl;

    // MAIN LOOP
    // runs while projectile has not hit the ground
	while(y>=0.0){
        // pushes current variables to back of respective lists
		listT.push_back(t);
		listX.push_back(x);
		listY.push_back(y);
		listVx.push_back(vx);
		listVy.push_back(vy);
		listAx.push_back(ax);
		listAy.push_back(ay);

		t+=dt; // increment time by timestep

		v0x=vx;
		v0y=vy;

		x0=v0x*dt; // update x position change

        // check if new x will be higher than maxX
        // if so set maxX to new x
		if(x<(fabs(x+x0))){
			maxX=x+x0;
		}

		x+=x0; // increment x

		y0=v0y*dt; // update y position change

        // check if new y will be higher than maxY
        // if so set maxY to new y
		if(y<(fabs(y+y0))){
			maxY=y+y0;
		}

		y+=y0; // increment y

		fg=m*g; // update gravitational force (constant for this simulation)

        // check if going left or right
        // adjust x drag force accordingly
		if(vx>0.0){
			fdx=-0.5*rho*cd*vx*vx*ar;
		}
		else{
			fdx=0.5*rho*cd*vx*vx*ar;
		}

        // check if going up or down
        // adjust y drag force accordingly
		if(vy>0.0){
			fdy=-0.5*rho*cd*vy*vy*ar;
		}
		else{
			fdy=0.5*rho*cd*vy*vy*ar;
		}

		fx=fdx; // x force is drag force
		fy=fdy+fg; // y fore is drag force + gravitational force

		ax=fx/m; // update x acceleration
		ay=fy/m; // update y acceleration

		v0x=ax*dt; // update x velocity change
		v0y=ay*dt; // update y velocity change

		vx+=v0x; // update x velocity
		vy+=v0y; // update y velocity
	}

	printAndWrite(listT,listX,listY,listVx,listVy,listAx,listAy,maxX,maxY,file); // print and write the results

	logo(); // print logo

	return 0;
}

