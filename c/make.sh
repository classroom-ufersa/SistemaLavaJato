#!/bin/bash

cd src/

rm -f main

rm -f ../bin/main

make main

mv main ../bin
