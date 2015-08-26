#! /bin/bash
#
# scrip.sh
# Copyright (C) 2015 Vilchis Dominguez Miguel Alonso <mvilchis@ciencias.unam.mx>
#
# Distributed under terms of the MIT license.
#
python InsertionSort.py 1 50
python MergerSort.py 1 50
java MergerSort 1 50
java InsertionSort 1 50
./InsertionSortC 1 50
./MergerSortC 1 50 


