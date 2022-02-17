import numpy as np
import pandas as pd
from sklearn.cluster import KMeans

def sklean_kmeans(centeroids_n, df):
    kmeans = KMeans(n_clusters=centroids_n).fit(df.values)
    return kmeans.cluster_centers_, kmeans.labels_

centroids_n = 3
data_n = 20
data = np.random.randint(0, 100, size=(data_n, 2))
df = pd.DataFrame(data, columns=['x', 'y'])

centers, labels = sklean_kmeans(centroids_n, df)
for x, y in centers:
    print(x, y)

for label in labels:
    print(label)
