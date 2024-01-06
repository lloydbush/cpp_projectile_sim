import sys
import matplotlib.pyplot as plt
import pandas as pd

###READ CSV###
fileName=sys.argv[1]+".csv"
data=pd.read_csv(fileName)

listX=data['x'].tolist()
listY=data['y'].tolist()

###PLOT###

plt.plot(listX,listY,color='b',label="sim",linestyle='-')
plt.title("Projectile Flight Path")
plt.xlabel("x / m")
plt.ylabel("y / m")
plt.legend()
plt.grid(color='lightgrey')
plt.show()
