#!/bin/bash

exec_path=`pwd`


cd /usr/bin/mc_command
exec ./makec $exec_path/$@

