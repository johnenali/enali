#!/bin/bash
#For git config
case $# in
	0)
		echo "Enter your editor:"
		read UEDITOR
		echo "Enter your name:"
		read UNAME
		echo "Enter your email:"
		read UEMAIL
		echo "Enter color choice: true/false"
		read UCOLOR
		echo "Enter cache time (seconds):"
		read UTIME
		;;
	1)
		if [ $1 = "me" ];then
			UEDITOR="vim"
			UNAME=$LOGNAME
			UEMAIL=dreamrider2011@gmail.com
			UCOLOR="true"
			UTIME=3000
		elif [ $1 = "-h" -o $1 = "--help" ];then
			echo "Usage: "
			echo -e "\t`basename $0` "
			echo -e "\t`basename $0` me"
			echo -e "\t`basename $0` editor name email colortype(true/false) cachetime(seconds)"
			exit 1
		else :
		fi
		;;
	5)
		UEDITOR=$1
		UNAME=$2
		UEMAIL=$3
		UCOLOR=$4
		UTIME=$5
		;;
	*)
		echo "Usage Error!Usage: "
		echo -e "\t`basename $0` "
		echo -e "\t`basename $0` me"
		echo -e "\t`basename $0` editor name email color cachetime"
		exit 1
		;;
esac
if ! which $UEDITOR >/dev/null 2>&1 ; then
	echo "Your editor isn't installed. Install now?(y/n)"
	read ANS
	if [ $ANS = "y" -o $ANS = "Y" ]; then
		sudo apt-get -y install $UEDITOR
	fi
fi
emailReg='^(\w)+(\.\w+)*@(\w)+((\.\w{2,3}){1,3})$'
if ! echo $UEMAIL | egrep $emailReg >/dev/null 2>&1 ; then
	echo "Wrong email."
	exit 1
fi
case $UCOLOR in
	true|True|TRUE);;
	false|False|FALSE);;
	*) echo "Wrong color type.Just support 'true/false'"
	exit 1
	;;
esac
git config --global core.editor "$UEDITOR"
git config --global user.name "$UNAME"
git config --global user.email "$UEMAIL"
git config --global color.ui $UCOLOR
git config --global credential.helper cache
git config --global credential.helper "cache --timeout=$UTIME"
