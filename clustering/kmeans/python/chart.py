import sys
import matplotlib.pyplot as plt
import plotly.express as px

def chart(c, d, l, o):
    plt.scatter(c, c, c="blue", marker="+", alpha=0.5, s=100.0)
    plt.scatter(d, d, c=l, marker="o", alpha=0.5, s=10.0)
    plt.savefig(o)

centers_n = int(input())
data_n = int(input())

data = []
for i in range(0, data_n):
    data.append(float(input()))

centers = []
for i in range(0, centers_n):
    centers.append(float(input()))

labels = []
for i in range(0, data_n):
    labels.append(int(input()))

out = sys.argv[1]
chart(centers, data, labels, out)
