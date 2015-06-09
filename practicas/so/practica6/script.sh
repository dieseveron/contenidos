#!/bin/bash

while true; do
    clear
    echo -e "Hostname: $(hostname)\n"
    echo -e "Current date: $(date)\n"
    echo -e "/home directory contents:\n"
    ls -l /home
    echo -e "\nSome processes:\n$(ps -e | tail)"
    echo -e "\nProcess quantity:\n$(ps -e | wc -l)"
    sleep 10
done

