#!/bin/bash

# m=sklean
m=zzerross
script="python kmeans/python/${m}/${m}_kmeans.py"
n=0

in="sample/samples/in${n}"
out="ouput/out${n}.${m}"
out_chart="ouput/out${n}.${m}.png"

set -e -x

cat ${in} | ${script} | tee ${out}
cat ${in} ${out} | python kmeans/python/chart.py ${out_chart}
