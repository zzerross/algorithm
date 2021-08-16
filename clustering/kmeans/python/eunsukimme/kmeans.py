# refer https://eunsukimme.github.io/ml/2019/12/16/K-Means

import numpy as np
import matplotlib.pyplot as plt
from copy import deepcopy

def distance(a, b):
    z = zip(a, b)
    l = list(z)
    return sum([(el_a - el_b)**2 for el_a, el_b in l]) ** 0.5

def eunsukimme_kmeans(samples, k):
    x = samples[:, 0]
    y = samples[:, 1]
    centroids_x = np.random.uniform(min(x), max(x), k)
    centroids_y = np.random.uniform(min(y), max(y), k)
    centroids = np.stack((centroids_x, centroids_y), axis=1)
    centroids_old = np.zeros(centroids.shape)
    labels = np.zeros(len(samples))
    sepal_length_width = np.array(list(zip(x, y)))
    error = np.zeros(k)

    for i in range(k):
        error[i] = distance(centroids_old[i], centroids[i])

    while (error.all() != 0):
        for i in range(len(samples)):
            distances = np.zeros(k)
            for j in range(k):
                distances[j] = distance(sepal_length_width[i], centroids[j])
            cluster = np.argmin(distances)
            labels[i] = cluster
        centroids_old = deepcopy(centroids)
        for i in range(k):
            points = [ sepal_length_width[j] for j in range(len(sepal_length_width)) if labels[j] == i ]
            centroids[i] = np.mean(points, axis=0)
        for i in range(k):
            error[i] = distance(centroids_old[i], centroids[i])

    colors = ['r', 'g', 'b']
    for i in range(k):
        points = np.array([sepal_length_width[j] for j in range(len(sepal_length_width)) if labels[j] == i])
        if 0 < len(points):
            plt.scatter(points[:, 0], points[:, 1], c=colors[i], alpha=0.5)

    plt.scatter(centroids[:, 0], centroids[:, 1], marker='D', s=150)
    plt.xlabel('sepal length (cm)')
    plt.ylabel('sepal width (cm)')
    plt.show()
    return centroids