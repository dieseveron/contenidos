#!/bin/sh

while true; do
    clear
    echo "Hostname: $(hostname)\n"
    echo "/home directory contents:\n"
    ls -l /home
    echo "\nRunning process: $(ps -e | wc -l)"
    sleep 1
done

