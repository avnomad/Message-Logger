#	Copyright (C) 2010-2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
#
#	This file is part of Message Logger.
#
#	Message Logger is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	Message Logger is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with Message Logger.  If not, see <http://www.gnu.org/licenses/>.

BEGIN {
}

{
	if($0 ~ /^#define/)
	{
		print "\tcase " $2 ":"
		print "\t\tcout << escape(" $2 ") << endl;"
		print "\t\tbreak;"
	}
	else
	{
		print;
	}
}

END {
}
