import matplotlib.pyplot as plt
import numpy as np

plt.figure(dpi=100)

x = np.array([1, 2, 3, 4, 5])
y = np.array([4, 5, 6, 7, 8])

plt.plot(x, y)


plt.title("Plot NumPy array")
plt.xlabel("x-axis")
plt.ylabel("y-label")
plt.show()
