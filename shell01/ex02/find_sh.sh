find . -iname "*.sh" -printf "%f\n" | sed 's/.sh$//'
