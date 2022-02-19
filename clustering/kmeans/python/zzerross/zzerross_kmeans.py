def distance(i, j):
    return abs(i - j)

def init(n, d):
    c = [0] * n
    for i in range(n):
        c[i] = d[i]
    return c

def nearest(c, d):
    n = len(d)
    l = [0] * n
    for i in range(n):
        t = [distance(d[i], c[j]) for j in range(len(c))]
        l[i] = t.index(min(t))
    return l

def kmeans(n, d):
    c = init(n, d)
    l = None
    for i in range(1):
        l = nearest(c, d)

    return c, l

centers_n = int(input())
data_n = int(input())

data = []
for i in range(0, data_n):
    data.append(float(input()))

centers, labels = kmeans(centers_n, data)
for x in centers:
    print(x)

for label in labels:
    print(label)
