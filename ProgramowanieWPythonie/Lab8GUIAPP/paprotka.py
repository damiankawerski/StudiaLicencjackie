import matplotlib.pyplot as plt
import numpy as np

iterations = 100000
funcs = [
                (0.01, lambda x, y: (0, 0.16 * y)),
                (0.08, lambda x, y: (0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6)),
                (0.15, lambda x, y: (-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44)),
                (1.00, lambda x, y: (0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6))
        ]


def create_fractal():
    x = np.zeros(iterations + 1)
    y = np.zeros(iterations + 1)

    for i in range(iterations):
        rand = np.random.rand()
        for p, func in funcs:
            if rand < p:
                x[i + 1], y[i + 1] = func(x[i], y[i])
                break
    plt.figure(figsize=(4, 8))
    plt.scatter(x, y, s = 0.1, color = "green")
    plt.show()
                
    
create_fractal()
            