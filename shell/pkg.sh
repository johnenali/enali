#!/bin/bash
#The script is to apt-get install needed packages for me.
. func.sh
if [ $LOGNAME != "root" ];then
	echo "You need to be root to run this script" >&2
	exit 1
fi
PKGS="guake vim python3 curl zim"
for pkgs in $PKGS
do
    pkgme $pkgs
done
#For Ruby/Rails/RVM install
if ! which curl >/dev/null 2>&1 ; then
	apt-get install curl
fi
