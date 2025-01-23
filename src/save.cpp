#include "save.h"
#include "data.h"

#include <iostream>
#include <vector>

//draw error message when invalid...
void save() {
	std::vector<u16> trimmedCanvas;
	int rowWidth 		= 0;
	int expectedWidth 	= 0;
	bool isValid = true;

	for (auto val : canvas) {
		if (val != 0xffff) {
			rowWidth++;
			trimmedCanvas.push_back(val);
		}
		
		if (val == 0xffff && rowWidth > 0) {
			if (expectedWidth > 0 && rowWidth != expectedWidth) {
				std::cout << "ERROR: PUZZLE IS NOT A RECTANGLE" << std::endl;
				isValid = false;
				std::cout << "NOT SAVING..." << std::endl;
			}
			expectedWidth = rowWidth;
			rowWidth = 0;
		}
	}

	if (isValid) std::cout << "valid puzzle -- saving..." << std::endl;

	//std::cout << expectedWidth << std::endl;
	//std::cout << trimmedCanvas.size() << std::endl;
}
