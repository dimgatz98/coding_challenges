# \s matches any whitespace character [ \r\n\t\f ].
# Here \S also matches non-whitespace characters. In general when you use 
# the same escape character in uppercase you say dont match this pattern!

# The expression \w will match any word character.
# Word characters include alphanumeric characters (a-z, A-Z and 0-9) and underscores (_).

Regex_Pattern = r"\S\S\s\S\S\s\S\S"	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())