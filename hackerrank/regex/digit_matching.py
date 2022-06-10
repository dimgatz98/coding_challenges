# \d matches digit characters.
# [^\d] matches non-digit characters.
# Here \D also matches non-digit characters!
Regex_Pattern = r"^[\d][\d][^\d][\d][\d][^\d][\d][\d][\d][\d]$"	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())