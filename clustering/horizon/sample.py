import sys
from random import seed
from random import random

args = len(sys.argv)
if args < 2:
    sys.exit("Usage: " + sys.argv[0] + " [clusters] [axies...]")

clusters = int(sys.argv[1])
print(clusters)

axises = args - 2
samples = int(sys.argv[2]) if 0 < axises else 0

for i in range(samples):
    for axis in range(axises):
        print(random(), end=" ")
    print()
