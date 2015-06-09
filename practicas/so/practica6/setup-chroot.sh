#!/bin/sh

CHROOT=/home/chroot/sid

mount --bind /dev/ $CHROOT/dev/
mount --bind /proc/ $CHROOT/proc/
mount --bind /sys/ $CHROOT/sys/
