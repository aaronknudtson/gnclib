import numpy as np
import matplotlib.pyplot as plt
import sys

sys.path.insert(0, "./build/src/main/pygnc")
import pygnc


x0 = np.array([0.0, -0.1, 1.2, 1.1, 0.1, 0.2])
x0 = x0 * 6378.245
x0[3:] = x0[3:] / (13.45 * 60)
h, t0, t_max = 100.0, 0.0, 1000000.0
t = np.linspace(t0, t_max, int((t_max - t0) / h))

x = pygnc.twobody_sim(x0, h, t0, t_max)
fig, ax = plt.subplots()

ax.plot(t, x[0, :], label="x")
ax.plot(t, x[1, :], label="y")
ax.set(xlabel="time (s)", ylabel="distance (km)", title="Orbit Sim")
ax.legend()
ax.grid()

plt.show()
