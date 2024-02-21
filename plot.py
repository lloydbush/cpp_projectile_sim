import sys
import matplotlib.pyplot as plt
import pandas as pd

###READ CSV###
fileName=sys.argv[1]+".csv" # get file name from command line arguments
data=pd.read_csv(fileName) # read .csv file

listX=data['x'].tolist() # put x values in list
listY=data['y'].tolist() # put y values in list

###PLOT###
# plot x and y values on graph
plt.plot(listX,listY,color='b',label="sim",linestyle='-')
plt.title("Projectile Flight Path")
plt.xlabel("x / m")
plt.ylabel("y / m")
plt.legend()
plt.grid(color='lightgrey')
plt.show()
