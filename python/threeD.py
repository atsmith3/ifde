import open3d as o3d
import sys
import numpy as np
import pandas as pd
import csv

#check how many arguments
if(len(sys.argv) == 5):
	print('Correct number of arguments')

'''
r = int(34)
g = int(200)
b = int(78)

rgb = (r << 16) | (g << 8) | b

print(str(rgb))

r_back = (rgb >> 16) & 0x0000ff;
g_back  = (rgb >> 8)  & 0x0000ff;
b_back  = (rgb)       & 0x0000ff;

print('\n')
print('\n')
print(str(r_back))
print('\n')
print(str(g_back))
print('\n')
print(str(b_back))
print('\n')
'''

#Get inputs
pathToCsv = sys.argv[1]
height = int(sys.argv[2])
width = int(sys.argv[3])
depths = int(sys.argv[4])

#Create a pcd file
pcdFilename = 'heyhey.pcd'

pcdFile = open(pcdFilename,'w') 
 
pcdFile.write('VERSION .7\nFIELDS x y z rgb\nSIZE 4 4 4 4\nTYPE I I I F\nCOUNT 1 1 1 1\n') 
pcdFile.write('WIDTH ' + str(width) + '\n')
pcdFile.write('HEIGHT ' + str(height) + '\n')
pcdFile.write('VIEWPOINT 0 0 0 1 0 0 0\n')
pcdFile.write('POINTS ' + str(width*height) + '\n')
pcdFile.write('DATA ascii\n') 

#print('hello')

with open(pathToCsv) as csvfile:
	readCSV = csv.reader(csvfile, delimiter=',')
	for row in readCSV:
		#read from csv
	
		x = int(row[0]); 
		y = int(row[1]);
		z = int(row[2]);

		r = int(row[3]);
		g = int(row[4]);
		b = int(row[5]);
		'''
		x = 53
		y= 42
		z = 245
		r = 82
		g = 3
		b = 0
		'''
		rgb = (r << 16) | (g << 8) | b

		#write to pcd file
		pcdFile.write(str(x) + ' ' + str(y) + ' ' + str(z) + ' ' + str(rgb) + '\n')

#Close pcd file
pcdFile.close()  

#visualize
pcd = o3d.io.read_point_cloud("ex.pcd")
#print(pcd)
#print(np.asarray(pcd.points))
o3d.visualization.draw_geometries([pcd])




