
from numpy import *
import matplotlib.pyplot as plt

f1 = loadtxt ("exercise_data.txt", skiprows=0, delimiter=",")

plt.plot(arange(f1.shape[0]), f1[:,0])
plt.show() 
