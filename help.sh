function help(){
	echo $WORK_ENV 
	file=$WORK_ENV 
	echo ""
	echo "commands are the following:"
	sed  -ne "/#BEGIN$/,/#END$/ s/alias\s\(.*\)='\(.*\)'/\1\t ==>  \2/p"  < $file
	echo ""
	echo "environments are the following::"
	sed  -ne "/export/ s/export\s\+\(.*\)=\(.*\)/\1\t ==>  \2/p"  < $file
}
alias h=help
