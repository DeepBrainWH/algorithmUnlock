

file_io: file_io.c
	$(CC) $^ -o bin/$@

integer_to_roman: integer_to_roman.cc
	$(CXX) $^ -o bin/$@ -Wall

roman_to_integer: roman_to_integer.cc
	$(CXX) $^ -o bin/$@ -Wall

add_two_numbers: add_two_numbers.cc
	$(CXX) $^ -o bin/$@

remove_duplicated_numbers: remove_duplicated_numbers.cc
	$(CXX) $^ -o bin/$@

remove_element: remove_element.c
	$(CC) $^ -o bin/$@


all: file_io integer_to_roman roman_to_integer add_two_numbers \
	remove_duplicated_numbers remove_element

.PHONY:all
clean: 
	rm -rf file_io integer_to_roman roman_to_integer