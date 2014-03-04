#!/bin/bash
#Just for buaaer's linuxlover to set ubuntu sourcelist.
if [ $# -lt 2 ]; then
	echo "Usage:  `basename $0` distributions version"
	echo -e "\tdistributions e.g.(ubuntu)"
	echo -e "\tversion e.g.(12.04/12.10/13.04/13.10)"
	exit 1
fi
if [ $# -eq 0 ]; then
	DIST=`lsb_release -i | awk -F ':' '{print $2}'`
	VERS=`lsb_release -c | awk -F ':' '{print $2}'`
fi
DIST=$1
VERNUM=$2
if [ $DIST == "ubuntu" ];then
	case $VERNUM in
		12.04) VERS=precise
			;;
		12.10) VERS=quantal
			;;
		13.04) VERS=raring
			;;
	#	13.10) VERS=
	esac

	SRCFILE=/etc/apt/sources.list
	mv $SRCFILE ${SRCFILE}.bk
	echo "deb http://mirror.buaa.edu.cn/ubuntu/ $VERS main multiverse restricted universe
deb http://mirror.buaa.edu.cn/ubuntu/ $VERS-backports main multiverse restricted universe
deb http://mirror.buaa.edu.cn/ubuntu/ $VERS-proposed main multiverse restricted universe
deb http://mirror.buaa.edu.cn/ubuntu/ $VERS-security main multiverse restricted universe
deb http://mirror.buaa.edu.cn/ubuntu/ $VERS-updates main multiverse restricted universe
deb-src http://mirror.buaa.edu.cn/ubuntu/ $VERS main multiverse restricted universe
deb-src http://mirror.buaa.edu.cn/ubuntu/ $VERS-backports main multiverse restricted universe
deb-src http://mirror.buaa.edu.cn/ubuntu/ $VERS-proposed main multiverse restricted universe
deb-src http://mirror.buaa.edu.cn/ubuntu/ $VERS-security main multiverse restricted universe
deb-src http://mirror.buaa.edu.cn/ubuntu/ $VERS-updates main multiverse restricted universe" > $SRCFILE
	if [ -f ${SRCFILE}.bk ];then
		echo "Configuration! Your $DIST's sourcelist have be update to buaa"
	fi
fi
