# abc.def.ghi.klm
# "\" escapes .
# . in general means any(non-empty) single character except for "\n"
# ^ means starting of the string, $ means ending of the string
regex_pattern = r"^...\....\....\....$"	# Do not delete 'r'.

# regex_pattern = r"^.{3}\..{3}\..{3}\..{3}$"	# Do not delete 'r'.
# The above could also be the case where in {x}, x defines the number of occurences
# of the preceding character. Whatever is enclosed in '[]' defines the character or set of
# characters to be matched. If "^" comes at the starting of the '[]', in this case
# it means "No", meaning that it will match only characters not contained in the set.


import re
import sys

test_string = input()

match = re.match(regex_pattern, test_string) is not None

print(str(match).lower())