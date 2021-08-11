#!/usr/bin/env python
# coding: utf-8

# [sklearn.cluster.KMeans example]
# https://github.com/minsuk-heo/python_tutorial/blob/master/data_science/kmean/kmean.ipynb

# [K-Means Clustering Concept](https://eunsukimme.github.io/ml/2019/12/16/K-Means)


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from copy import deepcopy

import ImadDabbura.kmeans
from eunsukimme.kmeans import eunsukimme_kmeans

data_n = 20
data = np.random.randint(0, 100, size=(data_n, 2))
df = pd.DataFrame(data, columns=['x', 'y'])
data_x = df.values[:, 0]
data_y = df.values[:, 1]
centroids_n = 3
centroids = np.zeros(data_n)
means_x = np.zeros(centroids_n)
means_y = np.zeros(centroids_n)


def charting(cx, cy, c, init_x=None, init_y=None):
    if init_x is not None:
        if init_y is not None:
            print("     init_x:", init_x)
            print("     init_y:", init_y)
            plt.scatter(init_x, init_y, c="red")
    # print("  centroids:", centroids)
    print("    means_x:", cx)
    print("    means_y:", cy)
    plt.scatter(data_x, data_y, c=c)
    plt.scatter(cx, cy, c="blue")


# Reference using sklearn
def sklean_kmeans():
    kmeans = KMeans(n_clusters=centroids_n).fit(df.values)
    charting(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], kmeans.labels_)


sklean_kmeans()

# # Reference using  ImadDabbura.kmeans
# https://towardsdatascience.com/k-means-clustering-algorithm-applications-evaluation-methods-and-drawbacks-aa03e644b48a


def imad_dabbura_kmeans():
    km = ImadDabbura.kmeans.Kmeans(n_clusters=centroids_n)
    km.fit(df.values)
    charting(km.centroids[:, 0], km.centroids[:, 1], km.labels)


imad_dabbura_kmeans()


eunsukimme_kmeans(df.values, centroids_n)


# Implement
# STEP01: Place k random centroids
def randomize():
    cx = np.random.uniform(min(data_x), max(data_x), centroids_n)
    cy = np.random.uniform(min(data_y), max(data_y), centroids_n)
    return cx, cy


centroids_x, centroids_y = randomize()
plt.scatter(data_x, data_y, c="gray")
plt.scatter(centroids_x, centroids_y, c="red")


# STEP02: Assign datas to nearest centroids
def distance(x, y, u, v):
    return ((x - u) ** 2 + (y - v) ** 2) ** 0.5


def nearest():
    for d in range(data_n):
        distances = np.zeros(centroids_n)
        for c in range(centroids_n):
            distances[c] = distance(data_x[d], data_y[d], centroids_x[c], centroids_y[c])
        centroids[d] = np.argmin(distances)


nearest()
charting(centroids_x, centroids_y, centroids)


# STEP03: Update centroids

def update():
    counts = np.zeros(centroids_n)
    print("centroids:", centroids.shape, centroids)
    for i in range(data_n):
        c = int(centroids[i])
        means_x[c] = means_x[c] + data_x[i]
        means_y[c] = means_y[c] + data_y[i]
        counts[c] = counts[c] + 1

    for c in range(centroids_n):
        means_x[c] = means_x[c] / counts[c]
        means_y[c] = means_y[c] / counts[c]


update()
charting(centroids_x, centroids_y, centroids)


def cluster(repeat):
    count = 0
    cx, cy = randomize()
    init_x = deepcopy(cx)
    init_y = deepcopy(cy)
    for i in range(repeat):
        nearest()
        update()
        cx = deepcopy(means_x)
        cy = deepcopy(means_y)
        count = count + 1

    print("      count:", count)
    charting(cx, cy, centroids, init_x, init_y)


cluster(1)
cluster(1000)


sklean_kmeans()
imad_dabbura_kmeans()
