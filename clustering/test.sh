#!/bin/bash

script="python kmeans/python/sklean/sklean_kmeans.py"
n=0

in="sample/samples/in${n}"
out="ouput/out${n}.sklean"
out_chart="ouput/out${n}.sklean.png"

set -e -x

cat ${in} | ${script} | tee ${out}
cat ${in} ${out} | python kmeans/python/chart.py ${out_chart}
