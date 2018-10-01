# make the target the name of the source file without the .c extension
TARGET = $(SOURCE:.c=)

# the target depends on the source file
$(TARGET) : $(SOURCE)
	# the command to build the target
	clang -Wall -Werror $(SOURCE) -o $(TARGET)
