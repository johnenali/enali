#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
export PATH
#For .bashrc alias

#For .vimrc
cp vimrc.me ~/.vimrc
if ! which git >/dev/null 2>&1 ; then
	echo "You need install git first.Install(y/n)"
	read ANS
	if [ $ANS = "Y" -o $ANS = "y" ];then
		sudo apt-get install git
	else
		exit 1
	fi
fi
git clone http://github.com/gmarik/vundle.git ~/.vim/bundle/vundle
if ! which vim >/dev/null 2>&1 ; then
	echo "You need install vim first.Install(y/n)"
	read ANS
	if [ $ANS = "Y" -o $ANS = "y" ];then
		sudo apt-get install vim 
	else 
		exit 1
	fi
fi
vim +BundleInstall +qall
#For user's facepng
cp face.png ~/.face

	
