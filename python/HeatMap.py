import numpy as np 
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd

#Get inputs
pathToCsv = sys.argv[1]
w = int(sys.argv[2])

width = w
count = 1
data = {}
path = pathToCsv
with open(path, 'r') as f:
    for lines in f:
        temp = lines.split(',')
        temp[-1] = temp[-1].strip()
        x = str(temp[0])
        if count != width+1:
            if x not in data:
                data[x] = [int(temp[2])]
                count = 0
            else:
                data[x].append(int(temp[2]))
            count=count+1
            
df = pd.DataFrame(data)
narray = df.to_numpy()

heat = plt.imshow(narray, cmap='Spectral', interpolation='nearest')
plt.colorbar(heat)
plt.xticks([])
plt.yticks([])
#plt.savefig('heatmap.eps', format='eps', dpi=1000)
plt.show()
