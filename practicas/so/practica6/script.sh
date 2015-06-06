#!/bin/sh

while true; do
    clear
    echo "Hostname: $(hostname)\n"
    echo "/home directory contents:\n"
    ls -l /home
    echo "\nSome processes:\n$(ps -e | tail)"
    echo "\nProcess quantity:\n$(ps -e | wc -l)"
    sleep 1
done

