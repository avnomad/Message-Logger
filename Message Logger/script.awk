BEGIN {
}

{
	print "\tcase " $2 ":"
	print "\t\tcout << escape(" $2 ") << endl;"
	print "\t\tbreak;"
}

END {
}
