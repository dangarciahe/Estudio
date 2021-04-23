import matplotlib.pyplot as plt
import numpy as np
import sys 

N, t = np.loadtxt(sys.argv[1], unpack=True)

t1=t/t[0];

plt.plot(N,t1,'-o')
plt.title('Solución del Sistema')
plt.xlabel('N')
plt.ylabel('t [s]')
plt.yscale('log')
plt.xscale('log')
plt.savefig('System')
plt.grid()
plt.legend()
plt.show()
