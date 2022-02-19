import numpy as np
import pandas as pd
from sklearn.cluster import KMeans

def kmeans(centeroids_n, df):
    kmeans = KMeans(n_clusters=centers_n).fit(df.values)
    return kmeans.cluster_centers_, kmeans.labels_

centers_n = int(input())
data_n = int(input())

data = []
for i in range(0, data_n):
    data.append(float(input()))

df = pd.DataFrame(data, columns=['x'])

centers, labels = kmeans(centers_n, df)
for x in centers:
    print(x[0])

for label in labels:
    print(label)
